#include"engine.h"

int PWMPin = 2;		//2-13引擎Pin
int SteerPin = 3;	//2-13舵机Pin
int PWMValue = 0;	//0-1000
int keyV = 50;
int gear = 0;		//初始化挡位

int main(int argc, char** argv) {
	init();
	if (argc == 2) {
		if (strcmp(argv[1], "twice")==0) { //电调每次启动通电后需要初始化，保持通电就不需要重复初始化
			control(PWMValue);
				return 0;
		}
	}
		rangestd();
		control(PWMValue);
		return 0;
}
