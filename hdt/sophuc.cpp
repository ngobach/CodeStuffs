#include <iostream>

using namespace std;

struct SoPhuc {
	float thuc,ao;
};

istream &operator >>(istream& is,SoPhuc &x){
	cout << "Nhap phan thuc va phan ao: ";
	is >> x.thuc >> x.ao;
	return is;
}
ostream &operator <<(ostream& os,SoPhuc x){
	os << x.thuc << (x.ao>=0?"+":"") << x.ao << "i ";
	return os;
}
SoPhuc operator +(SoPhuc &a,SoPhuc &b){
	SoPhuc tmp = {a.thuc + b.thuc,a.ao + b.ao};
	return tmp;
}
SoPhuc operator -(SoPhuc &a,SoPhuc &b){
	SoPhuc tmp = {a.thuc - b.thuc,a.ao - b.ao};
	return tmp;
}
SoPhuc operator *(SoPhuc &a,SoPhuc &b){
	SoPhuc tmp = {a.thuc*b.thuc - a.ao*b.ao,a.thuc*b.ao + a.ao*b.thuc};
	return tmp;
}
SoPhuc operator /(SoPhuc &a,SoPhuc &b){
	int mau = b.thuc * b.thuc + b.ao*b.ao;
	SoPhuc tmp = {(a.thuc*b.thuc + a.ao*b.ao)/mau,(a.ao*b.thuc - a.thuc*b.ao)/mau};
	return tmp;
}

int main(){
	SoPhuc a,b;
	cout << "Nhap vao 2 so phuc a va b: " << endl;
	cin >> a >> b;
	
	cout << "Tong 2 so phuc la: " << a + b << endl;
	cout << "Hieu 2 so phuc la: " << a - b << endl;
	cout << "Tich 2 so phuc la: " << a * b << endl;
	cout << "Thuong 2 so phuc la: " << a / b << endl;
}

