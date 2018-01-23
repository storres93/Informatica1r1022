/**
  \file usuarios.c
  \brief Archivo de libreria orientado al manejo de usuarios
  \details Contiene todas las funciones a utilizar que tengan relacion al manejo de usuarios
  \author Sebastian Torres
  \date 27/11/2012
*/
#include "usuarios.h"
/**
  \fn int createUserList(Clients * * client)
  \brief Crea la lista de usuarios
  \details Carga de a un usuario hasta que el administrador presione 0 o hasta que addUser devuelva 0
  \author Sebastian Torres
  \date 27/11/2012
  \param[out] client Datos de los clientes
  \return retState
*/
int createUserList(Clients **client)
{
  int flag=1;
  int retState=1;// 1 = Se creo BD y lista || 2 = Se creo lista || 0 = hubo un error
  while(flag)
  {
      if(addUser(client))
      {
	printf("Si desea ingresar otro usuario ingrese 1, de lo contrario ingrese 0\n");
	scanf("%d",&flag);
      }else{
	retState=0;
	flag=0;
      }
  }
  fillFriendList(client);
  showFriends(*client);
  return retState;
}
/**
  \fn int fillFriendList(Clients * * client)
  \brief Crea la lista de amigos de cada usuario
  \details Luego de tener los datos de cada uno de los usuarios se llena el nick de cada uno en la lista de amigos
  \author Sebastian Torres
  \date 27/11/2012
  \param[out] client Listas de amigos de los clientes
  \return Void
*/
void fillFriendList(Clients **client)
{
  Clients *aux=*client;
  DataClient friend;
  Friends *auxF;
  while(aux)
  {
    auxF=aux->data.friends;
    while(auxF)
    {
      friend=getUser(**client,auxF->CID);
      strcpy(auxF->nick,friend.nick);
      auxF=auxF->next;
    }
    aux=aux->next;
  }
}
/**
  \fn DataClient getUser(Clients client,int CID)
  \brief Devuelve la estructura del usuario deseado
  \author Sebastian Torres
  \date 27/11/2012
  \param[in] client Listas de clientes
  \param[in] CID Usuario deseado
  \return client.data
*/
DataClient getUser(Clients client,int CID)
{
  while(client.data.CID!=CID)
  {
    client=*(client.next);
  }
  return client.data;
}
/**
  \fn int addUser(Clients * * client)
  \brief Añade un usuario a la lista
  \details Consigue todos los datos mediante scanf y devuelve un numero igual a 0 en caso de error
  \author Sebastian Torres
  \date 27/11/2012
  \param[out] h Listas de amigos de los clientes
  \return retState
*/
int addUser(Clients **h)
{
  Clients *a;
  Friends *friend;
  int CIDF;
  int friendsQuant=0;
  int retState=1;
  a=(Clients*)malloc(sizeof(Clients));
  a->data.friends=NULL;
  a->data.socket=0;
  printf("Ingrese el nombre\n");
  scanf("%s",(a->data).nick);
  printf("Ingrese el mail\n");
  scanf("%s",(a->data).email);
  printf("Ingrese la contraseña\n");
  scanf("%s",(a->data).password);
  (a->data).CID = getCID(*h);
  printf("Ingrese todos los codigos de sus amigos por separado y luego 0 para finalizar\n");
  scanf("%d",&CIDF);
  while(CIDF)
  {
    friend = (Friends*)malloc(sizeof(Friends));
    friend->CID=CIDF;
    pushF(friend,&(a->data.friends));
    friendsQuant++;
    scanf("%d",&CIDF);
  }
  (a->data).FriQuant=friendsQuant;
  push(a,h);
  printf("Se ah agregado al usuario %s de mail %s y contraseña %s , el CID correspondiente es %d\n",(a->data).nick,(a->data).email,(a->data).password,(a->data).CID);
  return retState;
}
/**
  \fn void showFriends(Clients * a)
  \brief Muestra los amigos de cada usuario
  \author Sebastian Torres
  \date 27/11/2012
  \param[in] a Lista de usuarios
  \return Void
*/
void showFriends(Clients *a)
{
  Clients *aux=a;
  Friends *auxF;
  while(aux)
  {
    printf("Mostrando los %d amigos de %s\n",aux->data.FriQuant,aux->data.nick);
    auxF=aux->data.friends;
    while(auxF)
    {
      printf("Amigo : %s , CID : %d\n",auxF->nick,auxF->CID);
      auxF=auxF->next;
    }
    aux=aux->next;
  }
}

/**
  \fn int getCID(Clients * h)
  \brief Consigue un CID que no este en uso
  \author Sebastian Torres
  \date 27/11/2012
  \param[in] h Lista de usuarios
  \return CID
*/
int getCID(Clients *h)
{
  int CID=1;
  if(!h)
  {
    return CID;
  }
  Clients *aux=h;
  while(aux)
  {
    if(aux->data.CID>=CID)
    {
      CID++;
    }
    aux=aux->next;
  }
  return CID;
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
void pushF(Friends *a,Friends **h)
{
  if(!*h)
  {
   *h=a;
   return;
  }
  Friends *aux=*h;
  while(aux->next)
    aux=aux->next;
  aux->next=a;
  a->next=NULL;
}
/**
  \fn void push(Clients * a,Clients **h)
  \brief Agrega a la lista de usuarios un nuevo nodo
  \details Agrega a la ultima poscicion de la lista de usuarios un nuevo nodo
  \author Sebastian Torres
  \date 27/11/2012
  \param[in] a Nuevo nodo
  \param[out] h Lista de usuarios
  \return Void
*/
void push(Clients *a,Clients **h) // Lo pone en la ultima poscicion
{
 if(!*h)
 {
   *h=a;
 }
 Clients *aux=*h;
 while(aux->next)
   aux=aux->next;
 aux->next=a;
 a->next=NULL;
}
/**
  \fn int pyuVerify(char * pass, char * user, Clients * client)
  \brief Verifica un usuario y contraseña
  \details Se fija si existe el usuario y luego si la contraseña es correcta, devuelve el CID del cliente en caso de exito o 0 si no verifica
  \author Sebastian Torres
  \date 27/11/2012
  \param[in] pass Contraseña
  \param[in] user Usuario
  \param[in] client Lista de usuarios
  \return ret
*/
int pyuVerify(char *pass,char *user,Clients *client)
{
  Clients *clients = client;
  int ret=0;
  while(clients && strcmp(clients->data.nick,user))
  {
    clients = clients->next;
  }
  if(clients && !strcmp((clients->data).password,pass))
  {
    ret = clients->data.CID;
  }
  return ret;
}
/**
  \fn int login(int sockFd, Clients * clients)
  \brief Verifica el logueo de un usuario
  \details Consigue el usuario y luego la contraseña mediante el socket y verifica esto con la funcion pyuVerify. Devuelve el CID del usuario en caso de exito o 0 en caso de error
  \author Sebastian Torres
  \date 27/11/2012
  \param[in] sockFd Socket de comunicacion
  \param[in] clients Lista de usuarios
  \return ret
*/
int login(int sockFd,Clients *clients)
{
  int ret=0;
  char user[50];
  char pass[26];
  int i=0;
  char a;
  while(read(sockFd,&a,sizeof(char))==sizeof(char) && a!='/')
  {
    user[i]=a;
    i++;
  }
  user[i]=NULLC;
  i=0;
  while(read(sockFd,&a,sizeof(char))==sizeof(char) && a!='/')
  {
    pass[i]=a;
    i++;
  }
  pass[i]=NULLC;
  ret = pyuVerify(user,pass,clients);
  return ret;
}
/**
  \fn void setSocket(Clients * * clients,int CID,int socket, pthread_mutex_t * mutex)
  \brief Pone en el valor especificado el socket correspondiente
  \author Sebastian Torres
  \date 27/11/2012
  \param[in] socket Valor a cambiar
  \param[in] clients Lista de usuarios
  \param[in] mutex Variable para que otros thread no modifiquen al mismo tiempo el mismo socket
  \param[in] CID CID que se quiere modificar
  \return Void
*/
void setSocket(Clients **clients,int CID,int socket,pthread_mutex_t *mutex)
{
  Clients *aux=*clients;
  while(aux->data.CID!=CID)
  {
    aux=aux->next;
  }
  pthread_mutex_lock(mutex);
  aux->data.socket=socket;
  pthread_mutex_unlock(mutex);
}
/**
  \fn int getSocket(Clients * clients,int CID)
  \brief Devuelve el socket del cliente CID
  \author Sebastian Torres
  \date 27/11/2012
  \param[in] CID CID del cual se quiere conseguir el socket
  \param[in] clients Lista de usuarios
  \return socket
*/
int getSocket(Clients *clients,int CID)
{
  Clients *aux=clients;
  while(aux->data.CID!=CID && aux!=NULL)
  {
    aux = aux->next;
  }
  return aux->data.socket;
}