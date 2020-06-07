// ConsoleApplication1.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.

#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>
#include <string>

using namespace std;
using namespace cv;

void main()
{
    // �̹��� â 3���� ���
    namedWindow("Origin", WINDOW_AUTOSIZE);
    namedWindow("Noise", WINDOW_AUTOSIZE);
    namedWindow("Filter", WINDOW_AUTOSIZE);

    Mat inputImg;  // ���� �̹���
    Mat noiseImg; // ����� ������ �̹���
    Mat filterImg;   // ���͸� �̹���

    // ������ �о���� ���̾�α� ���
    string filename = "image.jpg";

    // �̹��� �ҷ�����
    inputImg = imread(filename, IMREAD_COLOR);
    if (inputImg.empty()) {
        cout << "Reading File is Unavailable" << endl;
    }

    noiseImg = inputImg.clone();

    // ������ Noise ����
    for (int i = 0; i < 1000; i++)
    {
        int x = rand() % noiseImg.rows;
        int y = rand() % noiseImg.cols;
        int c = rand() % 256;

        noiseImg.at<Vec3b>(x, y)[0] = c;
        noiseImg.at<Vec3b>(x, y)[1] = c;
        noiseImg.at<Vec3b>(x, y)[2] = c;
    }

    // Median Filer ����
    medianBlur(noiseImg, filterImg, 3);

    imshow("Origin", inputImg);
    imshow("Noise", noiseImg);
    imshow("Filter", filterImg);

    // �̹��� ����
    vector params;
    params.push_back(CV_IMWRITE_JPEG_QUALITY);
    params.push_back(95);
    imwrite(filename + "_Original", inputImg, params);
    imwrite(filename + "_Noised", noiseImg, params);
    imwrite(filename + "_Filtered", filterImg, params);
}