/**
    \file main.c
    \brief Crea un boton mediante opencv
    \details Crea un rectangulo y luego hace deteccion de clicks
    \author Sebastian Torres
    \date 08/11/2016
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

#define REC_X 100
#define REC_Y 25
#define REC_TAM_Y 25
#define REC_TAM_X 200
#define TAM_STRING 100
void crearBoton(IplImage*);
void callbackBoton(int, int, int, int, void*);

int main(int argc, char *argv[])
{
	//Creamos una ventana de tamaño 500x300
	cvNamedWindow("Boton",  CV_WINDOW_NORMAL);
	cvResizeWindow("Boton", 500, 300);

	//Creamos una imagen de fondo que podamos modificar del mismo tamaño que la pantalla
	IplImage* imagenFondo = cvCreateImage(cvSize(500, 300), 8, 3);
	cvZero(imagenFondo);

	//Creamos nuestro boton
	crearBoton(imagenFondo);

	//Mostramos la imagen
	cvShowImage ("CampoDeTexto",imagenFondo);

	//Creamos el callback para nuestro evento de click
	cvSetMouseCallback("CampoDeTexto", callbackBoton, NULL);

	// wait for a key
	cvWaitKey(0);

	cvReleaseImage(&imagenFondo);
	return 0;
}

void crearBoton(IplImage* imagenFondo)
{
	CvFont Font;

	int rectanguloDesdeDonde_X = REC_X;
	int rectanguloDesdeDonde_Y = REC_Y;
	int rectanguloHastaDonde_X = rectanguloDesdeDonde_X + REC_TAM_X;
	int rectanguloHastaDonde_Y = rectanguloDesdeDonde_Y + REC_TAM_Y;

	//Incializamos las fuentes
	cvInitFont(&Font,CV_FONT_HERSHEY_SIMPLEX, 0.4, 0.5, 0, 1,8);

	cvRectangle (imagenFondo,
				 cvPoint (rectanguloDesdeDonde_X, rectanguloDesdeDonde_Y),
				 cvPoint (rectanguloHastaDonde_X, rectanguloHastaDonde_Y),
				 cvScalar (255,255,255,0),1,8,0);

	cvPutText (imagenFondo,"Este es un boton",cvPoint(rectanguloDesdeDonde_X + 35, rectanguloDesdeDonde_Y + 16), &Font, cvScalar (255,255,255,0));
}
/*
   Eventos:
   CV_EVENT_MOUSEMOVE      =0,
   CV_EVENT_LBUTTONDOWN    =1,
   CV_EVENT_RBUTTONDOWN    =2,
   CV_EVENT_MBUTTONDOWN    =3,
   CV_EVENT_LBUTTONUP      =4,
   CV_EVENT_RBUTTONUP      =5,
   CV_EVENT_MBUTTONUP      =6,
   CV_EVENT_LBUTTONDBLCLK  =7,
   CV_EVENT_RBUTTONDBLCLK  =8,
   CV_EVENT_MBUTTONDBLCLK  =9

   Flags:
   CV_EVENT_FLAG_LBUTTON   =1,
   CV_EVENT_FLAG_RBUTTON   =2,
   CV_EVENT_FLAG_MBUTTON   =4,
   CV_EVENT_FLAG_CTRLKEY   =8,
   CV_EVENT_FLAG_SHIFTKEY  =16,
   CV_EVENT_FLAG_ALTKEY    =32
 */
void callbackBoton(int evento, int x, int y,int flags, void* sth)
{
	int rectanguloDesdeDonde_X = REC_X;
	int rectanguloDesdeDonde_Y = REC_Y;
	int rectanguloHastaDonde_X = rectanguloDesdeDonde_X + REC_TAM_X;
	int rectanguloHastaDonde_Y = rectanguloDesdeDonde_Y + REC_TAM_Y;

	if(evento == CV_EVENT_LBUTTONDOWN && x > rectanguloDesdeDonde_X && y > rectanguloDesdeDonde_Y && x < rectanguloHastaDonde_X && y < rectanguloHastaDonde_Y)
	{
		printf("Hicimos click!!!!\n");
		fflush(stdout);
	}
}