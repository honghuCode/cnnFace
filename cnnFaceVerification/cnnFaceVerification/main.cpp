#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <opencv2/opencv.hpp> 

#include "cnnFace.h"

using namespace std;
using namespace cv;

void main(int argc, char* argv)
{
	Mat imgFace1 = imread("D:\\test\\Aaron_Peirsol_0001.bmp", CV_LOAD_IMAGE_GRAYSCALE);
	Mat imgFace2 = imread("D:\\test\\Aaron_Peirsol_0002.bmp", CV_LOAD_IMAGE_GRAYSCALE);
	char* modelPath = "D:\\code\\cnnFace\\model\\cnnFace.bin";

	cnnFace cnn(imgFace1, imgFace2, modelPath, 44);
	if ( cnn.cnnFaceInit() != 0) {
		return;
	}

	cnn.faceVerification();
	cout << "The score is " << cnn.getScore() << endl;

}
