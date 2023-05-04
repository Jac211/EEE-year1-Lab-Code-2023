#include <stdio.h>
#include "opencv2/opencv.hpp"

void setup(void)
{
    cv::VideoCapture cap(0); // open the default camera
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 320);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 240);
}

int main(int argc, char** argv)
{
    setup();

    cv::namedWindow("Photo", cv::WINDOW_NORMAL);

    while (true)
    {
        cv::Mat frame;
        cv::VideoCapture cap(0);

        if (!cap.isOpened())
        {
            frame = cv::imread("OpenCV_Logo.png");
        }
        else
        {
            cap >> frame;
        }

        cv::imshow("Photo", frame);
        int key = cv::waitKey(1);

        if (key == 27) // ESC key pressed
        {
            break;
        }
    }

    cv::destroyAllWindows();
    return 0;
}




