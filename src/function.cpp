#include"engine.h"
void init()
{
	if (wiringPiSetup() == -1) {
		printf("init error!\n");
	}
}

void pwm(int PMMPin, int PWMValue) //ģ��pwm�ź�����10ms ,Ƶ��100HZ
{
	PWMValue += 1000;
	digitalWrite(PWMPin, HIGH);
	delayMicroseconds(PWMValue); //������ͣ ��λ΢��
	digitalWrite(PWMPin, LOW);
	delayMicroseconds(10000 - PWMValue);
}

void rangestd() //��ʼ�����
{
	pinMode(PWMPin, OUTPUT);

	for (int i = 0; i <= 220; i++) {
		pwm(PWMPin, 1000); //��ߵ� ��Ӧ�ߵ�ƽ2ms
	}
	for (int i = 0; i <= 110; i++) {
		pwm(PWMPin, 0);  //0�� ��Ӧ�ߵ�ƽ1ms
	}
}

void control(int PWMValue) //���ƺ���
{
	while (1)
	{
		keyV = getch();
		if (keyV == UP) {
			pwm(PWMPin, 200 * gear);
		}
		else if (keyV == LEFT)
		{

		}
		else if (keyV == RIGHT)
		{

		}
		else if (keyV == LUP || UUP) {
			gear++;
			if (gear > 5)
				gear = 5;
		}
		else if (keyV == LDOWN || UDOWN) {
			gear--;
			if (gear < 0)
				gear = 0;

		}
		else if (keyV == CANCEL)
		{
			return;
		}
		else
		{
			pwm(PWMPin, PWMValue);
		}
	}
}

int getch(void) //getch()���� Linux����
{
	struct termios tm, tm_old;
	int fd = 0, ch;

	if (tcgetattr(fd, &tm) < 0) {
		return -1;
	}

	tm_old = tm;
	cfmakeraw(&tm);
	if (tcsetattr(fd, TCSANOW, &tm) < 0) {
		return -1;
	}

	ch = getchar();
	if (tcsetattr(fd, TCSANOW, &tm_old) < 0) {
		return -1;
	}

	return ch;
}
