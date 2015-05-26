#include <iostream>

using namespace std;

struct SinhVien{
	string MaSV,HoTen,NgaySinh;
	float DTB;
};

istream &operator >>(istream &is,SinhVien &sv){
	cout << "Ma sinh vien: ";is >> sv.MaSV;is.ignore();
	cout << "Ho Ten: ";getline(is,sv.HoTen);
	cout << "Ngay sinh: ";is >> sv.NgaySinh;
	cout << "Diem trung binh: ";is >>sv.DTB;
	return is;
}

ostream &operator <<(ostream &os,SinhVien &sv){
	cout << "Ma SV: " << sv.MaSV << endl;
	cout << "Ho Ten: " << sv.HoTen << endl;
	cout << "Ngay sinh: " << sv.NgaySinh << endl;
	cout << "Diem trung binh: " << sv.DTB << endl;
	return os;
}

int main(){
	SinhVien sv;
	cout << "Nhap thong tin sinh vien: " << endl;
	cin >> sv;
	cout << "Sinh vien vua nhap la: " << endl << sv;
	return 0;
}

