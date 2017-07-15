#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main( )
{
    VideoCapture cam;

    if(!cam.open(0))
        return 0;

    while(true){

        Mat srcVideoFrame, outVideoFrame, grayFrame;

        cam >> srcVideoFrame;

        if(srcVideoFrame.empty())
            break;

        namedWindow( "Imagem Original", CV_WINDOW_AUTOSIZE );
        imshow( "Imagem Original", srcVideoFrame);   //shows original video

        cvtColor(srcVideoFrame, grayFrame, CV_BGR2GRAY);

        Canny(grayFrame, outVideoFrame, 50, 150, 3);

        namedWindow("Imagem com Canny Edge", CV_WINDOW_AUTOSIZE);
        imshow("Imagem com Canny Edge", outVideoFrame); //shows filtered image

        if(waitKey(10) == 27)
            break;
    }

    return 0;
}
