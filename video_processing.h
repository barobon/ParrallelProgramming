#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>
#include <string>
#include <timer.h>

using namespace std;
using namespace cv;

//���͸� �����ϴ� �ٽ� �Լ�
void applyMedianFilter(file_name) {
    Timer timer = new Timer();  //Ÿ�̸� ��ü ����
    Mat frame;  //������ �̹��� ���� ���� ����

    VideoCapture inputVid(file_name);    //���� �о����

    // ������ ���� ���� ���� ����
    char usrCmd;

    while (1) {
        cout << "Do you want to create a new noise added video? (Y/N)" << endl;
        cin >> ">>" >> usrCmd >> endl;
        switch (usrCmd) {
        case 'Y':
        case 'y':
            // ������ ���� ����
            noiseVideo(inputVid);
            break;

        case 'N':
        case 'n':
            break;
        default:
            cout << "WARNING: Invalid Input" << endl;
            continue;
        }
    }

    // ���� ���� ����
    file_name = "resources/test_video_noise_added.avi";
    timer.start();
    cout << "\t Filtering Video...";
    while (inputVid.isOpened())
        noiseVideo(inputVid)
    cout << "done (" << timer.end() << "s)" << endl;
}

//������ ������ �����ϴ� �Լ�
void noiseVideo(file_name) {
    timer.start();

    cout << "\t Making Noise Video...";

    while (file_name.isOpened()) {

    }

    cout << "done (" << timer.end() << "s)" << endl;
}

//���� ���͸� �����ϴ� �Լ�
void filterVideo(noise_video) {

}