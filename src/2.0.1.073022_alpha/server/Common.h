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
#include <vector>
#include <ctime>
#include <cstdio>

#define QUEUE 5 //连接请求等待队列的长度
#define MAXMSG 100//暂存接收消息的最大长度
//void interaction();
#endif

#ifndef _strtime_
#define _strtime_
std::string strtime()
{
    std::stringstream ss;

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
    std::string time;
    ss>>time;
    return time;
}
#endif
