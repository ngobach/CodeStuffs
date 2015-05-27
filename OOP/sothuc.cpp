#include <iostream>
using namespace std;

class SoPhuc{
	private:
		int thuc,ao;
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
	ret.ao = thuc+x.ao;
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

int main(){
	return 0;
}

