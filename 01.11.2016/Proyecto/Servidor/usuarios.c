/**
  \file usuarios.c
  \brief Archivo de libreria orientado al manejo de usuarios
  \details Contiene todas las funciones a utilizar que tengan relacion al manejo de usuarios
  \author Sebastian Torres
  \date 27/11/2012
*/
#include "usuarios.h"
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
DataClient getUser(Clients client,int CID)
{
  while(client.data.CID!=CID)
  {
    client=*(client.next);
  }
  return client.data;
}
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
void loadFriends(int socket,Friends **h,int FriQuant)
{
  int i=0;
  Friends *friend;
  for(i=0;i<FriQuant;i++)
  {
    friend = (Friends*)malloc(sizeof(Friends));
    read(socket,friend,sizeof(Friends));
    friend->next=NULL;
    pushF(friend,h);
  }
}
void showUser(DataClient user)
{
  printf("El usuario %s tiene mail %s y su contraseña es %s , tiene %d amigos y su CID es %d\n",user.nick,user.email,user.password,user.FriQuant,user.CID);
  while(user.friends)
  {
    printf("Amigo : %s CID: %d\n",user.friends->nick,user.friends->CID);
    user.friends=user.friends->next;
  }
}
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
int getSocket(Clients *clients,int CID)
{
  Clients *aux=clients;
  while(aux->data.CID!=CID && aux!=NULL)
  {
    aux = aux->next;
  }
  return aux->data.socket;
}