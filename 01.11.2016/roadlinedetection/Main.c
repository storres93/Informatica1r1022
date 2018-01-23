/**
 * \file	Main.c
 * \brief	Main para probar ImagesAndLines
 * \c		Compilar: make
 * \arg		Se pasa por linea de comandos el nombre de la foto (make)
 * \author  Santiago F. Maudet - Andrés Demski - Nicolás Linale
 * \date    23/07/2014
 **/

#include "Header.h"

int main( int argc, char *argv[] ) {

	// Declaro variables
	int key =0;
	IplImage *croped = NULL;
	char *filename = NULL;
	Linea lineas[3];

	// Check vargins
	if (argc == 2) filename = argv[1];
	else printf("\nError: No se especificó entrada por línea de comandos\n");

	CvCapture* capture = cvCaptureFromFile(filename);

	// Check
	if ( !capture )
	{
		fprintf (stderr,"No se pudo abrir el video\n" );
		return 1;
	}

	IplImage* frame = cvQueryFrame( capture );

	// Get the fps, needed to set the delay
	int fps = ( int )cvGetCaptureProperty( capture, CV_CAP_PROP_FPS );

	// Create a window to display the video

	cvNamedWindow("video", CV_WINDOW_AUTOSIZE);

	while( key != 'x' )
	{
		// get the image frame
		frame = cvQueryFrame( capture );

		if( !frame ) break;

		croped = CropImage (frame,50,350,350,150);

		// Llamo a nuestra función
		ImagesAndLines (&croped, lineas);
		Validar_Lineas (lineas,lineas);

		PrintLines (croped, lineas[0],255,0,0);
		PrintLines (croped, lineas[1],0,255,0);
		PrintLines (croped, lineas[2],0,0,255);

		cvShowImage( "video", croped );

		// exit if user presses 'x'
		key = cvWaitKey( 10000 / fps );
	}

	// Tidy up
	cvDestroyWindow( "video" );
	cvReleaseCapture( &capture );

	// Libero memoria y retorno
	cvReleaseImage(&croped);
	return(0);
}



/*
 * i n*t main( int argc, char *argv[] ) {
 *
 *    // Declaro variables
 *    IplImage *image = NULL;
 *    IplImage *croped = NULL;
 *    char *filename = NULL;
 *  Linea lineas[3];
 *
 *  // Check vargins
 *  if (argc == 2)
 *    filename = argv[1];
 *  else
 *    printf("\nError: No se especificó entrada por línea de comandos\n");
 *
 *  // Cargo la imagen
 *  image = cvLoadImage(filename,BGR);
 *
 *  // Recorto la imagen
 *  croped = CropImage (image,0,(image->height-1)/2,image->width,image->height/2);
 *
 *  // Llamo a nuestra función
 *  ImagesAndLines (&croped, lineas);
 *
 *
 *  PrintLines (croped, lineas[0],255,0,0);
 *  PrintLines (croped, lineas[1],0,255,0);
 *  PrintLines (croped, lineas[2],0,0,255);
 *
 *  cvNamedWindow("RGB", CV_WINDOW_AUTOSIZE);
 *  cvShowImage("RGB", croped);
 *
 *  cvWaitKey(0);
 *
 *  // Libero memoria y retorno
 *  cvReleaseImage(&image);
 *  cvReleaseImage(&croped);
 *  return(0);
   }*/

