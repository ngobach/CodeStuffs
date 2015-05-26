#include <iostream>
using namespace std;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
class PhanSo{
	private:
		int ts,ms;
	public:
		PhanSo(){}
		PhanSo(int ts,int ms);
		void nhap();
		void hienthi();
		void rutgon();
		int t(){return ts;}
		int m(){return ms;}
		PhanSo* cong(PhanSo *ps);
};
PhanSo::PhanSo(int ts,int ms){
	this->ts = ts;
	this->ms = ms;
}
void PhanSo::nhap(){
	cout << "Nhap tu va mau so: ";
	cin >> ts >> ms;
}
void PhanSo::hienthi(){
	cout << "Gia tri phan so la: "<<ts << "/" << ms << endl;
}
void PhanSo::rutgon(){
	int ucln = gcd(ts,ms);
	ts/=ucln;ms/=ucln;
}
PhanSo* PhanSo::cong(PhanSo *ps){
	return new PhanSo(ts * ps->m() + ms*ps->t(), ms*ps->m());
}

int main(){
	PhanSo *ps1,*ps2,*ps3;
	ps1 = new PhanSo();
	ps2 = new PhanSo();
	cout << "Nhap 2 phan so:"<<endl;
	ps1->nhap();
	ps2->nhap();
	cout << "2 phan so da nhap la:" << endl;
	ps1->hienthi();
	ps2->hienthi();
	cout << "Tong 2 phan so:" << endl;
	ps3 = ps1->cong(ps2);
	ps3->rutgon();
	ps3->hienthi();
	delete ps1;
	delete ps2;
	delete ps3;
}

