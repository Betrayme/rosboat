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
#define LUP      119		
#define UUP		 87		
#define LDOWN	 115	
#define UDOWN    83
#define MAXGEAR     1000
#define MINGEAR     0
#define ANGLE0      -1
#define ANGLE90     0
#define ANGLE180    1

int enginerun(const char*);
int enginerun(const char*, const int&);
void init();
void rangestd();
void pwm(int, int);
// void rangestd();
int control(const char* );
int getch(void);
void turn(const int& );


extern int PWMPin;		
extern int SteerPin;	
extern int PWMValue;	
extern int keyV;
extern int gear;        
#endif
