#include"Engine.h"
void init()
{
	if (wiringPiSetup() == -1) {
		printf("engine:init error!\n");
	}
}

void pwm(int PMMPin, int PWMValue) //一周期10ms
{
	PWMValue += 1000;
	digitalWrite(PWMPin, HIGH);
	delayMicroseconds(PWMValue);
	digitalWrite(PWMPin, LOW);
	delayMicroseconds(10000 - PWMValue);
}

// void rangestd() //解锁电机
// {
// 	pinMode(PWMPin, OUTPUT);

// 	for (int i = 0; i <= 220; i++) {
// 		pwm(PWMPin, 1000); 
// 	}
// 	for (int i = 0; i <= 110; i++) {
// 		pwm(PWMPin, 0);  
// 	}
// }

int control(const char* temsg)
{
	string Temsg(temsg);
	while (1)
	{
		for (auto i = Temsg.begin();i != Temsg.end();i++)
		{
			keyV = (int)*i;
			if (keyV == UP)
			{
				pwm(PWMPin, 200 * gear);
				turn(ANGLE90);
				continue;
			}
			else if (keyV == LEFT)
			{
				turn(ANGLE0);
				continue;
			}
			else if (keyV == RIGHT)
			{
				turn(ANGLE180);
				continue;
			}
			else if (keyV == LUP || UUP) {
				turn(ANGLE90);
				if (++gear > 5)
					gear = 5;
				cout << gear << endl;
				continue;
			}
			else if (keyV == LDOWN || UDOWN) {
				turn(ANGLE90);
				if (--gear < 0)
					gear = 0;
				cout << gear << endl;
				continue;
			}
			else if (keyV == CANCEL)
			{
				return -1;
			}
		}
		return 0;
	}
}

int getch(void)
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

void turn(const int& angle)
{
	if (angle == ANGLE0) 	//0°			//0.5ms--------------0°
	{										//1.0ms------------45°
		digitalWrite(SteerPin, HIGH);		//1.5ms------------90°
		delayMicroseconds(500); 			//2.0ms---------- - 135°
		delayMicroseconds(20000 - 500);		//2.5ms-----------180°
	}
	else if (angle == ANGLE90) //90°
	{
		digitalWrite(SteerPin, HIGH);
		delayMicroseconds(1500);
		delayMicroseconds(20000 - 1500);
	}
	else if (angle == ANGLE180) //180°
	{
		digitalWrite(SteerPin, HIGH);
		delayMicroseconds(2500);
		delayMicroseconds(20000 - 2500);
	}
}
