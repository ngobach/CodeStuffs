#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
struct Point{
	int x,y;
};
const char NAME[3][20] = {"Xoay","Tinh tien","Thu phong"};
const int STEP_T = 10;
const int WIDTH = 600;
const int HEIGHT = 600;

Point p[3],q[3],d;
double sc;
int mode;
int goc;

void init() {
	initwindow(WIDTH,HEIGHT,"Ve tam giac");
	p[0] = {100,-80};
	p[1] = {-50,100};
	p[2] = {0,100};
	d = {0,0};
	mode = 1;
	goc = 0;
	sc = 1.0;
}
double d2r(double d){
	return d*M_PI/180;
}
void cacl(){
	q[0]=p[0];q[1]=p[1];q[2]=p[2];
	Point pp;
	switch(mode){
		case 1:
			for (int i=0;i<3;i++){
				pp.x = cos(d2r(goc))*p[i].x - sin(d2r(goc))*p[i].y;
				pp.y = sin(d2r(goc))*p[i].x + cos(d2r(goc))*p[i].y;
				q[i] = pp;
			}
			break;
		case 2:
			for (int i=0;i<3;i++){
				q[i].x += d.x;
				q[i].y += d.y;
			}
			break;
		case 3:
			for (int i=0;i<3;i++){
				q[i].x *= sc;;
				q[i].y *= sc;
			}
			break;
	}
	
	// thu phong
}

void paint(){
	char txt1[1000] = {0}, txt2[1000] = {0};
	int ox = getmaxx()/2,oy = getmaxy()/2;
	// reset painter
	setbkcolor(BLACK);
	setcolor(WHITE);
	cleardevice();

	// goc toa do
	setcolor(GREEN);
	circle(ox,oy,2);
	
	// ve tam giac
	setcolor(WHITE);
	line(ox + q[0].x,oy + q[0].y,ox + q[1].x,oy + q[1].y);
	line(ox + q[0].x,oy + q[0].y,ox + q[2].x,oy + q[2].y);
	line(ox + q[1].x,oy + q[1].y,ox + q[2].x,oy + q[2].y);
	
	// draw text
	settextstyle(2,0,4);
	setcolor(CYAN);
	strcat(txt1,"Thao tac: ");
	strcat(txt1,NAME[mode-1]);
	strcat(txt2,"[1]: Xoay  [2]: Tinh tien  [3]: Thu phong");
	if (mode == 1){
		strcat(txt2, "     [UP][DOWN]: Tang/giam goc quay");
	}else if (mode == 2){
		strcat(txt2, "     [UP][DOWN][LEFT][RIGHT]: Di chuyen");
	}else if (mode == 3){
		strcat(txt2, "     [UP][DOWN]: Thu/phong da giac");
	}
	outtextxy(10,HEIGHT - 20,txt2);
	outtextxy(10,HEIGHT - 30,txt1);
}
void key(){
	char c = getch();
	switch (c){
		case 27:
			exit(0);
			break;
		case '1':
			mode = 1;
			break;
		case '2':
			mode = 2;
			break;
		case '3':
			mode = 3;
			break;
		case KEY_UP:
			switch(mode){
				case 1:
					goc = (goc+5)%360;
					break;
				case 2:
					d.y -= 5;
					break;
				case 3:
					sc -= .1;
					if (sc < .2)
						sc = .2;
					break;
			}
			break;
		case KEY_LEFT:
			if (mode == 2){
				d.x -= 5;
			}
			break;
		case KEY_RIGHT:
			if (mode == 2){
				d.x += 5;
			}
			break;
		case KEY_DOWN:
			switch(mode){
				case 1:
					goc = (goc-5)%360;
					break;
				case 2:
					d.y += 5;
					break;
				case 3:
					sc += .1;
					break;
			}
			break;
		default:
			// printf("Invalid key:(%d)\n",c);
			break;
	}
}
void loop(){
	while (true){
		cacl();
		paint();
		key();
	}
}


int main(){
	init();
	loop();
	return 0;
}

