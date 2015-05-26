#include <iostream>
#include <cmath>
using namespace std;

class Point{
	public:
		int x,y;
		Point();
		Point(int x, int y);
		~Point();
		void nhap();
		void xuat();
};

Point::Point(){
	x = y = 0;
}

Point::Point(int x,int y){
	this->x = x;
	this->y = y;
}

Point::~Point(){
}

void Point::nhap(){
	cout << "Nhap toa do x va y nguyen: ";
	cin >> x >> y;
}

void Point::xuat(){
	cout << "Toa do x va y la: "<< x << y << endl;
}

double sqr(double x){
	return x*x;
}

double dis(Point a,Point b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

int main(){
	double maxd = 0;
	Point p[1000];
	int n;
	cout << "Nhap so luong Points: ";
	cin >> n;
	for (int i=0;i<n;i++){
		cout << "Nhap diem thu " << i+1 << endl;
		p[i].nhap();
	}
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++){
			maxd = max(maxd,dis(p[i],p[j]));
		}
	cout << "Khoang cach lon nhat giua 2 trong n diem la: " << maxd << endl;
	return 0;
}

