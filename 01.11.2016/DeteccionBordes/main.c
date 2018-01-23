/**
    \file main.c
    \brief Realiza deteccion de bordes sobre una imagen
    \details Uso: ./mostrarImagen <path/a/imagen>
    \author Sebastian Torres
    \date 08/11/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>


int main (void)
{
	int key = 0;
	IplImage *img;
	IplImage *img_gray = NULL;
	IplImage *img_borders = NULL;
	CvSize img_size;

	// Creamos una ventana
	cvNamedWindow("imagen", CV_WINDOW_AUTOSIZE);

	// Cargamos nuestra imagen de prueba
	img = cvLoadImage("./lena.jpg", CV_LOAD_IMAGE_COLOR);

	img_size = cvSize(img->width,img->height);

	// Creamos nuevas imagenes desde la nuestra
	img_gray =  cvCreateImage(img_size, img->depth, 1);
	img_borders =  cvCreateImage(img_size, img->depth, 1);

	// Hacemos cambio a escala de grises y luego aplicamos el algoritmo Canny para deteccion de bordes
	cvCvtColor(img, img_gray, CV_RGB2GRAY);
	cvCanny(img_gray, img_borders, 51, 51, 3);

	// Mostramos las imagenes
	cvShowImage("img", img);
	cvShowImage("gray", img_gray);
	cvShowImage("borders", img_borders);

	// Bloqueamos el programa esperando una tecla y luego liberamos las imagenes
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&img_gray);
	cvReleaseImage(&img_borders);
	cvDestroyWindow( "imagen" );
	return 0;
}


