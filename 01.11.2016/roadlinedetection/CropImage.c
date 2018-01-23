/**
 * \fn		CropImage
 * \brief	Función que recorta la imagen y se queda solo con la parte útil
 * \arg		Se pasa como argumento la imagen y los límites de interés
 * \return	La función devuelve la imagen recortada
 * \author	Andrés Demski -- andresdemski@gmail.com
 * \date 	24/07/2014
 **/

#include "Header.h"

IplImage*  CropImage (IplImage* image,int x,int y,int width, int height)
{
    IplImage *Cropped;
    CvRect region;
    
    region.x=x;
    region.y=y;
    region.width=width;
    region.height=height;
    
    cvSetImageROI((IplImage*)image, region);

    Cropped = cvCreateImage(cvGetSize(image), image->depth , image->nChannels);
    cvCopy(image, Cropped,NULL);

    cvResetImageROI((IplImage*)image);
    
    return Cropped;
  
}

