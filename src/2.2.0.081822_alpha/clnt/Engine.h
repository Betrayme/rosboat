#ifndef _Engine_
#define _Engine_

#ifndef _USENAMESPACES_
#define _USENAMESPACES_
using namespace std;
#endif

#include<stdio.h>
#include<iostream>
#include<wiringPi.h>
#include<softPwm.h>
#include<cstring>
#include<termio.h>


#define UP 		56			
#define LEFT 		52			
#define RIGHT 		54			
#define CANCEL          48                      
#define LUP      'w'		
#define UUP		 'W'		
#define LDOWN	 's'		
#define UDOWN    'S'
#define MAXGEAR     1000
#define MINGEAR     0
#define ANGLE0      -1
#define ANGLE90     0
#define ANGLE180    1

int enginerun(const char*);
void init();
void pwm(int , int );
// void rangestd();
int control(const char*& );
int getch(void);
void turn(const int& );


extern int PWMPin;		
extern int SteerPin;	
extern int PWMValue;	
extern int keyV;
extern int gear;        
#endif