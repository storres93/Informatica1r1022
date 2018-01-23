/**
  \file usuarios.h
  \brief Archivo de prototipos de la libreria de usuarios
  \details Contiene todos los prototipos y estructuras para el manejo de usuarios
  \author Sebastian Torres
  \date 27/11/2012
*/
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct friends_t
{
  int CID;
  char nick[50];
  struct friends_t *next;
}Friends;
typedef struct dataClient_t
{
  int CID;
  char nick[50];
  char email[50];
  char password[26];
  int FriQuant;
  Friends *friends;
  int socket;
}DataClient;
typedef struct clients_t
{
  DataClient data;
  struct clients_t *next;
}Clients;
typedef struct threadPass_t
{
  Clients **Client;
  int socket;
  int CID;
  pthread_mutex_t *mutex;
}ThreadPass;
typedef struct threadPassClient_t
{
  DataClient yo;
  int socket;
  pthread_mutex_t *mutex;
}ThreadPassClient;
int login(int,Clients*);
void setSocket(Clients**,int,int,pthread_mutex_t*);
int pyuVerify(char*,char*,Clients*);
int getSocket(Clients*,int);
int createUserList(Clients**);
int addUser(Clients**);
void pushF(Friends*,Friends**);
void push(Clients*,Clients**);
int getCID(Clients*);
void showFriends(Clients*);
void fillFriendList(Clients**);
DataClient getUser(Clients,int);
#define NULLC '\0'