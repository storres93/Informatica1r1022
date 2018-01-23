/**
  \file server.c
  \brief Archivo de principal del servidor
  \details Hace la carga de la lista de usuarios y luego espera conexiones, cada vez que llega una y el login es correcto se crea un thread para esa nueva conexion y se esperan nuevas conexiones
  \author Sebastian Torres
  \date 27/11/2012
*/
#include "sock-lib.h"

int main (void)
{
  //!< Funcion Principal
	int sockfd;
	void (*funcPtr)(void*);
	ThreadPass threadPass;
	int CID;
	int loginCorrect=1;
	Clients *clients=NULL;
	struct sockaddr_in my_addr;	/* contendr� la direcci�n IP y el n�mero de
					puerto local */
	pthread_t thread;				
	pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
	funcPtr=startChild;
	
	int sockdup; 
	
	if(createUserList(&clients) == -1)
	{
	  perror ("Fallo la creacion de la lista de usuarios");
	  exit(1);
	}
	printf("Iniciando servidor\n");
	if ((sockfd = Open_conectionServ (&my_addr)) == -1)
	{
		perror ("Fall� la creaci�n de la conexi�n"); 
		exit (1);
	}
	printf("Servidor iniciado en el puerto %u\n",my_addr.sin_port);
	while(1)
	{
	  sockdup = Aceptar_pedidos (sockfd,my_addr);
	  CID=login(sockdup,clients);
	  if(CID)
	  {
	    loginCorrect=1;
	    threadPass.socket=sockdup;
	    threadPass.CID=CID;
	    threadPass.Client=&clients;
	    threadPass.mutex=&count_mutex;
	    if(write (sockdup, &loginCorrect , sizeof (int)) == -1)
	    {
	      printf("Fatal error destroy destroy!!\n");
	      exit(1);
	    }
	    if(pthread_create(&thread,NULL,(void *)funcPtr,(void*)&threadPass))//pthread_create(thread,NULL,startChild,&Clients)
	    {
	      printf("Error creando el thread para el cliente %d\n",CID);
	    }
	  }else{
	    loginCorrect=0;
	    if (write (sockdup, &loginCorrect , sizeof (int)) == -1)
	      {
		perror("Error escribiendo mensaje en socket");
	      }
	  }
	  
	}
	return 0;
}

