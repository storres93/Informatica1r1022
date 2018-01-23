/**
 * \fn		PrintLines
 * \brief	La función muestra las líneas detectadas sobre la imagen
 * \arg		Se le pasa la imagen, las lineas y el color en el que se desean las mismas
 * \return	No retorna nada
 * \author	Andrés Demski -- andresdemski@gmail.com
 * \date 	24/07/2014
 **/

#include "Header.h"

void PrintLines (IplImage * img, Linea lineas, int R , int G , int B)
{
    CvPoint pt1, pt2;
    pt1.x = lineas.punto1.x;
    pt1.y = lineas.punto1.y;
    pt2.x = lineas.punto2.x;
    pt2.y = lineas.punto2.y;
    cvLine(img, pt1, pt2, CV_RGB(R,G,B), 3, 8, 0);
  
    return;
}

