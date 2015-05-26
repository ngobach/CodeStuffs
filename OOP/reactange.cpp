#include <iostream>
#include <string>
using namespace std;
struct sinhvien{
	string masv,tensv,ngaysinh, ns;
	float dtb;
};
istream& operator >>(istream& in,sinhvien &sv) {
	cout << "nhap ma sinh vien :"; in >> sv.masv;
	cout << "nhap ten sinh vien :"; in.ignore();getline(in,sv.tensv);

	cout << "nhap noi song sinh vien :"; in >> sv.ns;

	cout << "nhap dtb sinh vien :"; in >> sv.dtb;
}
ostream& operator <<(ostream& out,sinhvien sv){
	cout << " ma sinh vien : " << sv.masv;
	cout << " ten sinh vien : " << sv.tensv;
	cout << " noi song sinh vien : " << sv.ns;
	cout << " dtb sinh vien : " << sv.dtb;
}
int main(){
	sinhvien sv;
	cout << "nhap thong tin sv : "<< endl; cin >> sv;
	cout << "hien thi thong tin sinh vien :"; cout << sv;
}
