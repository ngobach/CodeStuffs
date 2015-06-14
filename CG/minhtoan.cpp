#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;
int n,a[1000][2];
const double ZOOM = 1.2;

void nhap(){
	do{
		cout << "Nhap so luong dinh (n>2): ";
		cin >> n;
	} while (n <= 2);
	for (int i=0;i<n;i++){
		cout << "Nhap toa do dinh thu " << i+1 << ": ";
		cin >> a[i][0] >> a[i][1];
	}
}

void hienthi(){
	int w,h;
	char c;
	float sc = 1;
	initwindow(800,600);
	while (true){
		w = getmaxx();
		h = getmaxy();
		cleardevice();
		
		moveto(sc*a[0][0]+w/2,sc*a[0][1]+h/2);
		for (int i=1;i<n;i++){
			lineto(sc*a[i][0]+w/2,sc*a[i][1]+h/2);
		}
		lineto(sc*a[0][0]+w/2,sc*a[0][1]+h/2);
		
		
		c = getch();
		switch (c){
			case 27:
				exit(0);
				break;
			case KEY_UP:
			case KEY_RIGHT:
				sc *= ZOOM;
				break;
			case KEY_DOWN:
			case KEY_LEFT:
				if (sc > .1)
					sc /= ZOOM;
		}
	}
}
int main(){
	nhap();
	hienthi();
	return 0;
}

