/**
    \file main.c
    \brief Muestra una imagen mediante opencv
    \details Uso: ./mostrarImagen <path/a/imagen>
    \author Sebastian Torres
    \date 08/11/2016
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>


int main(int argc, char *argv[])
{
	IplImage* img = 0;
	int height,width,channels;

	if(argc<2) {
		printf("Usage: main <image-file-name>\n\7");
		exit(0);
	}

	// Cargamos la imagen desde el archivo pasado por linea de comandos
	img=cvLoadImage(argv[1], 1);
	if(!img) {
		printf("Could not load image file: %s\n",argv[1]);
		exit(0);
	}

	// Conseguimos la informacion de la imagen
	height    = img->height;
	width     = img->width;
	channels  = img->nChannels;
	printf("Processing a %dx%d image with %d channels\n",height,width,channels);

	// Creamos una ventana
	cvNamedWindow("mainWin", CV_WINDOW_AUTOSIZE);
	cvMoveWindow("mainWin", 100, 100);

	// Mostramos la imagen
	cvShowImage("mainWin", img );

	// Nos quedamos esperando una tecla para bloquear el programa
	cvWaitKey(0);

	// Liberamos la imagen
	cvReleaseImage(&img );
	return 0;
}