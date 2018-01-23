/**
   \file sock-lib.c
   \brief Archivo de libreria orientado a la conexion
   \details Contiene todas las funciones a utilizar que tengan relacion a la conexion y el envio de datos con el cliente
   \author Sebastian Torres
   \date 27/11/2012
 */
#include "sock-lib.h"
/**
   \fn int Open_conectionServ(struct sockaddr_in * my_addr)
   \brief Abre las conexiones al servidor
   \details Permite hasta un maximo de 30 conexiones en simultaneo, carga en my_addr todos los datos de red del server y devuelve un fd al socket
   \author Sebastian Torres
   \date 27/11/2012
   \param[out] my_addr Valores de red(Puerto, ip, etc)
   \return fd al socket
 */
int Open_conectionServ ( struct sockaddr_in * my_addr)
{
	int sockaux;    /*socket auxiliar*/
	int aux;        /*variable auxiliar*/

/*Crea un socket y verifica si hubo alg�n error*/
	if ((sockaux = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		fprintf(stderr, "Error en funci�n socket. C�digo de error %s\n", strerror(sockaux));
		return -1;
	}

/* Asignamos valores a la estructura my_addr */

	my_addr->sin_family = AF_INET;      /*familia de sockets INET para UNIX*/
	my_addr->sin_port = htons(PORT);    /*convierte el entero formato PC a
	                                       entero formato network*/
	my_addr->sin_addr.s_addr = INADDR_ANY;  /* automaticamente usa la IP local */
	bzero(&(my_addr->sin_zero), 8);     /* rellena con ceros el resto de la
	                                       estructura */

	/* Con la estructura sockaddr_in completa, se declara en el Sistema que este
	   proceso escuchar� pedidos por la IP y el port definidos*/
	if ( (aux = bind (sockaux, (struct sockaddr *) my_addr, sizeof(struct sockaddr))) == -1)
	{
		fprintf(stderr, "Error en funci�n bind. C�digo de error %s\n", strerror(aux));
		return -1;
	}
	/* Habilitamos el socket para recibir conexiones, con una cola de conexiones
	   en espera que tendr� como m�ximo el tama�o especificado en BACKLOG*/
	if ((aux = listen (sockaux, BACKLOG)) == -1)
	{
		fprintf(stderr, "Error en funci�n listen. C�digo de error %s\n", strerror(aux));
		return -1;
	}
	return sockaux;
}
/**
   \fn int Open_conectionThread(struct sockaddr_in * my_addr)
   \brief Abre las conexiones al un nuevo socket
   \details FUNCION OBSOLETA
   \author Sebastian Torres
   \date 27/11/2012
   \param[out] my_addr Valores de red(Puerto, ip, etc)
   \return fd al socket
 */
int Open_conectionThread (struct sockaddr_in *my_addr)
{
	int sockaux;    /*socket auxiliar*/
	int aux;        /*variable auxiliar*/
	int i=1;

/*Crea un socket y verifica si hubo alg�n error*/
	if ((sockaux = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		fprintf(stderr, "Error en funci�n socket. C�digo de error %s\n", strerror(sockaux));
		return -1;
	}

/* Asignamos valores a la estructura my_addr */

	my_addr->sin_family = AF_INET;      /*familia de sockets INET para UNIX*/
	my_addr->sin_port = htons(PORT+i);  /*convierte el entero formato PC a
	                                       entero formato network*/
	my_addr->sin_addr.s_addr = INADDR_ANY;  /* automaticamente usa la IP local */
	bzero(&(my_addr->sin_zero), 8);     /* rellena con ceros el resto de la
	                                       estructura */

	/* Con la estructura sockaddr_in completa, se declara en el Sistema que este
	   proceso escuchar� pedidos por la IP y el port definidos*/
	while(aux !=0 )
	{
		i++;
		my_addr->sin_port = htons(PORT+i);
		aux = bind (sockaux, (struct sockaddr *) my_addr, sizeof(struct sockaddr));
	}
	printf("Valor de aux %d\n",aux);
	/* Habilitamos el socket para recibir conexiones, con una cola de conexiones
	   en espera que tendr� como m�ximo el tama�o especificado en BACKLOG*/
	if ((aux = listen (sockaux, 1)) == -1)
	{
		fprintf(stderr, "Error en funci�n listen. C�digo de error %s\n", strerror(aux));
		return -1;
	}
	printf("Valor de listen %d\n",aux);
	return sockaux;
}
/**
   \fn int Aceptar_pedidos(int sockfd,struct sockaddr_int my_addr)
   \brief Se queda a la espera de una conexion
   \details Con la funcion accept() se queda a la espera de una conexion y cuando la consigue devuelve el valor del nuevo socket
   \author Sebastian Torres
   \date 27/11/2012
   \param[in] my_addr Valores de red(Puerto, ip, etc)
   \param[in] sockfd socket desde el cual conseguir la conexiones
   \param[out] newfd socket con la nueva conexion
   \return newfd
 */
int Aceptar_pedidos (int sockfd,struct sockaddr_in my_addr )
{
	int newfd;  /* Por este socket duplicado del inicial se transaccionar�*/
	struct sockaddr_in their_addr;      /* Contendra la direccion IP y n�mero de
	                                       puerto	del cliente */
	unsigned int sin_size = sizeof(struct sockaddr_in);
	/*Se espera por conexiones ,*/
	if ((newfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1)
	{
		fprintf(stderr, "Error en funci�n accept. C�digo de error %s\n", strerror(newfd));
		return -1;
	}
	else
	{
		printf  ("server:  conexion desde:  %s\n", inet_ntoa(their_addr.sin_addr));
		fflush(stdout);
		return newfd;
	}
}
/**
   \fn void sendNormalMessage(Clients * clients,int sockfd,int CID)
   \brief Manda un mensaje
   \details Manda un mesaje del tipo "Mensaje" al cliente al que este dirijido(Consiguiendo este leyendo el socket)
   \author Sebastian Torres
   \date 27/11/2012
   \param[in] socket Socket asociado al cliente que intenta mandar el mensaje
   \param[in] CID CID del cliente que intenta mandar el mensaje
   \param[in] clients Estructura que contiene a todos los usuarios y sus respectivos sockets
   \return Void
 */
void sendNormalMessage(Clients *clients,int socket,int CID)
{
	char a=0;
	char aux;
	int CIDDest;
	int socketDest;
	read(socket,&CIDDest,sizeof(int));
	printf("CID Destino %d\n",CIDDest);
	socketDest = getSocket(clients,CIDDest);
	printf("Socket destino %d\n",socketDest);
	read(socket,&aux,sizeof(char));
	write(socketDest,"mensaje/",sizeof(char)*8);
	write(socketDest,&CID,sizeof(int));
	write(socketDest,"/",sizeof(char));
	read(socket,&a,sizeof(char));
	while(a != '/')
	{
		write(socketDest,&a,sizeof(char));
		read(socket,&a,sizeof(char));
	}
	do
	{
		write(socketDest,&a,sizeof(char));
		read(socket,&a,sizeof(char));
	} while(a != '/');
	write(socketDest,"/",sizeof(char));
}
/**
   \fn void sendConnectMessageAll(Clients *clients,int sockfd,int CID)
   \brief Avisa de la conexion de un cliente
   \details Manda un mesaje del tipo "Connect" a todos los clientes
   \author Sebastian Torres
   \date 27/11/2012
   \param[in] socket Socket asociado al cliente que intenta mandar el mensaje
   \param[in] CID CID del cliente que intenta mandar el mensaje
   \param[in] clients Estructura que contiene a todos los usuarios y sus respectivos sockets
   \return Void
 */
void sendConnectMessageAll(Clients *clients,int socket,int CID)
{
	Clients *client = clients;
	Friends *aux;
	int socketDest;
	while(client && client->data.CID!=CID)
	{
		client = client->next;
	}
	aux = client->data.friends;
	while(aux)
	{
		socketDest = getSocket(clients,aux->CID);
		if(socketDest)
		{
			write(socketDest,"connect/",sizeof(char)*8);
			write(socketDest,&((client->data).CID),sizeof(int));
		}
		aux = aux->next;
	}
}
/**
   \fn void sendDisconnectMessageAll(Clients *clients,int sockfd,int CID)
   \brief Avisa de la desconexion de un cliente
   \details Manda un mesaje del tipo "Deconne" a todos los clientes
   \author Sebastian Torres
   \date 27/11/2012
   \param[in] socket Socket asociado al cliente que intenta mandar el mensaje
   \param[in] CID CID del cliente que intenta mandar el mensaje
   \param[in] clients Estructura que contiene a todos los usuarios y sus respectivos sockets
   \return Void
 */
void sendDisconnectMessageAll(Clients *clients,int socket,int CID)
{
	Clients *client = clients;
	Friends *aux;
	int socketDest;
	while(client && client->data.CID!=CID)
	{
		client = client->next;
	}
	aux = client->data.friends;
	while(aux)
	{
		socketDest = getSocket(clients,aux->CID);
		if(socketDest)
		{
			write(socketDest,"disconn/",sizeof(char)*8);
			write(socketDest,&((client->data).CID),sizeof(int));
		}
		aux = aux->next;
	}
}
/**
   \fn void sendDisconnectMessageAll(Clients *clients,int sockfd,int CID)
   \brief Avisa de la desconexion de un cliente al que esta conectado el socket
   \details FUNCION OBSOLETA
   \author Sebastian Torres
   \date 27/11/2012
   \param[in] socket Socket asociado al cliente que intenta mandar el mensaje
   \param[in] CIDDest CID del cliente que se desconecto
   \return Void
 */
void sendDisconnectMessage(int socket,int CIDDest)
{
	write(socket,"disconn/",sizeof(char)*8);
	write(socket,&(CIDDest),sizeof(int));
}
/**
   \fn void sendConnectMessageAll(Clients *clients,int sockfd,int CID)
   \brief Avisa de la conexion de un cliente al que esta conectado el socket
   \details FUNCION OBSOLETA
   \author Sebastian Torres
   \date 27/11/2012
   \param[in] socket Socket asociado al cliente que intenta mandar el mensaje
   \param[in] CIDDest CID del cliente que se desconecto
   \return Void
 */
void sendConnectMessage(int socket,int CIDDest)
{
	write(socket,"connect/",sizeof(char)*8);
	write(socket,&(CIDDest),sizeof(int));
}
/**
   \fn void sendUserInfo(Clients *clients,int sockfd,int CID)
   \brief Manda toda la informacion del cliente
   \details Manda la informacion del cliente respectivo al CID por el socket ingresado
   \author Sebastian Torres
   \date 27/11/2012
   \param[in] socket Socket asociado al cliente que intenta mandar el mensaje
   \param[in] CID CID del cliente que va a recibir los datos
   \param[in] clients Estructura que contiene a todos los usuarios y sus respectivos sockets
   \return Void
 */
void sendUserInfo(Clients *clients,int CID,int socket)
{
	Clients client = *clients;
	while(client.data.CID!=CID)
	{
		client=*(client.next);
	}
	if(write(socket,&(client.data),sizeof(DataClient)-8) == -1)
	{
		printf("Error Error destroy! destroy! SendUserInfo crashed!!!\n");
	}
	while(client.data.friends)
	{
		if(write(socket,client.data.friends,sizeof(Friends)) == -1)
		{
			printf("Error Error destroy! destroy! SendUserInfo crashed while sending friends");
		}
		client.data.friends=client.data.friends->next;
	}
}
/**
   \fn void sendConnectedFriends(Clients *clients,int sockfd,int CID)
   \brief Manda toda la lista de amigos del cliente
   \details Manda la lista de amigos del cliente respectivo al CID por el socket ingresado
   \author Sebastian Torres
   \date 27/11/2012
   \param[in] socket Socket asociado al cliente que intenta mandar el mensaje
   \param[in] CID CID del cliente que va a recibir los datos
   \param[in] clients Estructura que contiene a todos los usuarios y sus respectivos sockets
   \return Void
 */
void sendConnectedFriends (Clients *clients,int socket,int CID)
{
	Clients *client = clients;
	Friends *aux;
	while(client && client->data.CID!=CID)
	{
		client = client->next;
	}
	aux = client->data.friends;
	while(aux)
	{
		printf("Pase por un amigo de %d\n",CID);
		if(getSocket(clients,aux->CID))
		{
			printf("Estoy enviando el amigo de %d que es %d\n",CID,aux->CID);
			write(socket,"connect/",sizeof(char)*8);
			write(socket,&(aux->CID),sizeof(int));
		}
		aux = aux->next;
	}
}
/**
   \fn void startChild(void * threadPass_t)
   \brief Funcion principal activada en la creacion del thread
   \details Recibe los datos necesarios desde la estructura void * ingresada, luego setea el socket en la lista de usuarios, manda la informacion del usuario y luego entra en un loop leyendo desde el socket para mandar el mensaje correspondiente en cada caso
   \author Sebastian Torres
   \date 27/11/2012
   \param[in] threadPass_t Estructura del tipo ThreadPass que contiene los datos de la nueva conexion
   \return Void
 */
void startChild(void* threadPass_t)
{
	Clients **clients = ((ThreadPass*)threadPass_t)->Client;
	int socket = ((ThreadPass*)threadPass_t)->socket;
	int CID = ((ThreadPass*)threadPass_t)->CID;
	//int socket;
	char type[8];
	int flag=1;
	char a;
	// int CIDTarget;
	//struct sockaddr_in my_addr;
	//socket = Open_conectionThread(&my_addr);
	//write(sockAux,&(my_addr.sin_port),sizeof(unsigned short int));
	//socket = Aceptar_pedidos(socket,my_addr);
	//close(sockAux);
	setSocket(clients,CID,socket,((ThreadPass*)threadPass_t)->mutex);
	sendUserInfo(*clients,CID,socket);
	printf("Socket de %d = %d\n",CID,getSocket(*clients,CID));
	sendConnectedFriends(*clients,socket,CID);
	sendConnectMessageAll(*clients,socket,CID);
	while(flag)
	{
		read(socket,type,sizeof(char)*7);
		type[7]=NULLC;
		read(socket,&a,sizeof(char));
		printf("Tipo de mensaje %s \n",type);
		if(!strcmp(type,"mensaje"))
		{
			sendNormalMessage(*clients,socket,CID);

		}else if(!strcmp(type,"disconn")) {
			sendDisconnectMessageAll(*clients,socket,CID);
			printf("Se desconecto %d \n",CID);
			setSocket(clients,CID,0,((ThreadPass*)threadPass_t)->mutex);
			close(socket);
			flag=0;
		}/*else if(!strcmp(type,"connect")){
		    sendConnectMessage(socket,CIDTarget);
		    }*/
	}
	pthread_exit(NULL);

}