#include <iostream>
using namespace std;

int hour, minute, second;

void addHour(int addition) {
	if (hour + addition >= 24) {
		hour = (hour + addition) % 24;
	}
	else {
		hour = hour + addition;
	}
}

void addMinute(int addition) {
	if (minute + addition >= 60) {
		addHour(1);
		minute = minute + addition - 60;
	}
	else {
		minute = minute + addition;
	}
}

void addSecond(int addition) {
	if (second + addition >= 60) {
		addMinute(1);
		second = second + addition - 60;
	}
	else {
		second = second + addition;
	}
}

int main() {
	cin >> hour >> minute >> second;
	int d; cin >> d;

	// 필요한 시간을 시간 분 초 단위로 변환
	int add_hour = d / 3600;
	int add_minute = (d - add_hour * 3600) / 60;
	int add_second = (d - add_hour * 3600 - add_minute * 60);

	addHour(add_hour);
	addMinute(add_minute);
	addSecond(add_second);

	cout << hour << " " << minute << " " << second << endl;
	return 0;
}