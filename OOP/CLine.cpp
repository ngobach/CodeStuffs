#include <iostream>
#include <cmath>
using namespace std;
float sqr(float x){
	return x*x;
}
class Point {
	private:
		int x,y;
	public:
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
		void input(){
			cout << "Nhap x va y: "; cin >> x >> y;
		}
		void clone(Point p){
			this->x = p.x;
			this->y = p.y;
		}
		void display(){
			cout << "(x=" << x << ";y=" << y << ") ";
		}
};
class Line {
	private:
		Point dau,cuoi;
	public:
		void input(){
			cout << "Nhap diem dau: " << endl;
			dau.input();
			cout << "Nhap diem cuoi: " << endl;
			cuoi.input();
		}
		void setDiemDau(Point p){
			dau = p;
		}
		void setDiemCuoi(Point p){
			cuoi = p;
		}
		void setData(Point dau,Point cuoi){
			this->dau = dau;
			this->cuoi = cuoi;
		}
		float getLength(){
			return sqrt(sqr(cuoi.getX()-dau.getX()) + sqr(cuoi.getY()-dau.getY()));
		}
		void display(){
			cout << "Diem dau la: ";dau.display();cout << endl;
			cout << "Diem cuoi la: ";cuoi.display();cout << endl;
			cout << "Do dai doan thang la: " << getLength() << endl;
		}
};
int main(){
	Line l;
	cout << "Nhap doan thang: " << endl;
	l.input();
	l.display();
	
	Point p1,p2;
	cout << "Nhap diem dau moi: " << endl;
	p1.input();
	cout << "Nhap diem cuoi moi: " << endl;
	p2.input();
	l.setData(p1,p2);
	l.display();
	return 0;
}
