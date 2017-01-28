#pragma comment ( lib, "opencv_contrib2411d.lib" )
#pragma comment ( lib, "opencv_core2411d.lib" )
#pragma comment ( lib, "opencv_features2d2411d.lib" )
#pragma comment ( lib, "opencv_flann2411d.lib" )
#pragma comment ( lib, "opencv_gpu2411d.lib" )
#pragma comment ( lib, "opencv_highgui2411d.lib" )
#pragma comment ( lib, "opencv_imgproc2411d.lib" )
#pragma comment ( lib, "opencv_legacy2411d.lib" )
#pragma comment ( lib, "opencv_ml2411d.lib" )
#pragma comment ( lib, "opencv_nonfree2411d.lib" )
#pragma comment ( lib, "opencv_objdetect2411d.lib" )
#pragma comment ( lib, "opencv_ocl2411d.lib" )
#pragma comment ( lib, "opencv_photo2411d.lib" )
#pragma comment ( lib, "opencv_stitching2411d.lib" )
#pragma comment ( lib, "opencv_superres2411d.lib" )
#pragma comment ( lib, "opencv_ts2411d.lib" )
#pragma comment ( lib, "opencv_video2411d.lib" )

#pragma comment ( lib, "opencv_calib3d2411d.lib" )
#pragma comment ( lib, "opencv_videostab2411d.lib" )

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#define IMAGE "»çÁø.jpg"

#define G_HEIGHT 300
#define G_WIDTH 2
#define G_WEIGHT 50

#define MAX_SCALE 256

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
   Mat oriImg;
   Mat grayImg;
   Mat eqImg;
   oriImg = imread(IMAGE);

   if (oriImg.empty())
   {
      fprintf(stderr, "imread() Error, %d line in %s", __LINE__, __FILE__);
      exit(1);
   }

   cvtColor(oriImg, grayImg,COLOR_BGR2GRAY);
   cvtColor(oriImg, eqImg, COLOR_BGR2GRAY);

   //Get Original Histogram
   unsigned int hist[MAX_SCALE] = { 0 };
   for (int i = 0; i < grayImg.cols; i++)
   {
      for (int j = 0; j < grayImg.rows; j++)
      {
         hist[grayImg.data[i + j* grayImg.cols]]++;
      }
   }

   //Eqaulization
   unsigned int sum[MAX_SCALE] = { 0 };
   unsigned int N[MAX_SCALE] = { 0 };
   unsigned char histMax = 0;
   unsigned int eqHist[MAX_SCALE] = { 0 };
   for (int i = MAX_SCALE - 1; i > -1; i--)
   {
      if (hist[i] != 0)
      {
         histMax =i;
         break;
      }
   }//get Intensity Max
   for (int i = 0; i < MAX_SCALE; i++)
   {
      for (int j = 0; j < i; j++)
      {
         sum[i] += hist[j];
      }
      N[i] = sum[i] * 255 / (grayImg.rows * grayImg.cols);
   }
   for (int i = 0; i < grayImg.cols; i++)
   {
      for (int j = 0; j < grayImg.rows; j++)
      {
         int k = grayImg.data[i + j* grayImg.cols];
         eqImg.data[i + j*grayImg.cols] = N[k];
         eqHist[N[k]]++;
      }
   }

   //Rescale for Drawing Graph
   double gHist[MAX_SCALE] = { 0 }; // Rescaled Array of Original Histogram
   double gN[MAX_SCALE] = { 0 }; // Rescaled Array of Equalized Histogram
   double gEqHist[MAX_SCALE] = { 0 };
   for (int i = 0; i < MAX_SCALE; i++)
   {
      gHist[i] = (double)hist[i] * G_WEIGHT / (grayImg.rows*grayImg.cols);
      gN[i] = (double)N[i] * G_WEIGHT / (grayImg.rows*grayImg.cols);
      gEqHist[i] = (double)eqHist[i] * G_WEIGHT / (grayImg.rows*grayImg.cols);
   }

   // Draw Graph
   Mat graph(G_HEIGHT*2, MAX_SCALE * G_WIDTH, CV_8UC3,Scalar(0,0,0));
      for (int i = 0; i < MAX_SCALE; i++)
   {
      line(graph, Point(i*G_WIDTH, G_HEIGHT), Point(i*G_WIDTH, G_HEIGHT - (gHist[i] * G_HEIGHT)),Scalar(0,0,255),1);
      //line(graph, Point((i - 1)*G_WIDTH, G_HEIGHT - (gN[i - 1] * G_HEIGHT)), Point(i*G_WIDTH, G_HEIGHT - (gN[i] * G_HEIGHT)), Scalar(0, 255, 0), 2);
      line(graph, Point(i*G_WIDTH, G_HEIGHT), Point(i*G_WIDTH, G_HEIGHT + (gEqHist[i] * G_HEIGHT)), Scalar(0, 255, 0), 1);
   }

   imshow("Gray Histogram",graph);
   imshow("Original Image", oriImg);
   imshow("Gray Image", grayImg);
   imshow("Equalized Gray Image", eqImg);
   waitKey();
   return 0;
}