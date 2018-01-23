/**
  \file header.h
  \brief Archivo de prototipos de la libreria de conexion
  \details Contiene todos los prototipos y estructuras ademas de incluir la libreria de manejo de usuarios
  \author Sebastian Torres
  \date 27/11/2012
*/
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "usuarios.h"

#define PORT 3490	/* El puerto donde se conectar�, servidor */
#define BACKLOG 20	/* Tama�o de la cola de conexiones recibidas */

int Open_conectionServ (struct sockaddr_in *); /* Funci�n que crea la conexi�n*/

int Aceptar_pedidos (int,struct sockaddr_in);	/* Funci�n que acepta una conexi�n entrante*/

void startChild(void*);

void startChildClient(void* threadPass_t);

int conectar (char*, char*);

int connectFinal (unsigned short int,char*);

void sendNormalMessage(Clients*,int,int);

void sendUserInfo(Clients*,int,int);

void sendConnectedFriends (Clients*,int,int);

void sendConnectMessage(int,int);

void sendDisconnectMessage(int,int);

void sendConnectMessageAll(Clients*,int,int);

void sendDisconnectMessageAll(Clients*,int,int);
