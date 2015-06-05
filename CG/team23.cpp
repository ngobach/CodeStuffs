#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

const int WIDTH = 600;
const int HEIGHT = 600;
const int TRIANGLE_SIZE = 200; // ban kinh duong tron ngoai tiep tam giac deu
const double ROTATION_SPEED = -2.0; // toc do quay cua tam giac, cho so am de quay nguoc lai

int center[2] = {WIDTH/2,HEIGHT/2};
double angle;

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
	double points[3][2];
	for (int i=0;i<3;i++){
		double a = angle*M_PI/180 + M_PI*2/3*i;
		points[i][0] = center[0] + sin(a)*TRIANGLE_SIZE;
		points[i][1] = center[1] + cos(a)*TRIANGLE_SIZE;
	}
	int j;
	setcolor(WHITE);
	for (int i=0;i<3;i++){
		j = (i+1)%3;
		line(points[i][0],points[i][1],points[j][0],points[j][1]);
	}
	settextstyle(2,0,7);
	setcolor(CYAN);
	outtextxy(100,HEIGHT - 30,"Demo ve tam giac deu tu quay quanh tam");
}

void loop(){
	while (!kbhit()){
		anim();
		paint();
		delay(100);
	}
}


int main(){
	init();
	loop();
	return 0;
}

