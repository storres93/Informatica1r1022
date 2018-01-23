/**
  \file dummy.c
  \brief Archivo de prueba
  \details Simula la conexion de un cliente(OBSOLETO)
  \author Sebastian Torres
  \date 27/11/2012
*/
#include "sock-lib.h"
#include <fcntl.h>
/**
  \fn int main(int argc, char * argv[])
  \brief Funcion principal del programa de prueba
  \author Sebastian Torres
  \param[in] argc cantidad de parametros
  \param[in] argv aqui se reciben , ip puerto usuario y contraseña
  \date 27/11/2012
  \return 0
*/
int main(int argc,char* argv[])
{
  int loginCorrect;
  int sockfd;
//  unsigned short int port;
  DataClient yo;
  void (*funcPtr)(void*);
  funcPtr=startChildClient;
  char mjs[20];
  int i=0;
  int flag=1;
  int CIDDest;
  ThreadPassClient threadPass;
  pthread_t thread;

  
  if (argc < 2)
  {
    fprintf(stderr,"uso: %s hostname [port]\n",argv [0]);
    exit(1);
  }

  sockfd = conectar (argv[1], argv[2]);
  
  while(*argv[3]!=NULLC)
  {
    write(sockfd,argv[3],sizeof(char));
    argv[3]++;
  }
  
  write(sockfd,"/",sizeof(char));
  
  while(*argv[4]!=NULLC)
  {
    write(sockfd,argv[4],sizeof(char));
    argv[4]++;
  }
  
  write(sockfd,"/",sizeof(char));
  
  read(sockfd,&loginCorrect,sizeof(int));
  if(loginCorrect)
  {
   
  // read(sockfd,&port,sizeof(unsigned short int));
   //printf("Puerto nuevo : %u\n",port);
   //close(sockfd);
   //sockfd = connectFinal(port,argv[1]);
   read(sockfd,&yo,sizeof(DataClient));
   yo.friends=NULL;
   loadFriends(sockfd,&(yo.friends),yo.FriQuant);
   showUser(yo);
   threadPass.yo = yo;
   threadPass.socket=sockfd;
   if(pthread_create(&thread,NULL,(void *)funcPtr,(void*)&threadPass))//pthread_create(thread,NULL,startChild,&Clients)
    {
      printf("Error creando el thread para transmitir datos \n");
    }
   while(flag)
   {
     printf("CID Destino ??\n");
     scanf("%d",&CIDDest);
     if(CIDDest){
      printf("Mensaje ==\n");
      scanf("%s",mjs);
      write(sockfd,"mensaje/",sizeof(char)*8);
      write(sockfd,&CIDDest,sizeof(int));
      write(sockfd,"/",sizeof(char));
      while(mjs[i]!=NULLC)
      {
	if(write(sockfd,mjs+i,sizeof(char)) == -1)
	{
	  perror("Error escribiendo en el socket CLIENTE");
	}
	i++;
      }
      write(sockfd,"/",sizeof(char));
      i=0;
     }else{
       write(sockfd,"descone/",sizeof(char)*8);
       close(sockfd);
       flag=0;
     }
   }
  }
/* Devolvemos recursos al sistema */
  printf("Me desconecte\n");
  close(sockfd);
  return 0;
}