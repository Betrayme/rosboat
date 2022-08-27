#include "Common.h"
string strtime()
{
    stringstream ss;

    tm* p;  //创建新时间的结构体指针p
    time_t nowtime;
    time(&nowtime); //获取当前时间存入结构体nowtime中
    p=localtime(&nowtime);  //将nowtime中存储的日历时间转化为本地时间,返回tm指针
    int year=p->tm_year+1900;
    int month=p->tm_mon;
    int day=p->tm_mday;
    int hour=p->tm_hour;
    int minutes=p->tm_min;
    int seconds=p->tm_sec;

    ss<<year<<"."<<month<<"."<<day<<"."<<hour<<":"<<minutes<<":"<<seconds;
    string time;
    ss>>time;
    return time;
}

int get_local_ip(char * ifname, char * ip)  //ip:存储ip
{
    char *temp = NULL;
    int inet_sock;
    struct ifreq ifr;

    inet_sock = socket(AF_INET, SOCK_DGRAM, 0); 

    memset(ifr.ifr_name, 0, sizeof(ifr.ifr_name));
    memcpy(ifr.ifr_name, ifname, strlen(ifname));

    if(0 != ioctl(inet_sock, SIOCGIFADDR, &ifr)) 
    {   
        perror("ioctl error");
        return -1;
    }

    temp = inet_ntoa(((struct sockaddr_in*)&(ifr.ifr_addr))->sin_addr);     
    memcpy(ip, temp, strlen(temp));

    close(inet_sock);

    return 0;
}

char getch(void) 
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