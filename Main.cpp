// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>
#include <string>

using namespace std;
using namespace cv;

void main()
{
    // 이미지 창 3개를 출력
    namedWindow("Origin", WINDOW_AUTOSIZE);
    namedWindow("Noise", WINDOW_AUTOSIZE);
    namedWindow("Filter", WINDOW_AUTOSIZE);

    Mat inputImg;  // 원본 이미지
    Mat noiseImg; // 노이즈를 생성한 이미지
    Mat filterImg;   // 필터링 이미지

    // 파일을 읽어오는 다이얼로그 출력
    string filename = "image.jpg";

    // 이미지 불러오기
    inputImg = imread(filename, IMREAD_COLOR);
    if (inputImg.empty()) {
        cout << "Reading File is Unavailable" << endl;
    }

    noiseImg = inputImg.clone();

    // 임의의 Noise 생성
    for (int i = 0; i < 1000; i++)
    {
        int x = rand() % noiseImg.rows;
        int y = rand() % noiseImg.cols;
        int c = rand() % 256;

        noiseImg.at<Vec3b>(x, y)[0] = c;
        noiseImg.at<Vec3b>(x, y)[1] = c;
        noiseImg.at<Vec3b>(x, y)[2] = c;
    }

    // Median Filer 적용
    medianBlur(noiseImg, filterImg, 3);

    imshow("Origin", inputImg);
    imshow("Noise", noiseImg);
    imshow("Filter", filterImg);

    // 이미지 저장
    vector params;
    params.push_back(CV_IMWRITE_JPEG_QUALITY);
    params.push_back(95);
    imwrite(filename + "_Original", inputImg, params);
    imwrite(filename + "_Noised", noiseImg, params);
    imwrite(filename + "_Filtered", filterImg, params);
}