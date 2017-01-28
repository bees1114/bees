#include <stdio.h>
#include <opencv\cv.h>
#include <opencv\highgui.h>

#ifdef _DEBUG
#pragma comment(lib, "opencv_core2411d.lib")
#pragma comment(lib, "opencv_highgui2411d.lib")
#pragma comment(lib, "opencv_imgproc2411d.lib")
#pragma comment(lib, "opencv_video2411d.lib")
#else
#pragma comment(lib, "opencv_core2411.lib")
#pragma comment(lib, "opencv_highgui2411.lib")
#pragma comment(lib, "opencv_imgproc2411.lib")
#pragma comment(lib, "opencv_video2411.lib")
#endif

int main(int argc, char * argv[])
{
	IplImage* img = cvLoadImage("1.jpg",CV_LOAD_IMAGE_COLOR);

	cvNamedWindow("Hello");
	for(int i = 0; i < img->height; i++)
	{
		for(int j = 0; j < img->width; j++)
		{
			img->imageData[i * img->widthStep + j + 0] = 255;//Blue;
			img->imageData[i * img->widthStep + j + 1] = 255;//Green
			img->imageData[i * img->widthStep + j + 2] = 255;//Red
			cvShowImage("Hello",img);
			cvWaitKey(1);
		}
	}

	cvWaitKey();
	return 0;
}
