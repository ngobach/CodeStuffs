#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
struct Point{
	int x,y;
};
const int WIDTH = 900;
const int HEIGHT = 500;
const int CAR_LENGTH = 260;
const int CAR_HEIGHT = 100;
const int WHEEL_RADIUS = 30;
const int SPEED = 5;

int t,w,h;
vector<Point> vp;

void init(){
	initwindow(WIDTH,HEIGHT);
	w = getmaxx(),h = getmaxy();
	t = 0;
}

void paint(){
	int x=(t*M_PI/180)*WHEEL_RADIUS,y=0;
	double sa = sin(t*M_PI/180);
	double ca = cos(t*M_PI/180);
	
	// xoa man hinh de ve
	clearviewport();
	
	// ve than o to
	setcolor(WHITE);
	setlinestyle(0,0,1);
	moveto(x,h-WHEEL_RADIUS);
	linerel(CAR_LENGTH,0);
	linerel(0,-CAR_HEIGHT/2);
	linerel(-CAR_HEIGHT/2,-CAR_HEIGHT/2);
	linerel(-CAR_LENGTH+CAR_HEIGHT/2,0);
	linerel(0,CAR_HEIGHT);
	
	// ve banh xe
	setcolor(WHITE);
	setfillstyle(1,BLACK);
	
	fillellipse(x+CAR_LENGTH/4,h-WHEEL_RADIUS,WHEEL_RADIUS,WHEEL_RADIUS);
	circle(x+CAR_LENGTH/4,h-WHEEL_RADIUS,WHEEL_RADIUS);
	circle(x+CAR_LENGTH/4,h-WHEEL_RADIUS,WHEEL_RADIUS-2);
	circle(x+CAR_LENGTH/4,h-WHEEL_RADIUS,2);
	arc(x+CAR_LENGTH/4,h-WHEEL_RADIUS,-t,-t+90,WHEEL_RADIUS/3*2);
	arc(x+CAR_LENGTH/4,h-WHEEL_RADIUS,-t-180,-t-90,WHEEL_RADIUS/3*2);
	
	fillellipse(x+3*CAR_LENGTH/4,h-WHEEL_RADIUS,WHEEL_RADIUS,WHEEL_RADIUS);
	circle(x+3*CAR_LENGTH/4,h-WHEEL_RADIUS,WHEEL_RADIUS);
	circle(x+3*CAR_LENGTH/4,h-WHEEL_RADIUS,WHEEL_RADIUS-2);
	circle(x+3*CAR_LENGTH/4,h-WHEEL_RADIUS,2);
	arc(x+3*CAR_LENGTH/4,h-WHEEL_RADIUS,-t+90,-t+180,WHEEL_RADIUS/3*2);
	arc(x+3*CAR_LENGTH/4,h-WHEEL_RADIUS,-t-90,-t,WHEEL_RADIUS/3*2);
	
	// ve quy dao chuyen dong cua diem tren vanh banh xe
	setcolor(YELLOW);
	moveto(vp[0].x,vp[0].y);
	for (int i=1;i<vp.size();i++){
		lineto(vp[i].x,vp[i].y);
	}
}

void anim(){
	if ((t*M_PI/180)*WHEEL_RADIUS >= w-CAR_LENGTH)
		return;
	t+=SPEED;
	double d = t*M_PI/180;
	vp.push_back({CAR_LENGTH/4 + (d+sin(d))*WHEEL_RADIUS,h - (cos(d)+1)*WHEEL_RADIUS});
}

int main(){
	int i = 0;
	init();
	while (!kbhit()){
		anim();
		setvisualpage(1-i);
		setactivepage(i);
		paint();
		i=1-i;
		delay(1000);
	}
	closegraph();
	return 0;
}
