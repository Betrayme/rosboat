//ͷ
#pragma once       //��֤��һ���ļ���ͷ�ļ����ᱻ������
#include<stdio.h>
#include<iostream>
#include<wiringPi.h>
#include<softPwm.h>
#include<cstring>
#include<termio.h>

//ȫ�ֺ궨��
#define UP 		56			//ǰ�� ��ӦС����8
#define LEFT 		52			//��ת ��ӦС����4
#define RIGHT 		54			//��ת ��ӦС����6
#define CANCEL          48                      //��������  ��ӦС����0
#define LUP      'w'		//��ߵ�λ
#define UUP		 'W'		
#define LDOWN	 's'		//���͵�λ
#define UDOWN    'S'

//��������
void init();
void pwm(int PWMPin, int PWMValue);
void rangestd();
void control(int PWMValue);
int getch(void);
void turn(int p);

//ȫ�ֱ�������
extern int PWMPin;		//2-13����Pin
extern int SteerPin;	//2-13���Pin
extern int PWMValue;	//0-1000
extern int keyV;
extern int gear;        //0-5
