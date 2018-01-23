/**
 * \file	Funciones.h
 * \brief	Header de Funciones.c
 * \c		Compilar: make
 * \author	Santiago F. Maudet - Andrés Demski - Nicolás Linale
 * \date 	20/07/2014
 **/


/**
 * \include	<stdio.h>
 * \include	<stdlib.h>
 * \include	<string.h>
 * \include	<errno.h>
 * \include 	<opencv/cv.h>
 * \include	<opencv/highgui.h>
 * \include 	<opencv/cxtypes.h>
 * \include 	<opencv/cxcore.h>
 * \include	<math.h>
 **/
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<errno.h>
#include 	<opencv/cv.h>
#include	<opencv/highgui.h>
//include 	<opencv/cxtypes.h>
//#include 	<opencv/cxcore.h>
#include	<math.h>


/**
 * \def		BGR		1		Nomenclatura OpenCV: 1 = tres colores (RGB)
 * \def		ANCHO_MAX	31		Máximo ancho para una línea válida (Modificar si se cambia la posicion de la camara)
 * \def		ANCHO_MIN	3		Mínimo ancho para una línea válida (Modificar si se cambia la posicion de la camara)
 * \def		CANT_FILAS	4		Numero de filas a analizar	(Se pueden agregar mas, en caso de agregar, hay que modificar el codigo)
 * \def		PI		3.14159		Constante Pi
 * \def		MAX_NUM_LINES	15		Maximo numero de lineas para el cuál pido memoria
 * \def		SE_DISCK	20		Parámetro de prefiltrado
 * \def		SE_DISCK_2	3		Parámetro de prefiltrado
 * \def		ANCHOR_X	1		Parámetro de prefiltrado
 * \def		ANCHOR_Y	1		Parámetro de prefiltrado
 * \def		KERNEL		3		Parámetro de prefiltrado
 * \def		XORDER		1		Parámetro de prefiltrado
 * \def		YORDER		0		Parámetro de prefiltrado
 * \def		rho_res 	1		Resolución de rho para la transformada de hough
 * \def		theta_res	CV_PI/60	Resolución de theta para la transformada de hough
 * \def		threshold	30		Valor minimo que debe alcanzar la votación dentro de la transformada de Hough
 * \def		min_length	0		Longitud minima del segmento a detectar
 * \def		max_gap		0		Salto maximo entre segmentos perteneciente a la misma recta
 * \def 	COND_CENTRO	(theta < 0+0.3 || theta >3.14-0.3)		Condición que debe cumplir para conciderarla como linea del centro 
 * \def		COND_IZQ	(theta  > 0+0.3 && theta<1.3)			Condición que debe cumplir para conciderarla como linea izquierda
 * \def 	COND_DER	(theta < 3.14-0.3 && theta>2)			Condición que debe cumplir para conciderarla como linea derecha
 **/

#define		BGR		1
#define		ANCHO_MAX	8
#define		ANCHO_MIN	3
#define		CANT_FILAS	4
#define		PI		3.14159
#define		MAX_NUM_LINES	15
#define		SE_DISCK	20
#define		SE_DISCK_2	3
#define		ANCHOR_X	1
#define		ANCHOR_Y	1
#define		KERNEL		3
#define		XORDER		1
#define		YORDER		0

#define 	COND_CENTRO	(theta < 0+0.3 || theta >3.14-0.3)  
#define		COND_IZQ	(theta  > 0+0.3 && theta<1.3)
#define 	COND_DER	(theta < 3.14-0.3 && theta>2)


#define		rho_res 	1
#define		theta_res	CV_PI/60
#define		threshold	30
#ifdef PROBABILISTICO
  #define		min_length	50	
  #define		max_gap		20
#else
  #define		min_length	0	
  #define		max_gap		0
#endif


/**
 * \struct	Punto
 * \brief	Punto de coordentadas X e Y
 * \details	Estructura que sirve para representar un pixel en una imágen
 * \date 	20/07/2014
 **/
typedef struct punto {
  
  int x;
  int y;
  
} Punto;


/**
 * \struct	Linea
 * \brief	Estructura que contiene todos los datos de una linea
 * \details	Para representar una línea se precisa de dos puntos o de una posicion y un ángulo
 * \var		
 * 		punto1: Punto inicial de la recto
 * 		punto2: Punto final de la recto
 * 		theta: Ángulo (en grados) de la recta
 * 		rho: Posicion de la recta
 * \date 	20/07/2014
 **/
typedef struct Linea {
  
  Punto punto1;
  Punto punto2;
  float rho;
  float theta;
  
} Linea;


/**
 * \fn		ImagesAndLines
 * \brief	La función detecta las líneas del asfalto
 * \arg		Se le pasa por argumento un puntero a la frame a analizar y vector donde se guardarán las lineas. 
 * \return	La función devuelve la ubicación de las lineas detecatadas (3 lineas), almacenandolas en un vector de estructura "Linea" con memoria suficiente
 * \author	Nicolás Linale -- nicolaslinale@gmail.com - Andrés Demski -- andresdemski@gmail.com
 * \date 	24/07/2014
 **/

/**
 * \fn		Filtro_Lineas
 * \brief	Función que valida las lineas arrojadas por Hough
 * \arg		Se pasa como argumento un puntero al Frame, las lineas a validar y la cantidad total de lineas
 * \return	Devuelve las lineas validadas y la cantidad de lineas validadas (ambos datos pasados por argumento)
 * \author	Nicolás Linale -- nicolaslinale@gmail.com - Andrés Demski -- andresdemski@gmail.com
 * \date 	20/07/2014
 **/

/**
 * \fn		AnalisisFilas
 * \brief	Devuelve para 4 filas distintas en qué posición en X puede haber lineas de un espezor definido
 * \arg		Se pasa como argumento el Frame (black & white) y las filas a analizar (F)
 * \return	La función devuelve los máximos de cada fila (Max) y su correspondiente número de elementos (SizeM)
 * \author	Nicolás Linale -- nicolaslinale@gmail.com - Andrés Demski -- andresdemski@gmail.com
 * \date 	20/07/2014
 **/

/**
 * \fn		Analisis1Linea
 * \brief	Devuelve para una sola fila en qué posicion en X puede haber lineas de un espezor definido
 * \arg		Se pasa como argumento la fila (F) a analizar
 * \return	Devuelve el vector de máximos (Max) y la cantidad de ellos (SizeM)
 * \author	Nicolás Linale -- nicolaslinale@gmail.com - Andrés Demski -- andresdemski@gmail.com
 * \date 	20/07/2014
 **/

/**
 * \fn		Corroborar_Linea
 * \brief	Verifica si las lineas de Hough coinciden con los máximos
 * \arg		Se pasa como argumento las líneas, los máximos, la cantidad de maximos y la Fila.
 * \return	La función devuelve un 1 en caso de encontrar coincidencia y un 0 en caso contrario.
 * \author	Nicolás Linale -- nicolaslinale@gmail.com
 * \date 	21/07/2014
 **/

/**
 * \fn		Lineas_Xvalues
 * \brief	Función que obtiene el valor en el eje X de las lineas para cada Fila
 * \arg		Se pasa como argumento una linea y una Fila
 * \return	La función devuelve la coordenada en el eje X de la linea detectada
 * \author	Nicolás Linale -- nicolaslinale@gmail.com - Andrés Demski -- andresdemski@gmail.com
 * \date 	21/07/2014
 **/

/**
 * \fn		CropImage
 * \brief	Función que recorta la imagen y se queda solo con la parte útil
 * \arg		Se pasa como argumento la imagen y los límites de interés
 * \return	La función devuelve la imagen recortada
 * \author	Andrés Demski -- andresdemski@gmail.com
 * \date 	24/07/2014
 **/

/**
 * \fn		PrintLines
 * \brief	La función muestra las líneas detectadas sobre la imagen
 * \arg		Se le pasa la imagen, las lineas y el color en el que se desean las mismas
 * \return	No retorna nada
 * \author	Andrés Demski -- andresdemski@gmail.com
 * \date 	24/07/2014
 **/

/**
 * \fn		Validar_Lineas
 * \brief	Valida las lineas utilizando información adquirida anteriormente
 * \arg		Se le pasa las lineas que queres validar y el vector donde se desea el resultado de las rectas validadas
 * \return	No retorna nada
 * \author	Andrés Demski -- andresdemski@gmail.com
 * \date 	26/07/2014
 **/

void		ImagesAndLines		(IplImage**, Linea*);
void		Filtro_Lineas		(IplImage*, Linea*, Linea*);
void		AnalisisFilas		(IplImage*, int, int, int, int, int**, int**, int**, int**, int*, int*, int*, int*);
void		Analisis1Linea		(CvMat*, int**, int*);
int		Corroborar_Linea	(Linea*, int*, int, int);
int		Lineas_Xvalues		(Linea*, int);
IplImage*	CropImage 		(IplImage* image, int x1, int y1, int ancho, int alto);
void 		PrintLines 		(IplImage * img, Linea, int R , int G , int B);
void 		Validar_Lineas		(Linea* Line, Linea* Line_ret);
