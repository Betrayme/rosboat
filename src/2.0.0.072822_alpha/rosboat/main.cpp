#include"engine.h"

int PWMPin = 2;		//2-13����Pin
int SteerPin = 3;	//2-13���Pin
int PWMValue = 0;	//0-1000
int keyV = 50;
int gear = 0;		//��ʼ����λ

int main(int argc, char** argv) {
	init();
	if (argc == 2) {
		if (strcmp(argv[1], "twice")==0) { //���ÿ������ͨ�����Ҫ��ʼ��������ͨ��Ͳ���Ҫ�ظ���ʼ��
			control(PWMValue);
				return 0;
		}
	}
		rangestd();
		control(PWMValue);
		return 0;
}
