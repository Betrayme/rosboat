//头
#pragma once       //保证在一个文件中头文件不会被编译多次
#include<stdio.h>
#include<iostream>
#include<wiringPi.h>
#include<softPwm.h>
#include<cstring>
#include<termio.h>

//全局宏定义
#define UP 		56			//前进 对应小键盘8
#define LEFT 		52			//左转 对应小键盘4
#define RIGHT 		54			//右转 对应小键盘6
#define CANCEL          48                      //结束进程  对应小键盘0
#define LUP      'w'		//提高挡位
#define UUP		 'W'		
#define LDOWN	 's'		//降低挡位
#define UDOWN    'S'

//函数声明
void init();
void pwm(int PWMPin, int PWMValue);
void rangestd();
void control(int PWMValue);
int getch(void);

//全局变量声明
extern int PWMPin;		//2-13引擎Pin
extern int SteerPin;	//2-13舵机Pin
extern int PWMValue;	//0-1000
extern int keyV;
extern int gear;        //0-5
