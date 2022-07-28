#include"engine.h"
void init()
{
	if (wiringPiSetup() == -1) {
		printf("init error!\n");
	}
}

void pwm(int PMMPin, int PWMValue) //模拟pwm信号周期10ms ,频率100HZ
{
	PWMValue += 1000;
	digitalWrite(PWMPin, HIGH);
	delayMicroseconds(PWMValue); //程序暂停 单位微秒
	digitalWrite(PWMPin, LOW);
	delayMicroseconds(10000 - PWMValue);
}

void rangestd() //初始化电调
{
	pinMode(PWMPin, OUTPUT);

	for (int i = 0; i <= 220; i++) {
		pwm(PWMPin, 1000); //最高档 对应高电平2ms
	}
	for (int i = 0; i <= 110; i++) {
		pwm(PWMPin, 0);  //0档 对应高电平1ms
	}
}

void control(int PWMValue) //控制函数
{
	while (1)
	{
		keyV = getch();
		if (keyV == UP) {
			pwm(PWMPin, 200 * gear);
			turn(0);
		}
		else if (keyV == LEFT)
		{
			turn(-1);
		}
		else if (keyV == RIGHT)
		{
			turn(1);
		}
		else if (keyV == LUP || UUP) {
			turn(0);
			gear++;
			if (gear > 5)
				gear = 5;
			printf("目前挡位为%d", gear);
		}
		else if (keyV == LDOWN || UDOWN) {
			turn(0);
			gear--;
			if (gear < 0)
				gear = 0;
			printf("目前挡位为%d", gear);
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

int getch(void) //getch()函数 Linux可用
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

void turn(int p) 
{
	if (p == -1) //左						//0.5ms--------------0度；
	{										//1.0ms------------45度；
		digitalWrite(SteerPin, HIGH);		//1.5ms------------90度；
		delayMicroseconds(500); 			//2.0ms---------- - 135度；
		delayMicroseconds(20000 - 500);		//2.5ms-----------180度；
	}
	else if (p == 1) //右 
	{
		digitalWrite(SteerPin, HIGH);
		delayMicroseconds(1500); 		
		delayMicroseconds(20000 - 1500);
	}
	else if (p == 0) //不转
	{
		digitalWrite(SteerPin, HIGH);
		delayMicroseconds(2500);
		delayMicroseconds(20000 - 2500);
	}
}
