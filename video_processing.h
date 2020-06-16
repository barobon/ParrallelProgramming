#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>
#include <string>
#include <timer.h>

using namespace std;
using namespace cv;

//필터를 적용하는 핵심 함수
void applyMedianFilter(file_name) {
    Timer timer = new Timer();  //타이머 객체 생성
    Mat frame;  //프레임 이미지 변수 공간 선언

    VideoCapture inputVid(file_name);    //영상 읽어오기

    // 노이즈 영상 생성 여부 묻기
    char usrCmd;

    while (1) {
        cout << "Do you want to create a new noise added video? (Y/N)" << endl;
        cin >> ">>" >> usrCmd >> endl;
        switch (usrCmd) {
        case 'Y':
        case 'y':
            // 노이즈 비디오 생성
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

    // 필터 비디오 생성
    file_name = "resources/test_video_noise_added.avi";
    timer.start();
    cout << "\t Filtering Video...";
    while (inputVid.isOpened())
        noiseVideo(inputVid)
    cout << "done (" << timer.end() << "s)" << endl;
}

//노이즈 영상을 생성하는 함수
void noiseVideo(file_name) {
    timer.start();

    cout << "\t Making Noise Video...";

    while (file_name.isOpened()) {

    }

    cout << "done (" << timer.end() << "s)" << endl;
}

//영상에 필터를 적용하는 함수
void filterVideo(noise_video) {

}