#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define _i ::iterator

using namespace std;
typedef long long LL;

class CPoint{
	private:
		int x,y;
	public:
		CPoint(int x = 0,int y = 0);
		void print();
		~CPoint();
};


CPoint::CPoint(int x,int y){
	this->x = x;
	this->y = y;
}
CPoint::~CPoint(){
	cout << "[DELETED]" << endl;
}
void CPoint::print(){
	cout << "(" << x << ";" << y << ")";
}
int main(){
	CPoint *p = new CPoint();
	p->print();
	delete p;
	p = new CPoint(3,4);
	p->print();
	delete p;
	return 0;
}
