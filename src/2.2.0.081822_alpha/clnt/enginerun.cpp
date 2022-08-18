#include"Engine.h"
int PWMPin = 2;	//电机pin
int SteerPin = 3;	//舵机pin
int PWMValue = 0;	
int keyV = 50;
int gear = 1;	//gear共有5档,1-5

int enginerun(const char* temsg) {
	cout << "无刷电机第一次开机请推到最高油门2s,然后拉到最低油门。此时可以听到滴滴两声表示电机已经解锁" << endl;
	return control(temsg);
}
