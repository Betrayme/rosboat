//�0�5
#pragma once       //�1�7�1�7�0�8�1�7�1�7�0�5�1�7�1�7�1�7�0�4�1�7�1�7�1�7�0�5�1�7�0�4�1�7�1�7�1�7�1�7�5�5�1�7�1�7�1�7�1�7�1�7�1�7
#include<stdio.h>
#include<iostream>
#include<wiringPi.h>
#include<softPwm.h>
#include<cstring>
#include<termio.h>

//�0�0�1�7�0�0�7�9�1�7�1�7
#define UP 		56			//�0�2�1�7�1�7 �1�7�1�7�0�8���1�7�1�7�1�7�1�78
#define LEFT 		52			//�1�7�1�7�0�8 �1�7�1�7�0�8���1�7�1�7�1�7�1�74
#define RIGHT 		54			//�1�7�1�7�0�8 �1�7�1�7�0�8���1�7�1�7�1�7�1�76
#define CANCEL          48                      //�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7  �1�7�1�7�0�8���1�7�1�7�1�7�1�70
#define LUP      'w'		//�1�7�1�7�1�1�1�7��
#define UUP		 'W'		
#define LDOWN	 's'		//�1�7�1�7�1�7�0�3�1�7��
#define UDOWN    'S'

//�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7
void init();
void pwm(int PWMPin, int PWMValue);
void rangestd();
void control(int PWMValue);
int getch(void);
void turn(int p);

//�0�0�1�7�0�1�1�7�1�7�1�7�1�7�1�7�1�7�1�7
extern int PWMPin;		//2-13�1�7�1�7�1�7�1�7Pin
extern int SteerPin;	//2-13�1�7�1�7�1�7Pin
extern int PWMValue;	//0-1000
extern int keyV;
extern int gear;        //0-5
