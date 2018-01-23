#include "header.h"
 /**
 	\file main.c
 	\brief Cliente
 	\details Interfaz grafica
 	\date 2012.11.27
*/
 
int main (void)
{
  
  IplImage*Window;
  MisDatos A;
  A.Friends=NULL;
  cvInitFont(&Font,CV_FONT_HERSHEY_SIMPLEX, 0.4, 0.5, 0, 1,8);
  cvNamedWindow ("UCHAT",   CV_WINDOW_AUTOSIZE);
  
  pthread_t thread;
  void (*funcPtr) (void*);
  threadParam Param;
  
  funcPtr= threadFunc;
  int fd;
  
    printf("Login\n");
  if (fd=login ("UCHAT",&A))
  {
    Param.fd=fd;
    Param.datos=&A;
    pthread_create(&thread,NULL,(void *)funcPtr,(void*)&Param);
    printf("Principal\n");
    principal (fd, "UCHAT",&A); ///De aca empieza el chat
    desconectar (fd,A.datos.ID);
     
  }
   
  return 0;
}

/**	
	\fn  int principal (char *Window,MisDatos *Datos)
	\brief Selector de Amigos
 	\param [in] fd
 	\param [in] Window Ventana en la que se va a mostrar
	\param [out] Datos Header de todos los datos
	\return Void
	\author Andres Demski
	\date 27/11/2012 
*/
int principal (int fd, char *Window,MisDatos *Datos) //Lista de usuarios
{
  IplImage*Principal;
  int i=0,j=0;
  int x,xx,y,yy;
  CvSize text_size;
  int baseline;
  char a;
  
  Ls_Friends *p;
  Ls_Friends* Amigos [2][AMIGOTES];
  Ls_Friends *Aux=NULL;
  IplImage *Img = cvLoadImage ("User1.jpg",CV_LOAD_IMAGE_COLOR); ///Aca estaria cargar la imagen
  Aux=Datos->Friends;
  
  for (i=0; i<AMIGOTES;i++)
  {
    Amigos[0][i]=NULL;
    Amigos[1][i]=NULL;
  }
  
  i=0;
  while (Aux)  //Cargo un vector con direcciones de los Friends
  {
    if (i<AMIGOTES) Amigos[0][i]=Aux;
    else Amigos [1][i-AMIGOTES]=Aux;
    i++;
    Aux=Aux->next;
  }
   
  Principal= cvCreateImage (cvSize(IMG_X,IMG_Y),IPL_DEPTH_8U ,3);
  for (i=0; i<Principal->height;i++)
  {
    for (j=0; j<Principal->widthStep;j++)
    {
      if (i==IMG_Y-ALTO_NEW_TEXT+3 || i==FIRST_LINE) (Principal->imageData)[i*Principal->widthStep+j] = (char)0xFF;
      else  (Principal->imageData)[i*Principal->widthStep+j] = (char)0;
     }
  }
  i=0;
  
  while ( i<AMIGOTES)  //llema primer columna de amigos
  {
    if (Amigos[0][i]) 
    { 
      cvPutText (Principal,Amigos[0][i]->datos.Nick,cvPoint(30,FIRST_LINE+25+(LINE_SPACE+3)*i), &Font, cvScalar (255,255,255,0));
      if (Amigos[0][i]->datos.Estado==1) cvCircle(Principal, cvPoint (21,FIRST_LINE+25+(LINE_SPACE+3)*i -3), 3, cvScalar (0,255,0,0), 1, 8, 0 );
      if (Amigos[0][i]->datos.Estado==0) cvCircle(Principal, cvPoint (21,FIRST_LINE+25+(LINE_SPACE+3)*i -3), 3, cvScalar (0,0,255,0), 1, 8, 0 );
      cvShowImage (Window,Principal);
     }
    i++;
    
  }
  
  while (i<AMIGOTES*2 && i<(Datos->datos).FriQuant)  //La segunda
  {
    if (Amigos[1][i-AMIGOTES]) 
    {
      cvPutText (Principal,Amigos[1][i-AMIGOTES]->datos.Nick,cvPoint(250,FIRST_LINE+25+(LINE_SPACE+3)*(i-AMIGOTES) ), &Font, cvScalar (255,255,255,0));
      if (Amigos[1][i-AMIGOTES]->datos.Estado) cvCircle(Principal, cvPoint (241,FIRST_LINE+25+(LINE_SPACE+3)*(i-AMIGOTES) -3), 3, cvScalar (0,255,0,0), 1, 8, 0 );
      else cvCircle(Principal, cvPoint (241,FIRST_LINE+25+(LINE_SPACE+3)*(i-AMIGOTES) -3), 3, cvScalar (0,0,255,0), 1, 8, 0 );
      cvShowImage (Window,Principal);
    }
    i++;
  }
  
  //El top
  cvPutText (Principal,Datos->datos.Nick,cvPoint(70,LINE_SPACE+15), &Font, cvScalar (255,255,255,0));
  //cvPutText (Principal,Datos->datos.Email,cvPoint(70,2*LINE_SPACE+15), &Font, cvScalar (255,255,255,0));
  poner_imagen (Principal,Img);
  cvReleaseImage (&Img);
  //El cuadradito de seleccion
  i=0;
  x=13;
  yy=(FIRST_LINE+25+(LINE_SPACE+3)*i )+5;
  cvShowImage (Window,Principal);
  if (Amigos[0][0])
  {
    cvGetTextSize(Amigos[0][i]->datos.Nick, &Font, &text_size,&baseline); //Para que varie con el tamanio
    xx= x+ text_size.width +23;
    y= FIRST_LINE+25+(LINE_SPACE+3)*i;
    y= yy-18;
    cvRectangle (Principal,cvPoint ( x,y ),
		cvPoint (xx,yy ),
		cvScalar (255,255,255,0),1,8,0);
    cvShowImage (Window,Principal);
    i=0;
    j=0;
    
    //Escaniamos el teclado
    a= cvWaitKey (100);
    while (a!=27 )
    {
      switch (a)
      {
	case ('R'): //Arriba
	  if (i>0)
	  {
	    i--; //Sube si se puede el cuadradito, mod cordenadas
	    cvRectangle (Principal,cvPoint ( x,y ),
		  cvPoint (xx,yy ),
		  cvScalar (0,0,0,0),1,8,0);
	    if (!j) x=13;
	    if (j) x=233;
	    cvGetTextSize((Amigos[j][i]->datos.Nick), &Font, &text_size,&baseline);
	    yy=(FIRST_LINE+25+(LINE_SPACE+3)*i )+5;
	    xx= x+ text_size.width +23;
	    y= FIRST_LINE+25+(LINE_SPACE+3)*i;
	    y= yy-18;
	    cvRectangle (Principal,cvPoint ( x,y ),
		  cvPoint (xx,yy ),
		  cvScalar (255,255,255,0),1,8,0);
	    cvShowImage (Window,Principal);
	  }
	  break;
	case ('Q'): //Izquierda
	  if (j){
	    j--; //Igual logica que el anterior
	    cvRectangle (Principal,cvPoint ( x,y ),
	    cvPoint (xx,yy ),
	    cvScalar (0,0,0,0),1,8,0);
	    if (!j) x=13;
	    if (j) x=233;
	    cvGetTextSize((Amigos[j][i]->datos.Nick), &Font, &text_size,&baseline);
	    yy=(FIRST_LINE+25+(LINE_SPACE+3)*i )+5;
	    xx= x+ text_size.width +23;
	    y= FIRST_LINE+25+(LINE_SPACE+3)*i;
	    y= yy-18;
	    cvRectangle (Principal,cvPoint ( x,y ),
		    cvPoint (xx,yy ),
		    cvScalar (255,255,255,0),1,8,0);
	    cvShowImage (Window,Principal);
	  }
	  break;
	case ('S'): //Derecha
	  if (!j && i+AMIGOTES<Datos->datos.FriQuant) {
	    j++;
	    cvRectangle (Principal,cvPoint ( x,y ),
	    cvPoint (xx,yy ),
	    cvScalar (0,0,0,0),1,8,0);
	    if (!j) x=13;
	    if (j) x=233;
	    cvGetTextSize((Amigos[j][i]->datos.Nick), &Font, &text_size,&baseline);
	    yy=(FIRST_LINE+25+(LINE_SPACE+3)*i )+5;
	    xx= x+ text_size.width +23;
	    y= FIRST_LINE+25+(LINE_SPACE+3)*i;
	    y= yy-18;
	    cvRectangle (Principal,cvPoint ( x,y ),
		    cvPoint (xx,yy ),
		    cvScalar (255,255,255,0),1,8,0);
	    cvShowImage (Window,Principal);
	  }
	  break;
	case ('T'): //Abajo
	  if (i<AMIGOTES-1 && i+j*AMIGOTES<Datos->datos.FriQuant-1)
	  {
	    i++;
	    cvRectangle (Principal,cvPoint ( x,y ),
		  cvPoint (xx,yy ),
		  cvScalar (0,0,0,0),1,8,0);
	    if (!j) 
	      x=13;
	    if (j) 
	      x=233;
	    cvGetTextSize((Amigos[j][i]->datos.Nick), &Font, &text_size,&baseline);
	    yy=(FIRST_LINE+25+(LINE_SPACE+3)*i )+5;
	    xx= x+ text_size.width +23;
	    y= FIRST_LINE+25+(LINE_SPACE+3)*i;
	    y= yy-18;
	    cvRectangle (Principal,cvPoint ( x,y ),
			  cvPoint (xx,yy ),
			  cvScalar (255,255,255,0),1,8,0);
	    cvShowImage (Window,Principal);
	  }
	  break;
	case ('\n'):  //Empecemos a chatear
	  if ((Amigos[j][i]->datos).Estado) 
	    chat (fd, Window, Datos, Amigos[j][i]);
	  cvShowImage (Window,Principal);
	  break;
      }
      actualizarPrin (Window, Principal,Amigos);
      a= cvWaitKey (100);
    }
  }
  else   {
    a= cvWaitKey (100);
  
    while (a!=27 )
    {
      a= cvWaitKey (100);
    }
  }
  cvReleaseImage (&Principal);
  return 0;

}

/**	
	\fn  void actualizarPrin (char *Window,IplImage *img, Ls_Friends* Amigos[][23])
	\brief Actualiza los estados de contactos
 	\param [in] Window Ventana
 	\param [in] Img Imagen a mostrar
	\param [in] Amigos Vector con las direcciones de la lista
	\return Void
	\author Andres Demski
	\date 27/11/2012 
*/
void actualizarPrin (char*Window, IplImage *img, Ls_Friends* Amigos[][23])
{
  int i=0;
  
  while ( i<AMIGOTES)  //llema primer columna de amigos
  {
    if (Amigos[0][i]) { 
    if (Amigos[0][i]->datos.Estado==1) cvCircle(img, cvPoint (21,FIRST_LINE+25+(LINE_SPACE+3)*i -3), 3, cvScalar (0,255,0,0), 1, 8, 0 );
    if (Amigos[0][i]->datos.Estado==0) cvCircle(img, cvPoint (21,FIRST_LINE+25+(LINE_SPACE+3)*i -3), 3, cvScalar (0,0,255,0), 1, 8, 0 );
    }
    i++;
  }
    
  while (i<AMIGOTES*2 && i<2*AMIGOTES)  //La segunda
  {
    if (Amigos[1][i-AMIGOTES]) {
    if (Amigos[1][i-AMIGOTES]->datos.Estado) cvCircle(img, cvPoint (241,FIRST_LINE+25+(LINE_SPACE+3)*(i-AMIGOTES) -3), 3, cvScalar (0,255,0,0), 1, 8, 0 );
    else cvCircle(img, cvPoint (241,FIRST_LINE+25+(LINE_SPACE+3)*(i-AMIGOTES) -3), 3, cvScalar (0,0,255,0), 1, 8, 0 );
    }
    i++;
  }
  cvShowImage (Window,img);
  
}

/**	
	\fn  int login (char * Window, MisDatos *Datos)
	\brief Conecta y actualiza mis datos.
 	\param [in] Window Ventana en la que se va a mostrar
	\param [out] Datos Header de todos los datos
	\return fd si se conecto, de lo contrario 0
	\author Andres Demski
	\date 27/11/2012 
*/
int login (char * Window, MisDatos *Datos)  //devuelve fd si hace login, llena Datos
{
  IplImage*Login= cvLoadImage ("UCHAT.jpg",CV_LOAD_IMAGE_COLOR);
  int i=0,fd=0;
  int a=0;
  char User[LOGIN_CH];
  char Password [PASSWORD+1];
  char c;
  
  for (i=0;i<LOGIN_CH;i++) { User[i]=(char)0; } //inicializo
  for (i=0;i<PASSWORD+1;i++) { Password [i]= (char)0; }
  
  cvRectangle (Login,cvPoint (((IMG_X - LOGIN_REC_X)/2) ,LOGIN_REC_POS_Y), //Pone rectangulos
	       cvPoint (((IMG_X - LOGIN_REC_X)/2)+LOGIN_REC_X, LOGIN_REC_POS_Y +LOGIN_REC_Y),
	       cvScalar (255,255,255,0),1,8,0);
  cvRectangle (Login,cvPoint (((IMG_X - LOGIN_REC_X)/2) ,LOGIN_REC_POS_Y + 60),
	       cvPoint (((IMG_X - LOGIN_REC_X)/2)+LOGIN_REC_X, LOGIN_REC_POS_Y +LOGIN_REC_Y +60),
	       cvScalar (255,255,255,0),1,8,0);
  cvPutText (Login,"User",cvPoint(((IMG_X - LOGIN_REC_X)/2)+80, LOGIN_REC_POS_Y -10), &Font, cvScalar (255,255,255,0));
  cvPutText (Login,"Password",cvPoint(((IMG_X - LOGIN_REC_X)/2)+65, LOGIN_REC_POS_Y +60 -10), &Font, cvScalar (255,255,255,0));
  cvShowImage (Window,Login);
  
  a=completar_campos (Window,Login,User,Password); //si llenar campos devuelve algo !=0
  while (a)
  {
    if (a==1)  //si es uno, intenta conectar
    {
      cvPutText (Login,"< Conectando >",cvPoint(((IMG_X - LOGIN_REC_X)/2)+35, LOGIN_REC_POS_Y +LOGIN_REC_Y +60+30), &Font, cvScalar (255,255,255,0));
      cvShowImage (Window,Login);   
      
      if (fd = conectarConServer (User,Password) )  
      {
	cvPutText (Login,"< Conectando >",cvPoint(((IMG_X - LOGIN_REC_X)/2)+35, LOGIN_REC_POS_Y +LOGIN_REC_Y +60+30), &Font, cvScalar (0,0,0,0));
	cvPutText (Login,"< Actualizando >",cvPoint(((IMG_X - LOGIN_REC_X)/2)+32, LOGIN_REC_POS_Y +LOGIN_REC_Y +60+30), &Font, cvScalar (255,255,255,0));
	cvShowImage (Window,Login);
	if (  llenardatos (fd,Datos) ) return fd;
	cvPutText (Login,"< Actualizando >",cvPoint(((IMG_X - LOGIN_REC_X)/2)+32, LOGIN_REC_POS_Y +LOGIN_REC_Y +60+30), &Font, cvScalar (0,0,0,0));
      }
      
      cvPutText (Login,"< Conectando >",cvPoint(((IMG_X - LOGIN_REC_X)/2)+35, LOGIN_REC_POS_Y +LOGIN_REC_Y +60+30), &Font, cvScalar (0,0,0,0));
      cvPutText (Login,"< ERROR >",cvPoint(((IMG_X - LOGIN_REC_X)/2)+55, LOGIN_REC_POS_Y +LOGIN_REC_Y +60+30), &Font, cvScalar (255,255,255,0));
      cvShowImage (Window,Login);
      cvWaitKey (0);
      cvPutText (Login,"< ERROR >",cvPoint(((IMG_X - LOGIN_REC_X)/2)+55, LOGIN_REC_POS_Y +LOGIN_REC_Y +60+30), &Font, cvScalar (0,0,0,0));
      
    }
    if (a==2) //si es 2, campos incompletos, volver a completar
    {
      cvPutText (Login,"< Campos Incompletos >",cvPoint(((IMG_X - LOGIN_REC_X)/2)+8, LOGIN_REC_POS_Y +LOGIN_REC_Y +60+30), &Font, cvScalar (255,255,255,0));
      cvShowImage (Window,Login);
      cvWaitKey (0);
      cvPutText (Login,"< Campos Incompletos >",cvPoint(((IMG_X - LOGIN_REC_X)/2)+8, LOGIN_REC_POS_Y +LOGIN_REC_Y +60+30), &Font, cvScalar (0,0,0,0));
      cvShowImage (Window,Login);
    }
    a= completar_campos (Window,Login,User,Password);
  }
  cvShowImage (Window,Login);
  cvReleaseImage (&Login);
  return 0;
}

/**	
	\fn  int completar_campos (char* Window, IplImage *Login, char* User, char* Password)
	\brief Completa los detos del Login
 	\param [in] Window Ventana en la que se va a mostrar
	\param [in] Login Imagen de la ventana
	\param [in] User String del User
	\param [in] Password String del Password	
	\return 1 si completo, 0 si toco esc y 2 si dejo algun campo incompleto
	\author Andres Demski
	\date 27/11/2012 
*/   
int completar_campos (char* Window, IplImage *Login, char* User, char* Password) // devuelve 1 si completo, 0 si toco esc y 2 si dejo algun campo incompleto
{
  int i=0;
  cvPutText (Login,User ,cvPoint(((IMG_X - LOGIN_REC_X)/2)+ 10 ,LOGIN_REC_POS_Y + LOGIN_REC_Y - 8), &Font, cvScalar (0,0,0,0));
  cvPutText (Login,"*************************" ,cvPoint(((IMG_X - LOGIN_REC_X)/2)+ 10 ,LOGIN_REC_POS_Y + LOGIN_REC_Y - 8 +60), &Font, cvScalar (0,0,0,0));
    for (i=0;i<LOGIN_CH;i++) { User[i]=(char)0; } //inicializo
    for (i=0;i<PASSWORD+1;i++) { Password [i]= (char)0; }
  cvCircle(Login, cvPoint (((IMG_X - LOGIN_REC_X)/2)+80-10, LOGIN_REC_POS_Y -13), 3, cvScalar (0,255,0,0), 1, 8, 0 );
  cvShowImage (Window,Login);
  CvSize text_size;
  char FakePassword [PASSWORD+1];
  int baseline;
  char aux= cvWaitKey (10); //Completar campos
  i=0;
  while (aux != 27 && aux != '\n')  //llenar campo User, usa la misma logica que writemsj
  {
    if (aux != '/') {
    if (aux>31)
      {
	cvGetTextSize(User, &Font, &text_size,&baseline); //Tamaño que va a ocupar el texto
	if ((LOGIN_REC_X-20) >  text_size.width)
	{
	  User[i]=aux;
	  cvPutText (Login,User ,cvPoint(((IMG_X - LOGIN_REC_X)/2)+ 10 ,LOGIN_REC_POS_Y + LOGIN_REC_Y - 8), &Font, cvScalar (255,255,255,0));
	  cvShowImage (Window,Login);
	  i++;
	}
      }
      
    if (aux==8 && i)
    {
      cvPutText (Login,User ,cvPoint(((IMG_X - LOGIN_REC_X)/2)+ 10 ,LOGIN_REC_POS_Y + LOGIN_REC_Y - 8), &Font, cvScalar (0,0,0,0));
      User[i]=(char)0;
      i--;
      User[i]=(char)0;
      cvPutText (Login,User ,cvPoint(((IMG_X - LOGIN_REC_X)/2)+ 10 ,LOGIN_REC_POS_Y + LOGIN_REC_Y - 8), &Font, cvScalar (255,255,255,0));
      cvShowImage (Window,Login);  
     }
    }
    aux= cvWaitKey (10);
  }
  
  if (aux == 27) return 0; //Toco esc
  i=0;
  cvCircle(Login, cvPoint (((IMG_X - LOGIN_REC_X)/2)+80-10, LOGIN_REC_POS_Y -13), 3, cvScalar (0,0,0,0), 1, 8, 0 );
  cvCircle(Login, cvPoint (((IMG_X - LOGIN_REC_X)/2)+65-10, LOGIN_REC_POS_Y +60 -13), 3, cvScalar (0,255,0,0), 1, 8, 0 );
  cvShowImage (Window,Login);
  aux= cvWaitKey (10);
  while (aux != 27 && aux != '\n')  //llenar campo Password y FakePassword, usa la misma logica que writemsj
  {
   if (aux!='/') { 
    if (aux>31)
    {
      if (i < PASSWORD)
      {
	Password[i]=aux;
	FakePassword[i]='*';
	FakePassword[i+1]=(char)0;
	cvPutText (Login,FakePassword,cvPoint(((IMG_X - LOGIN_REC_X)/2)+ 10 ,LOGIN_REC_POS_Y + LOGIN_REC_Y - 8 +60), &Font, cvScalar (255,255,255,0));
	cvShowImage (Window,Login);
	i++;
      }
    }
    
    if (aux==8 && i)
    {
      cvPutText (Login,FakePassword ,cvPoint(((IMG_X - LOGIN_REC_X)/2)+ 10 ,LOGIN_REC_POS_Y + LOGIN_REC_Y - 8 +60), &Font, cvScalar (0,0,0,0));
      User[i]=(char)0;
      FakePassword[i]=(char)0;
      i--;
      Password[i]=(char)0;
      FakePassword[i]=(char)0;
      cvPutText (Login,FakePassword ,cvPoint(((IMG_X - LOGIN_REC_X)/2)+ 10 ,LOGIN_REC_POS_Y + LOGIN_REC_Y - 8+60), &Font, cvScalar (255,255,255,0));
      cvShowImage (Window,Login);  
    }
   }
    aux= cvWaitKey (10);
  }
  cvCircle(Login, cvPoint (((IMG_X - LOGIN_REC_X)/2)+65-10, LOGIN_REC_POS_Y +60 -13), 3, cvScalar (0,0,0,0), 1, 8, 0 );
  cvShowImage (Window,Login);
  if (aux == 27) return 0; //si toco esc,envia codigo dos
  if (User[0] && Password [0]) return 1; //campos completos
  
  return 2;
}

/**	
	\fn  void addifnotblack (IplImage* Img ,IplImage* txt)
	\brief Funcion para agragar un fondo
 	\param [in] Img Imagen a la que se le suma la otra
 	\param [in] txt Imagen con fondo negro
	\return Void
	\author Andres Demski
	\date 27/11/2012 
*/
void addifnotblack (IplImage* Img ,IplImage* txt) //Monta lo que no es negro de una imagen, en la otra (se puede usar para poner fondo)
{
  int i,j;
  for (i=0; i<(Img->height);i++)
  {
    for (j=0;j<(Img->widthStep);j=j+3)
    {
       
      if ((((unsigned char*)(txt->imageData))[i*(Img->widthStep)+j] != (unsigned char)0) 
	 || (((unsigned char*)(txt->imageData))[i*(Img->widthStep)+j+1] != (unsigned char)0) 
	 || (((unsigned char*)(txt->imageData))[i*(Img->widthStep)+j+2] != (unsigned char)0)) //si no es negro, lo copia
      {
	((unsigned char*)(Img->imageData))[i*(Img->widthStep)+j]=((unsigned char*)(txt->imageData))[i*(Img->widthStep)+j];
	((unsigned char*)(Img->imageData))[i*(Img->widthStep)+j+1]=((unsigned char*)(txt->imageData))[i*(Img->widthStep)+j+1];
	((unsigned char*)(Img->imageData))[i*(Img->widthStep)+j+2]=((unsigned char*)(txt->imageData))[i*(Img->widthStep)+j+2];
      }
     }
  }
}

/**	
	\fn void chat (int fd,char *Window, MisDatos *Mios, Ls_Friends *Amigo)  
	\brief Ventana de chat
 	\param [in] fd fd 
 	\param [in] Window Ventana 
 	\param [in] Mios Header a los datos
 	\param [in] Amigo Amigo con el cual se desea chatear
	\return Void
	\author Andres Demski
	\date 27/11/2012 
*/
void chat (int fd,char *Window, MisDatos *Mios, Ls_Friends *Amigo)
{
  IplImage *Chat=cvCreateImage (cvSize(IMG_X,IMG_Y),IPL_DEPTH_8U ,3);;
  clearbar (Chat);
  actualizarmsj(Chat,Amigo); //llena la lista de msjs con todos los resividos
  topchat (Chat,Amigo); //Pone el top
  cvShowImage (Window,Chat);
  writemsj (fd,Window, Chat, Amigo); //Escribir msj
  cvReleaseImage (&Chat);
}

/**	
	\fn void topchat (IplImage *Chat,Ls_Friends *Amigo)
	\brief Genera el encabezado del Chat
 	\param [in] Chat Imagen del Chat
 	\param [in] Amigo Amigo con el cual se desea chatear
	\return Void
	\author Andres Demski
	\date 27/11/2012 
*/
void topchat (IplImage *Chat,Ls_Friends *Amigo) //Hace el top de la pantalla de chat
{
  int i,j;
  for (i=0;i<75;i++)
  {
    for (j=0;j<Chat->widthStep;j++)
    {
      if (i==70)
      (Chat->imageData)[i*Chat->widthStep+j]=(char)0xFF; //la liña
      else
      (Chat->imageData)[i*Chat->widthStep+j]=(char)0; //borra todo
    }
  }
  cvPutText (Chat,Amigo->datos.Nick,cvPoint(70,LINE_SPACE+15), &Font, cvScalar (255,255,255,0));
  if (Amigo->datos.Estado) cvPutText (Chat,"CONECTADO",cvPoint(70,2*LINE_SPACE+15), &Font, cvScalar (255,255,255,0));
  else cvPutText (Chat,"DESCONECTADO",cvPoint(70,2*LINE_SPACE+15), &Font, cvScalar (255,255,255,0));
  IplImage *Img = cvLoadImage ("User3.jpg",CV_LOAD_IMAGE_COLOR);
  poner_imagen (Chat,Img);
  cvReleaseImage (&Img);
}

/**	
	\fn void actualizartopchat (IplImage *Img,Ls_Friends *Amigo)
	\brief Genera el encabezado del Chat
 	\param [in] Img Imagen del Chat
 	\param [in] Amigo Amigo con el cual se desea chatear
	\return Void
	\author Andres Demski
	\date 27/11/2012 
*/
void actualizartopchat (IplImage*Img,Ls_Friends*Amigo)
{
  cvPutText (Img,"CONECTADO",cvPoint(70,2*LINE_SPACE+15), &Font, cvScalar (0,0,0,0));
  cvPutText (Img,"DESCONECTADO",cvPoint(70,2*LINE_SPACE+15), &Font, cvScalar (0,0,0,0));
  if (Amigo->datos.Estado) cvPutText (Img,"CONECTADO",cvPoint(70,2*LINE_SPACE+15), &Font, cvScalar (255,255,255,0));
  else cvPutText (Img,"DESCONECTADO",cvPoint(70,2*LINE_SPACE+15), &Font, cvScalar (255,255,255,0));
  
}

/**	
	\fn void newmsj (IplImage * Img,char *new,char quien)
	\brief Agrega msj en el Chat
 	\param [in] Img Imagen del Chat
 	\param [in] new Mensaje Nuevo
 	\param [in] Quien Color de la biñeta 
	\return Void
	\author Andres Demski
	\date 27/11/2012 
*/
void newmsj (IplImage * Img,char *new,char quien) // Agrega msj en la Img pantalla (preparada para mostrar), quien lo envia?
{
  int i=0,j=0;
  moveup (Img);//mueve todo para arriva
  if (quien==YO)
  {
    cvCircle(Img, cvPoint (10,Img->height - ALTO_NEW_TEXT -13), 3, cvScalar (0,0,255,0), 1, 8, 0 );
    
  }
  if (quien==OTRO)
  {
    cvCircle(Img, cvPoint (10,Img->height - ALTO_NEW_TEXT -13), 3, cvScalar (0,255,0,0), 1, 8, 0 );
  }
  cvPutText (Img,new,cvPoint(20,Img->height - ALTO_NEW_TEXT -10), &Font, cvScalar COLOR_MSJ); //Ingresa el msj
}

/**	
	\fn void writemsj (int fd, char*Window, IplImage *Img,Ls_Friends*Amigo)
	\brief Escanea el teclado y muestra lo que estas escribiendo.
 	\param [in] fd fd
 	\param [in] Window Ventana
 	\param [in] Img Imagen del chat
 	\param [in] Amigo Amigo con el cual se desea chatear
	\return Void
	\author Andres Demski
	\date 27/11/2012 
*/
void writemsj (int fd, char*Window, IplImage *Img,Ls_Friends*Amigo)  //escanea teclado y al precionar enter lo pone en la "consola" ("window") 
{
  int i=0, j=0;
  char new=(char)0;
  char newtxt[2][CH_LINE];
  CvSize text_size;
  int baseline;  //me lo pide la funcion gettextsie ... no lo uso
  for (i=0;i<CH_LINE;i++) //inicializa vector
  {
   newtxt[0] [i]=(char)0;
   newtxt[1] [i]=(char)0;
  }
  
  while (new != 27) // no esc
  {
    i=0;
    j=0;
    new= (cvWaitKey (100));
  while ((new != '\n') && (new != 27)) // ni enter ni esc
  {
    if (new!='/') 
    {
      cvPutText (Img,&newtxt[0][0],cvPoint(20,Img->height-LINE_SPACE -18), &Font, cvScalar (0,0,0,0)); //borra el txt (color negro, tapa lo que habia)
      cvPutText (Img,&newtxt[1][0],cvPoint(20,Img->height -18), &Font, cvScalar (0,0,0,0)); //borra el txt (color negro, tapa lo que habia)
      if (new>31) //es caracter?
      {
	cvGetTextSize(&newtxt[0][0], &Font, &text_size,&baseline); //Tamaño que va a ocupar el texto
	if ((Img->width-40) >  text_size.width)  //entra en la primer linea?
	{
	  newtxt[0][i]=new; //lo pone en el vector
	  i++; 
	  newtxt[0][i]=(char)0;
	}
	
	else //no?? entonces empezamos con la 2º linea
	{
	  cvGetTextSize(&newtxt[1][0], &Font, &text_size,&baseline);  //Cuanto ocupa?
	  if ((Img->width-40) >  text_size.width) //entra¿?
	  {
	    newtxt[1][j]=new; //lo pone en el vector
	    j++; 
	    newtxt[1][j]=(char)0;
	  }
	}
      }
	  
      if (new== 8)  //borrar
      {
	if (j) //hay algo en la 2º linea para borrar?
	{
	  j--;
	  newtxt[1][j]=(char)0;
	}
	else //no?? entonces borra de la primera
	{
	  if (i)
	  {
	    i--;
	    newtxt[0][i]=(char)0;
	  }
	}
      }
      cvPutText (Img,&newtxt[0][0],cvPoint(20,Img->height-LINE_SPACE-18), &Font, cvScalar COLOR_TXT);  //Pone en la imagen el txt
      cvPutText (Img,&newtxt[1][0],cvPoint(20,Img->height -18), &Font, cvScalar COLOR_TXT);  //Pone en la imagen el txt
      
      cvShowImage (Window,Img);  //muestra
    }
    actualizarmsj (Img,Amigo);
    actualizartopchat (Img,Amigo);
    cvShowImage (Window,Img);
    new=cvWaitKey (100);
  }
  
  if (newtxt[0][0] !=0 && new!=27) //Esta vacio?
  {
    clearbar (Img);
    if (Amigo->datos.Estado)
    {
      sendNormalMsj (fd, (Amigo->datos.ID),&(newtxt[0][0]),&(newtxt[1][0]));
      newmsj (Img,&newtxt[0][0],YO);
      if (j) newmsj (Img,&newtxt[1][0],NADIE);
    }
    cvShowImage (Window,Img);
  }
  
  for (i=0;i<CH_LINE;i++) //pone en 0 todo el vector
  {
    newtxt[0] [i]=(char)0;
    newtxt[1] [i]=(char)0;
  }
  
  } 
  
}

/**	
	\fn void moveup (IplImage *Img)
	\brief Mueve todo el texto una linea para arriva
 	\param [in] Img Imagen del chat
 	\return Void
	\author Andres Demski
	\date 27/11/2012 
*/
void moveup (IplImage *Img) //mueve para arriba Todo, una linea 
{
  unsigned int i=0,j=0;
  for (i=76; (i+LINE_SPACE)<(Img->height-ALTO_NEW_TEXT);i++)
  {
    for (j=0;j<(Img->widthStep);j++)
    {
      ((unsigned char*)(Img->imageData))[i*(Img->widthStep)+j] = ((unsigned char*)(Img->imageData))[(i+LINE_SPACE) *(Img->widthStep)+j];//copia lo que esta LINe_SPACE mas abajo
    }
  }
  for (;i<(Img->height-ALTO_NEW_TEXT);i++)
  {
    for (j=0;j<(Img->widthStep);j++)
    {
      ((unsigned char*)(Img->imageData))[i*(Img->widthStep)+j] = (char)0; // lo ultimo de abajo lo pone en negro
      }
  }
}

/**	
	\fn void clearbar (IplImage *Img)
	\brief Borra todo el sector de escritura
 	\param [in] Img Imagen del chat
 	\return Void
	\author Andres Demski
	\date 27/11/2012 
*/
void clearbar (IplImage *Img) //Hace la liña y pone todo lo qe se estaba escribiendo en negro
{
  int i,j;
  for (i=0;i<ALTO_NEW_TEXT;i++)
  {
    for (j=0;j<Img->widthStep;j++)
    {
      if (i==3)
      (Img->imageData)[((Img->height-ALTO_NEW_TEXT)*Img->widthStep)+i*Img->widthStep+j]=(char)0xFF; //la liña
      else
      (Img->imageData)[((Img->height-ALTO_NEW_TEXT)*Img->widthStep)+i*Img->widthStep+j]=(char)0; //borra todo
    }
  }
}

/**	
	\fn void poner_imagen (IplImage *Window,IplImage *Img)
	\brief Pone una Img (Nuevo tamaño: 60x60) en la esquina superior de Window
 	\param [in] Window Imagen
 	\param [in] Img Imagen a ser achicada
	\return Void
	\author Andres Demski
	\date 27/11/2012 
*/
void poner_imagen (IplImage *Window,IplImage *Img) //Pone una imagen de 50x50 arriva a la izq
{
  int i,j;
  IplImage *Chiquita;
  Chiquita= cvCreateImage(cvSize (50,50), IPL_DEPTH_8U, 3);
  cvResize(Img, Chiquita, CV_INTER_AREA);
  for (i=10; i<60;i++)
  {
    for (j=30;j<180;j++)
    {
      ((unsigned char*)(Window->imageData))[i*(Window->widthStep)+j] = ((unsigned char*)(Chiquita->imageData))[((i-10) *152) +j-30];
    }
  }
}