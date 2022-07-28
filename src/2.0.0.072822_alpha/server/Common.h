#ifndef _Common_
#define _Common_
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <cstring>
#include <string>
#include <vector>

#define QUEUE 5 //连接请求等待队列的长度
#define MAXMSG 100//暂存接收消息的最大长度
//void interaction();
#endif