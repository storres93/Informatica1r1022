#include "header.h"

/**
 	\file libclient.c
 	\brief Libreria de conexion: Cliente
 	\details Conexion
 	\date 2012.11.27
*/


/**
  \fn void threadFunc(void * Param)
  \brief Funcion principal activada en la creacion del thread
  \details Recibe los datos necesarios desde la estructura void * ingresada, luego se queda a la espera de recepcion de datos y actua correspondientemente al tipo de los mismos
  \author Sebastian Torres & Andres Demski
  \date 27/11/2012
  \param[in] Param Estructura del tipo threadParam que contiene los datos de la nueva conexion
  \return Void
*/
void threadFunc (void* Param)
{
  int fd = ((threadParam*) Param)->fd;
  MisDatos *A= ((threadParam*) Param)->datos;
  int CID;
  int CIDConnect;
  char tipo[8];
  Ls_Msj *buf;
  Ls_Friends *q;
  int i;
  char aux;
  printf ("Se Abrio el Thread\n");
  while (1)
  {
    q=A->Friends;
    i=0;
    read (fd,&tipo[i],sizeof(char));
    while (tipo[i]!='/')
    {
      i++;
      read (fd,&tipo[i],sizeof(char));
    }
    tipo[7]=NULLC;
    printf ("NUEVO MSJ\nTipo %s\n",tipo);
    if (!strcmp (tipo,"mensaje"))
    {
      read (fd,&CID,sizeof(int));
      printf ("CID %d\n",CID);
      read (fd,&aux,sizeof(char));
      while (q->next && (q->datos).ID != CID) q=q->next;
      if ((q->datos).ID==CID)
      {
	buf=malloc (sizeof(Ls_Msj));
	i=0;
	read (fd,&((buf->msj1)[i]),sizeof(char));
	while (((buf->msj1)[i])!='/') 
	{
	  i++;
	  read (fd,&((buf->msj1)[i]),sizeof(char));
	}
	(buf->msj1)[i]= NULLC;
	printf ("Mensaje: %s\n",buf->msj1);
	i=0;
	read (fd,&((buf->msj2)[i]),sizeof(char));
	while (((buf->msj2)[i])!='/') 
	{
	  i++;
	  read (fd,&((buf->msj2)[i]),sizeof(char));
	}
	(buf->msj2)[i]= NULLC;
	encolarMsj (buf, &(q->Msj));
      }
    }else if(!strcmp(tipo,"connect"))
    {
      read(fd,&CIDConnect,sizeof(int));
      setConnected(q,CIDConnect);
    }else if(!strcmp(tipo,"disconn"))
    {
      read(fd,&CIDConnect,sizeof(int));
      setDisconnected(q,CIDConnect);
    }
  }
}

/**
  \fn void setConnected(Ls_Friends * q,int CID)
  \brief Pone en estado 1 el friend correspondiente a CID
  \author Sebastian Torres
  \date 27/11/2012
  \param[in] CID CID del cual se quiere modificar el estado
  \param[in] q Lista de amigos
  \return Void
*/
void setConnected(Ls_Friends *q,int CID)
{
  while((q->datos).ID != CID)
  {
    q = q->next;
  }
  q->datos.Estado=1;
}

/**
  \fn void setDisconnected(Ls_Friends * q,int CID)
  \brief Pone en estado 0 el friend correspondiente a CID
  \author Sebastian Torres
  \date 27/11/2012
  \param[in] CID CID del cual se quiere modificar el estado
  \param[in] q Lista de amigos
  \return Void
*/
void setDisconnected(Ls_Friends *q,int CID)
{
  while((q->datos).ID != CID)
  {
    q = q->next;
  }
  q->datos.Estado=0;
}

/**	
	\fn void encolarMsj (Ls_Msj *q,Ls_Msj **h) 
	\brief Encola el mensaje q en h
 	\param [q] Estructura del mensaje
 	\param [h] header de la lista de msj
	\author Andres Demski
	\date 27/11/2012 
	\return Void 
*/
void encolarMsj (Ls_Msj *q,Ls_Msj**h)
{
  Ls_Msj *p;
  if (*h)
  {
    p=(*h);
    while (p->next) p=p->next;
    p->next=q;
  }
  else (*h)=q;
  q->next=NULL;
}

/**
  \fn int conectar(char * ip,char * port)
  \brief Se conecta al servidor
  \details Usa la ip y el puerto correspondientes para conectarse al servidor. En caso de exito devuelve el socket a la nueva conexion
  \author Sebastian Torres
  \date 27/11/2012
  \param[in] ip Ip del servidor
  \param[in] port Puerto del servidor
  \return socket
*/
int conectar (char *ip, char*port)
{
  

	int	sockfd;
	struct hostent *he;	/* Se utiliza para convertir el nombre del host a su
				direcci�n IP */
	struct sockaddr_in their_addr;  /* direcci�n del server donde se conectar� */

	/* Convertimos el nombre del host a su direcci�n IP */
	if ((he = gethostbyname ((const char *) ip)) == NULL)
	{
		herror("Error en gethostbyname");
		return (0);
	}
 
/* Creamos el socket */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Error en creaci�n de socket");
		return 0;
	}

/* Establecemos their_addr con la direccion del server */
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(atoi(port));
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(their_addr.sin_zero), 8);

/* Intentamos conectarnos con el servidor */
	if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("Error tratando de conectar al server");
		return 0;
	}
	return sockfd;
}

/**
  \fn int conectarConServer(char * ip,char * port)
  \brief Realiza el logueo y conexion al servidor
  \details Utiliza la funcion connect para conseguir el socket y luego manda su usuario y contraseña para checkear logueo. Si este es correcto en el socket se escribe 1 en caso contrario, 0. Devuelve el socket a la nueva conexion
  \author Sebastian Torres
  \date 27/11/2012
  \param[in] user Nombre de usuario
  \param[in] password Contraseña de usuario
  \return socket
*/
int conectarConServer (char *user,char *password)
{
  printf ("User: %s\n",user);
  printf ("Password: %s\n",password);
  int loginCorrect;
  int sockfd = conectar (IP, PORTC);
    
  if (sockfd) {
  while(*user !=NULLC)
  {
    write(sockfd,user,sizeof(char));
    user++;
  }
  printf ("Se envio Usuario\n");
  write(sockfd,"/",sizeof(char));
  
  while(*password!=NULLC)
  {
    write(sockfd,password,sizeof(char));
    password++;
  }
  
  printf ("Se envio Password\n");
  
  write(sockfd,"/",sizeof(char));
  
  read(sockfd,&loginCorrect,sizeof(int));
  
  if(loginCorrect)
  {
    return sockfd;
  }
  else  
  {
    //desconectar (sockfd);
    return 0;
  }
  }
  else return 0;
}
/**
  \fn int conectar(char * ip,char * port)
  \brief Se conecta al servidor
  \details FUNCION OBSOLETA
  \author Sebastian Torres
  \date 27/11/2012
  \param[in] ip Ip del servidor
  \param[in] port Puerto del servidor
  \return socket
*/
int connectFinal (unsigned short int port,char *ip) //No se usa mas
{

	int	sockfd;
	int conne;
	struct hostent *he;	/* Se utiliza para convertir el nombre del host a su
				direcci�n IP */
	struct sockaddr_in their_addr;  /* direcci�n del server donde se conectar� */

	/* Convertimos el nombre del host a su direcci�n IP */
	if ((he = gethostbyname ((const char *) ip)) == NULL)
	{
		herror("Error en gethostbyname");
		exit(1);
	}
 
/* Creamos el socket */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Error en creaci�n de socket");
		exit(1);
	}

/* Establecemos their_addr con la direccion del server */
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = port;
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(their_addr.sin_zero), 8);

/* Intentamos conectarnos con el servidor */
	printf("Me estoy intentando conectar al puerto %u\n",their_addr.sin_port);
	conne = connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr));
	printf("Valor de conne %d\n",conne);
	if (conne == -1)
	{
		perror("Error tratando de conectar al server");
		exit(1);
	}
	return sockfd;
}

/**
  \fn void sendNormalMessage(int sockfd,int CIDDest,char  * txt0, char * txt1)
  \brief Manda un mensaje
  \details Manda un mesaje del tipo "Mensaje" al cliente CIDDest
  \author Sebastian Torres & Andres Demski
  \date 27/11/2012
  \param[in] sockfd Socket de la conexion al servidor 
  \param[in] CIDDest CID del cliente al que se le desea enviar un mjs
  \param[in] txt0 Primer parte del mensaje
  \param[in] txt1 Segunda parte del mensaje
  \return Void
*/
void sendNormalMsj (int sockfd, int CIDDest,char*txt0,char*txt1)
{
  int i=0;
  write(sockfd,"mensaje/",sizeof(char)*8);
  write(sockfd,&CIDDest,sizeof(int));
  write(sockfd,"/",sizeof(char));
  while(txt0[i]!=NULLC)
  {
   if(write(sockfd,txt0+i,sizeof(char)) == -1)
   {
    perror("Error escribiendo en el socket CLIENTE");
    }
   i++;
  }
  write(sockfd,"/",sizeof(char));
  i=0;
  
  while(txt1[i]!=NULLC)
  {
   if(write(sockfd,txt1+i,sizeof(char)) == -1)
   {
    perror("Error escribiendo en el socket CLIENTE");
    }
   i++;
  }
  write(sockfd,"/",sizeof(char));
  
}

/**	
	\fn void actualizarmsj (IplImage *Chat, Ls_Friends*Amigo)
	\brief Muestra todos los mensajes resividos
 	\author Demski Andres
 	\param [in] Chat Imagen del Chat
 	\param [in] Amigo Amigo con el cual se desea chatear
	\return Void
*/
void actualizarmsj (IplImage *Chat, Ls_Friends*Amigo)
{
  Ls_Msj *q,*m= Amigo->Msj;
  while (m)  //Pone todos los msj que recibiste mientras no tenes abierta la ventana
  {
    newmsj (Chat,m->msj1,OTRO);
    if ((m->msj2)[0]) newmsj (Chat,m->msj2,NADIE);
    q=m;
    m=m->next;
    free (q);
  }
  Amigo->Msj=NULL;
}

/**	
	\fn  int llenardatos (int fd, MisDatos *Datos)
	\brief Recive la informacion enviada del servidor y llena las listas
 	\author Demski Andres
 	\param [in] fd Filedirector 
 	\param [out] Datos Header de todos los datos
	\return fd si se hizo con exito, de lo contrario 0
*/
int llenardatos (int sockfd, MisDatos *Datos)
{
  read(sockfd,Datos,sizeof(DatosMios));
  Datos->Friends=NULL;
  loadFriends(sockfd,&(Datos->Friends),(Datos->datos).FriQuant);
  return 1;
}


/**
  \fn void loadFriends(int socket,Ls_Friends * * h,int FriQuant)
  \brief Carga la lista de amigos
  \details Se lee por el socket cada uno de los amigos y se los agrega a la lista
  \author Sebastian Torres & Andres Demski
  \date 27/11/2012
  \param[in] FriQuant Cabtudad de amigos
  \param[in] socket Socket de la conexion con el servidor
  \param[out] h Lista de amigos
  \return Void
*/
void loadFriends(int socket,Ls_Friends **h,int FriQuant)
{
  int i=0;
  Ls_Friends *friend;
  printf ("Cargando amigos\n");
  for(i=0;i<FriQuant;i++)
  {
    friend = (Ls_Friends*)malloc(sizeof(Ls_Friends));
    read(socket,&(friend->datos),sizeof(SusDatos));
    printf ("Amigo %d: CID: %d Nick: %s\n",i,(friend->datos).ID,(friend->datos).Nick);
    friend->next=NULL;
    friend->Msj=NULL;
    (friend->datos).Estado=0;
    pushF (friend,h);
    read (socket, &friend, sizeof (Ls_Friends*));
  }
}

/**
  \fn void desconectar(int fd, int CID)
  \brief Manda un mensaje del tipo disconn y cierra el socket
  \author Sebastian Torres
  \date 27/11/2012
  \param[in] fd Socket de la conexion con el servidor
  \param[in] CID CID del usuario
  \return Void
*/
void desconectar (int fd, int CID)
{
  write(fd,"disconn/",sizeof(char)*8);
  write(fd,&CID,sizeof(int));
  close(fd);
}

/**
  \fn void pushF(Friends * a,Friends **h)
  \brief Agrega a la lista "Friends" un nuevo nodo
  \details Agrega a la ultima poscicion de la lista "Friends" un nuevo nodo
  \author Sebastian Torres
  \date 27/11/2012
  \param[in] a Nuevo nodo
  \param[out] h Lista de Friends
  \return Void
*/
void pushF (Ls_Friends *a,Ls_Friends **h)
{
  if(!*h)
  {
   *h=a;
   return;
  }
  Ls_Friends *aux=*h;
  while(aux->next)
    aux=aux->next;
  aux->next=a;
  a->next=NULL;
}
