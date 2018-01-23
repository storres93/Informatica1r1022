/**
   \file header.h
   \brief Header
   \details Directivas, Prototipos y definiciones.
   \author Demski Andres
   \date 2012.11.27
 */

#include <opencv2/core/core_c.h>
#include <opencv2/opencv_modules.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netdb.h>

//gcc `pkg-config --cflags opencv` `pkg-config --libs opencv` -o prueba main.c
// espacio entre linea
#define LINE_SPACE 17
// Caracteres MAXIMOS por linea
#define CH_LINE 150
//El alto del sector de escritura
#define ALTO_NEW_TEXT 60
//Color del texto (que se esta escribiendo) (RGB)
#define COLOR_TXT (255,255,255,0)
//Color del MSJ resivido
#define COLOR_MSJ (255,255,255,0)
//Tamaño de la ventana (Recomendado: 500*600)
#define IMG_X 500
#define IMG_Y 600
//Quien manda el msj,Define el color del circulito
#define YO 1
#define OTRO 2
#define NADIE 0
//LOGIN,cuan largo el texto
#define LOGIN_REC_X 200
#define LOGIN_REC_Y 25
#define LOGIN_REC_POS_Y 350
#define LOGIN_CH 50
#define PASSWORD 25
//Amigos por columna
#define AMIGOTES 23
//1º Linea en Principal
#define FIRST_LINE 70
//IP Y PUERTO
#define IP "127.0.0.1"
#define PORTC "3490"    /* El puerto donde se conectar�, servidor */
#define BACKLOG 20  /* Tama�o de la cola de conexiones recibidas */

#define NULLC '\0'


typedef struct _Mensaje
{
	char msj1[CH_LINE];
	char msj2[CH_LINE];
	struct _Mensaje *next;
} Ls_Msj;

typedef struct _susdatos
{
	int ID;
	char Nick[50];
	char Estado;
} SusDatos;

typedef struct _Ls_Friends
{
	SusDatos datos;
	Ls_Msj *Msj;
	struct _Ls_Friends * next;
} Ls_Friends;

typedef struct _datos
{
	int ID;
	char Nick[50];
	char Email[50];
	char Password[PASSWORD+1];
	int FriQuant;
} DatosMios;

typedef struct _misdatos
{
	DatosMios datos;
	Ls_Friends *Friends;
}MisDatos;

typedef struct _thread
{

	int fd;
	MisDatos *datos;
} threadParam;


void clearbar (IplImage*);
void addifnotblack(IplImage*,IplImage*);
void moveup (IplImage *);
void newmsj (IplImage *,char *, char);
void writemsj (int,char*, IplImage *,Ls_Friends*);
int login (char *,MisDatos*);
int completar_campos (char*, IplImage *,char*,char*);
int principal ( int, char *,MisDatos*);
void chat (int, char *, MisDatos *, Ls_Friends *);
void actualizarmsj (IplImage*, Ls_Friends*);
void topchat (IplImage *,Ls_Friends *);
void poner_imagen (IplImage *,IplImage *);
int conectarconserver (char*user,char*password);
int conectar (char*, char*);
void loadFriends(int,Ls_Friends**,int);
int llenardatos (int, MisDatos*);
void pushF (Ls_Friends *,Ls_Friends **);
void encolarMsj (Ls_Msj *,Ls_Msj**);
void threadFunc (void*);
void desconectar (int,int);
void setConnected(Ls_Friends*,int);
void setDisconnected(Ls_Friends*,int);
void actualizarPrin (char*, IplImage *, Ls_Friends* [][23] );
void sendNormalMsj (int, int,char*,char*);

CvFont Font;