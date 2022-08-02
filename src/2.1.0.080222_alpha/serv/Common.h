#ifndef _Common_
#define _Common_
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <cstring>
#include <string>
#include <string.h>
#include <vector>
#include <ctime>
#include <cstdio>
#include <net/if.h>
#include <sys/ioctl.h>
#include <termio.h>

#define IF_NAME "eth0"
#define QUEUE 5 //连接请求等待队列的长度
#define MAXMSG 100//暂存接收消息的最大长度
#define UP 		56			
#define LEFT 		52			
#define RIGHT 		54			
#define CANCEL          48                     
#define LUP      'w'		
#define UUP		 'W'		
#define LDOWN	 's'		
#define UDOWN    'S'
//void interaction();

#ifndef _USENAMESPACES_
#define _USENAMESPACES_
using namespace std;
#endif
string strtime();
int get_local_ip(char * ifname, char * ip);
char getch(void);
#endif
