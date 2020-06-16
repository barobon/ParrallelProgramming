// ConsoleApplication1.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.

#include <iostream>
#include <string>

#include <timer.h>
#include <video_processing.h>

using namespace std;

void main()
{
	//�Ҽ��� �ڸ��� ����
	cout << fixed;
	cout.precision(2);

	// ������ �о���� ���̾�α� ���
	string filename = "resources/test_video.avi";

	cout << "Start Video Processing..." << endl;

	// �ð� ���� ����
	double start = time.time();
	// �̵�� ���� ���� ����
	applyMedianFilter(filename);

	cout << "Total Video Processing Time : " << time.time() - start << "s" << endl;
	cin >> "Press Any Key To Exit";

}