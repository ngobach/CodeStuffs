#include <iostream>
#define ducngu cout
using namespace std;

int gcd(int,int);

class PhanSo{
	public:
		int tu,mau;
		PhanSo();
		PhanSo(int,int);
		~PhanSo();
		void nhap();
		void xuat();
		PhanSo operator+(PhanSo);
};

PhanSo::PhanSo(){
	tu = mau = 1;
}

PhanSo::PhanSo(int t,int m){
	tu = t; mau = m;
}

PhanSo::~PhanSo(){
	
}

void PhanSo::nhap(){
	cout << "Nhap tu va mau: ";
	cin >> tu >> mau;
}

void PhanSo::xuat(){
	cout << tu << "/" << mau <<"\t";
}

PhanSo PhanSo::operator+(PhanSo x){
	PhanSo ret;
	ret.tu = tu*x.mau+mau*x.tu;
	ret.mau = mau*x.mau;
	int t = gcd(ret.tu,ret.mau);
	ret.tu /= t;
	ret.mau /= t;
	return ret;
}

int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}

int main(){
	PhanSo a,b;
	a.nhap();
	b.nhap();
	(a+b).xuat();
}

