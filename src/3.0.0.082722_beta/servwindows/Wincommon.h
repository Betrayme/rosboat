#ifndef _Wincommon_
#define _Wincommon_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

#define QUEUE 5 //连接请求等待队列的长度
#define BUF_SIZE 50
#define UP 		56			
#define LEFT 		52			
#define RIGHT 		54			
#define CANCEL          48                     
#define LUP      'w'		
#define UUP		 'W'		
#define LDOWN	 's'		
#define UDOWN    'S'

#ifndef _USENAMESPACES_
#define _USENAMESPACES_
using namespace std;
#endif

#endif