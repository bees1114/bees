#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
 
int main()
{
	IplImage *img;
	IplImage *modifyImage;
	IplImage *modifiedbyOpenCV = NULL;
	float x1, x2, y1, y2;
	float w1, w2, w3, w4, a, b, p, q;
	float M, N;
	int i, j, k;
	CvSize size;
	
	img = cvLoadImage("images.jpg", CV_LOAD_IMAGE_COLOR);
    if (img == NULL)
    {
        std::cout << "[!] You can NOT see the cat!" << std::endl;
        return -1;
    }

	printf("Input Target Resolution M`, N`:\n");
	scanf("%f %f", &M, &N);
	size.height = img->height * N;
	size.width = img->width * M;
	modifyImage = cvCreateImage(size, img->depth, img->nChannels);
	modifiedbyOpenCV = cvCreateImage(size, img->depth, img->nChannels);
	for(i = 0; i < size.height; i++) {
		for(j = 0; j < size.width; j++) {
			x1 = j / M; x2 = x1 + 1;
			y1 = i / N; y2 = y1 + 1;
			
			a = ((M*(int)x2-M*(int)x1)*(N*(int)y2-N*(int)y1));
			for(k = 0; k < modifyImage->nChannels; k++) {
				p =  ((float)((M*((int)x2)-j)*(N*((int)y2)-i)))/a*(unsigned char)img->imageData[((int)y1)*img->widthStep + ((int)x1)*img->nChannels + k];
				p += ((float)(j-(M*((int)x1))*(N*((int)y2)-i)))/a*(unsigned char)img->imageData[((int)y1)*img->widthStep + ((int)x2)*img->nChannels + k];
				p += ((float)((M*((int)x2)-j)*(i- N*((int)y1))))/a*(unsigned char)img->imageData[((int)y2)*img->widthStep + ((int)x1)*img->nChannels + k];
				p += ((float)((j-M*((int)x1))*(i- N*((int)y1))))/a*(unsigned char)img->imageData[((int)y2)*img->widthStep + ((int)x2)*img->nChannels + k];
				modifyImage->imageData[i*modifyImage->widthStep + j*modifyImage->nChannels+k]=p;
			}
			
		}

	}
	cvResize(img, modifiedbyOpenCV, CV_INTER_LINEAR);

    cvShowImage("OriginalImage", img);
	cvShowImage("ModifiedImage", modifyImage);
	cvShowImage("ModifiedbyOpenCV", modifiedbyOpenCV);
    cvWaitKey(0);
    cvDestroyWindow("EXAMPLE01");
    return 0;
}
