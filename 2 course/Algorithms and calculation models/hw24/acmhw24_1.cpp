#include <iostream>
#include <opencv2/opencv.hpp>
//using namespace cv;

#define MAX_FACES_COUNT 8

#define PROCESSING_IMAGE_FROM_FILE

void detectFaces(cv::Mat * image, cv::CascadeClassifier * face_cascade, std::vector<cv::Rect> * faces) {
    if (!image || !face_cascade || face_cascade->empty() || !faces) {
        return;
    }
    face_cascade->detectMultiScale(*image, *faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
    for (int index = 0; index < faces->size() && index < MAX_FACES_COUNT; ++index) {
        ellipse(
            *image,
            cv::Point((*faces)[index].x + (*faces)[index].width / 2, (*faces)[index].y + (*faces)[index].height / 2),
            cv::Size((*faces)[index].width / 2, (*faces)[index].height / 2),
            0,
            0,
            360,
            cv::Scalar(255, 0, 255),
            4,
            8,
            0);
    }
}

int main() {
    cv::CascadeClassifier face_cascade;
    if (!face_cascade.load("haarcascade_frontalface_alt.xml")) {
        std::cout << "Could not open haarcascade_frontalface_alt.xml" << std::endl;
        std::cout << "Copy this file and try again" << std::endl;
        return -1;
    }

    cv::Mat image;
    std::vector<cv::Rect> faces;

#ifdef PROCESSING_IMAGE_FROM_FILE
    image = cv::imread("image.jpg");
    if (!image.data) {
        std::cout << "Could not open or find the image" << std::endl;
        std::cout << "Copy the image file and try again" << std::endl;
        return -1;
    }

    detectFaces(&image, &face_cascade, &faces);

    //cv::imshow("Detected Face", image);
    //cv::waitKey(0);
    cv::imwrite("image_out.jpg", image);
#else
    cv::VideoCapture cap(0);
    while (true) {
        cap >> image;

        detectFaces(&img, &face_cascade, &faces);

        cv::imshow("Detected Face", image);
        cv::waitKey(1);
    }
#endif

#ifdef __linux__ 
    std::cout << "Press any key to continue . . . " << std::endl;
    (void)getchar();
#elif defined(_WIN32)    
    system("pause");
#else
#endif
    
     return 0;
}
