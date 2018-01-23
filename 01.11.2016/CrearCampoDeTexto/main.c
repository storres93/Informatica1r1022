/**
    \file main.c
    \brief Crea un campo de texto mediante opencv
    \details Crea un rectangulo y luego hace deteccion de teclas para ir poniendo texto en pantalla
    \author Sebastian Torres
    \date 08/11/2016
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>


//Definimos los parametros de nuestro rectangulo
#define REC_X 100
#define REC_Y 25
#define REC_TAM_Y 25
#define REC_TAM_X 200
#define TAM_STRING 100
void crearCampodeTexto(IplImage*, CvFont);
void leemosDelCampo(char*, IplImage*, CvFont);

int main(int argc, char *argv[])
{
	CvFont Font;

	//Creamos una ventana de tamaño 500x300
	cvNamedWindow("CampoDeTexto",  CV_WINDOW_NORMAL);
	cvResizeWindow("CampoDeTexto", 500, 300);

	//Creamos una imagen de fondo que podamos modificar del mismo tamaño que la pantalla
	IplImage* imagenFondo = cvCreateImage(cvSize(500, 300), 8, 3);
	cvZero(imagenFondo);

	//Incializamos las fuentes
	cvInitFont(&Font,CV_FONT_HERSHEY_SIMPLEX, 0.4, 0.5, 0, 1,8);

	//Creamos el campo de texto
	crearCampodeTexto(imagenFondo, Font);

	//Mostramos la imagen
	cvShowImage("CampoDeTexto",imagenFondo);

	//Leemos del campo y mostramos en pantalla
	leemosDelCampo("CampoDeTexto", imagenFondo, Font);

	// Bloqueamos hasta que toquen una tecla
	cvWaitKey(0);

	// Borramos la imagen
	cvReleaseImage(&imagenFondo);
	return 0;
}

void crearCampodeTexto(IplImage* imagenFondo, CvFont Font)
{
	// Realizamos calculos para definir los puntos (x,y)
	int rectanguloDesdeDonde_X = REC_X;
	int rectanguloDesdeDonde_Y = REC_Y;
	int rectanguloHastaDonde_X = rectanguloDesdeDonde_X + REC_TAM_X;
	int rectanguloHastaDonde_Y = rectanguloDesdeDonde_Y + REC_TAM_Y;

	// Creamos un rectangulo y se lo asignamos a la imagen de fondo
	cvRectangle (imagenFondo,
				 cvPoint (rectanguloDesdeDonde_X, rectanguloDesdeDonde_Y),
				 cvPoint (rectanguloHastaDonde_X, rectanguloHastaDonde_Y),
				 cvScalar (255,255,255,0),1,8,0);

	// Ponemos un texto de referencia un poco mas arriba del rectangulo
	cvPutText (imagenFondo,"El texto va aqui",cvPoint(rectanguloDesdeDonde_X + 35, rectanguloDesdeDonde_Y - 8), &Font, cvScalar (255,255,255,0));
}

void leemosDelCampo(char* nombreVentana, IplImage* imagenFondo, CvFont Font)
{
	char texto[TAM_STRING];
	int i = 0;
	for (i=0; i<TAM_STRING; i++) { texto[i]=(char)0; } //inicializo
	CvSize text_size;
	int baseline;
	int puntero_lector = 0;
	char aux = cvWaitKey(0); //Completar campos

	// Definimos desde donde y hasta donde va a ir el texto
	int textoDesdeDonde_X = REC_X + 10;
	int rectanguloDesdeDonde_Y = REC_Y;
	int textoHastaDonde_X = textoDesdeDonde_X + REC_TAM_X;
	int textoHastaDonde_Y = rectanguloDesdeDonde_Y + REC_TAM_Y - 8;

	while (aux != 27) //llenar campo User, usa la misma logica que writemsj
	{
		printf("Leimos: %c\n", aux);
		printf("Nuestro texto va quedando como: %s\n", texto);
		fflush(stdout);
		cvGet`
		//Aca vamos a entrar si escribio una letra
		if (aux > 31 && aux < 127)
		{

			cvGetTextSize(texto, &Font, &text_size, &baseline);     //Tamaño que va a ocupar el texto
			if ((textoHastaDonde_X - textoDesdeDonde_X - 20) > text_size.width)
			{
				texto[puntero_lector]=aux;
				cvPutText(imagenFondo,texto,cvPoint(textoDesdeDonde_X,textoHastaDonde_Y), &Font, cvScalar (255,255,255,0));
				cvShowImage(nombreVentana,imagenFondo);
				puntero_lector++;
			}
		}

		//Aca vamos a entrar si quiere borrar algo
		if ((aux==8 || aux==127) && puntero_lector)
		{
			cvPutText(imagenFondo,texto,cvPoint(textoDesdeDonde_X,textoHastaDonde_Y), &Font, cvScalar (0,0,0,0));
			cvShowImage(nombreVentana,imagenFondo);
			texto[puntero_lector]=(char)0;
			puntero_lector--;
			texto[puntero_lector]=(char)0;
			cvPutText(imagenFondo,texto,cvPoint(textoDesdeDonde_X,textoHastaDonde_Y), &Font, cvScalar (255,255,255,0));
			cvShowImage(nombreVentana,imagenFondo);
		}
		aux = cvWaitKey(0);
	}
}