//cmake .
//make
//./DisplayImage bird.jpeg

//path /usr/include/opencv2/opencv.hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
 int main (int argc, char **argv)
 {
     if (argc != 2)
     {
         printf ("DisplayImage.out <Image_Path>\n");
         return -1;
     }
     
     Mat image;
     image = imread(argv[1], 1);

     if (!image.data)
     {
        printf("No image data\n");
        return -1;
     }

    namedWindow ("Display image", WINDOW_AUTOSIZE );
    imshow("Display image", image); 

    waitKey(0);
    return 0;


 }
/*
message (STATUS     "version: ${OpenCV_VERSION}")
message (STATUS     "libraries: ${OpenCV_LIBS}")
message (STATUS     "include path: ${OpenCV_INCLUDE_DIRS}")
*/
