// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <string>

#include <timer.h>
#include <video_processing.h>

using namespace std;

void main()
{
	//소수점 자리수 조절
	cout << fixed;
	cout.precision(2);

	// 파일을 읽어오는 다이얼로그 출력
	string filename = "resources/test_video.avi";

	cout << "Start Video Processing..." << endl;

	// 시간 측정 시작
	double start = time.time();
	// 미디안 필터 적용 시작
	applyMedianFilter(filename);

	cout << "Total Video Processing Time : " << time.time() - start << "s" << endl;
	cin >> "Press Any Key To Exit";

}