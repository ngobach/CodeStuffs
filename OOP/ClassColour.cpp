#include <iostream>

using namespace std;

class CPoint{
	private:
		int x,y,colour;
	public:
		CPoint();
		void setData(int x,int y,int colour);
		void setData(int x,int y);
		void print();
};

CPoint::CPoint(){
	x = 0;
	y = 0;
	colour = 0;
}

void CPoint::setData(int x,int y,int colour){
	this->x = x;
	this->y = y;
	this->colour = colour;
}

void CPoint::setData(int x,int y){
	this->x = x;
	this->y = y;
}

void CPoint::print(){
	cout << "Point: (" << x << ';' << y << "):" << colour << endl;
}

int main(){
	CPoint *point = new CPoint();
	cout << "After init(): " << endl;
	point->print();
	point->setData(1,2,0xFFFFFF);
	cout << "After setdata 1: " << endl;
	point->print();
	point->setData(5,5);
	cout << "After setdata 2: " << endl;
	point->print();
	
	return 0;
}

