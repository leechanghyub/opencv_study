#include <opencv2\opencv.hpp>
#include <math.h>
#include <cstdlib>
#include <time.h>
using namespace std;
using namespace cv;
void put_string(Mat &frame, string text,Point pt,int value) {
	text += to_string(value);
	int font = FONT_HERSHEY_SIMPLEX;
	putText(frame, text, pt, font, 0.7, Scalar(120, 200, 90), 2);
}
int main() {
	VideoCapture capture(0);
	if (!capture.isOpened()) {
		cout << "카메라가 연결되지 않았습니다." << endl;
		exit(1);
	}

	cout << "너비" << capture.get(CAP_PROP_FRAME_WIDTH) << endl;
	cout << "높이" << capture.get(CAP_PROP_FRAME_HEIGHT) << endl;
	cout << "노출" << capture.get(CAP_PROP_EXPOSURE) << endl;
	cout << "밝기" << capture.get(CAP_PROP_BRIGHTNESS) << endl;

	for (;;) {
		Mat frame;
		capture.read(frame);
		put_string(frame, "EXPOS : ", Point(10, 40), capture.get(CAP_PROP_EXPOSURE));
		imshow("카메라영상", frame);
		if (waitKey(30) >= 0) break;
	}
	waitKey(0);
	return 0;
}