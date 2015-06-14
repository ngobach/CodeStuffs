#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

const int WIDTH = 600;
const int HEIGHT = 600;
const double ROTATION_SPEED = 1.0; // toc do quay PISTON
const double PISTON_RADIUS = 100;
const double PISTON_LENGTH = 250;

double angle;

double sqr(double x){return x*x;}

void init(){
	initwindow(WIDTH,HEIGHT,"TEAM 23");
	angle = 0;
}

void anim(){
	angle += ROTATION_SPEED;
	if (angle >= 360)
		angle -= 360;
}

void paint(){
	cleardevice();
	
	double a = angle*M_PI/180;
	
	// draw PISTON
	setcolor(YELLOW);
	setlinestyle(1,1,1);
	circle(WIDTH/2,HEIGHT-PISTON_RADIUS - 50,PISTON_RADIUS);
	
	// offet y
	int h = PISTON_RADIUS*cos(a+M_PI/2)+sqrt(sqr(PISTON_LENGTH) -sqr(PISTON_RADIUS*sin(a+M_PI/2)));

	// draw piston
	setcolor(BLUE);
	setlinestyle(0,1,1);
	rectangle(WIDTH/2-100,HEIGHT-PISTON_RADIUS - 50 - h-140,WIDTH/2+100,HEIGHT-PISTON_RADIUS - 50 - h+30);
	rectangle(WIDTH/2-98,HEIGHT-PISTON_RADIUS - 50 - h-138,WIDTH/2+98,HEIGHT-PISTON_RADIUS - 50 - h-32);
	rectangle(WIDTH/2-98,HEIGHT-PISTON_RADIUS - 50 - h-30,WIDTH/2+98,HEIGHT-PISTON_RADIUS - 50 - h+28);
	
	// draw bar
	setcolor(RED);
	setlinestyle(0,1,50);
	line(WIDTH/2 + cos(a)*PISTON_RADIUS,HEIGHT-PISTON_RADIUS - 50+sin(a)*PISTON_RADIUS,WIDTH/2,HEIGHT-PISTON_RADIUS - 50 - h);
	
	
	// joint 1
	setcolor(BLACK);
	setlinestyle(0,1,1);
	circle(WIDTH/2 + cos(a)*PISTON_RADIUS,HEIGHT-PISTON_RADIUS - 50+sin(a)*PISTON_RADIUS,20);
	
	// joint 2
	setcolor(BLACK);
	setlinestyle(0,1,1);
	circle(WIDTH/2,HEIGHT-PISTON_RADIUS - 50 - h,20);
	
	settextstyle(2,0,7);
	setcolor(CYAN);
	outtextxy(150,HEIGHT - 30,"Mo phong chuyen dong cua piston");
}

void loop(){
	int i=0,j;
	while (!kbhit()){
		j = 1-i;
		setactivepage(i);
		setvisualpage(j);
		anim();
		paint();
		delay(1);
		i = j;
	}
}


int main(){
	init();
	loop();
	return 0;
}

