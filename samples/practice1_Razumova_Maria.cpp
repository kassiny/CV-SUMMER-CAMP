#include <iostream>
#include <string>

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "filter.h"

using namespace cv;
using namespace std;

const char* cmdAbout = "Sample of OpenCV usage. ";

const char* cmdOptions =
"{ i  image         | <none> | image to process        }"
"{ w  width         | <none> | width for image resize  }"
"{ h  height        | <none> | height for image resize }"
"{ q ? help usage   | <none> | print help message      }";

int main(int argc, char** argv)
{
    // Process input arguments
    CommandLineParser parser(argc, argv, cmdOptions);
    parser.about(cmdAbout);

    if (parser.has("help"))
    {
        parser.printMessage();
        return 0;
    }
    if (!parser.check())
    {
        parser.printErrors();
        return 0;
    }
    
    // Load image
    String imgName(parser.get<String>("image"));
	Mat image = imread(imgName);
    
    // Filter image
	GrayFilter grayFilter;
	Mat grayImg = grayFilter.ProcessImage(image);

    // Show image
	namedWindow("Show Image", WINDOW_NORMAL);
	imshow("Show Image", grayImg);
	waitKey();

	// Filter image
	ResizeFilter resizeFilter(parser.get<int>("width"), parser.get<int>("height"));
	Mat resizedImage = resizeFilter.ProcessImage(image);

    // Show image
	imshow("Show Image", resizedImage);
	waitKey();
    
    
    
    return 0;
}
