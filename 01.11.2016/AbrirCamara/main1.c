#include <stdio.h>
#include <stdlib.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>


int main (void)
{
	int key = 0;
	IplImage *img;
	IplImage *img_gray = NULL;
	IplImage *img_bordes = NULL;
	CvSize img_size;

	IplImage *frame= NULL;
	CvCapture* capture;
	capture = cvCaptureFromCAM( 0 );
	cvSetCaptureProperty(capture, CV_CAP_PROP_FPS, 31.0);

	do {
		frame = cvQueryFrame( capture );
		cvShowImage("frame", frame);
	} while(key =cvWaitKey(1));

	return 0;
}


