#include <iostream>
using namespace std;

double sqr(double);

class SoPhuc{
	private:
		double thuc,ao;
	public:
		SoPhuc();
		SoPhuc operator+ (SoPhuc);
		SoPhuc operator* (SoPhuc);
		friend SoPhuc operator -(SoPhuc,SoPhuc);
		friend SoPhuc operator /(SoPhuc,SoPhuc);
		friend istream& operator>> (istream&,SoPhuc &x);
		friend ostream& operator<< (ostream&,SoPhuc x);
};

SoPhuc::SoPhuc(){
	thuc = ao = 0;
}

SoPhuc SoPhuc::operator+ (SoPhuc x){
	SoPhuc ret;
	ret.thuc = thuc+x.thuc;
	ret.ao = ao+x.ao;
	return ret;
}

SoPhuc SoPhuc::operator* (SoPhuc x){
	SoPhuc ret;
	ret.thuc = thuc*x.thuc - ao*x.ao;
	ret.ao = thuc*x.ao + ao*x.thuc;
	return ret;
}

SoPhuc operator- (SoPhuc x,SoPhuc y){
	SoPhuc ret;
	ret.thuc = x.thuc - y.thuc;
	ret.ao = x.ao - y.ao;
	return ret;
}
SoPhuc operator /(SoPhuc x,SoPhuc y){
	double mau = sqr(y.thuc)+sqr(y.ao);
	y.ao *= -1;
	x = x * y;
	x.thuc /= mau;
	x.ao /= mau;
	return x;
}

double sqr(double x){
	return x*x;
}
istream& operator>> (istream& is,SoPhuc &x){
	is >> x.thuc >> x.ao;
	return is;
}
ostream& operator<< (ostream& os, SoPhuc x){
	os << x.thuc << (x.ao>0?"+":"") << x.ao << "i ";
}
int main(){
	SoPhuc s1,s2;
	cout << "Nhap so phuc 1: ";
	cin >> s1;
	cout << "Nhap so phuc 2: ";
	cin >> s2;
	cout <<"Tong: "<< s1+s2 <<"Hieu: "<< s1-s2 <<"Tich: "<< s1*s2 <<"Thuong: " << s1/s2;
	return 0;
}

