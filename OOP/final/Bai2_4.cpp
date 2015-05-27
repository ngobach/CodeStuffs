#include <iostream>

using namespace std;

class Nguoi;
class SinhVien;
class BangDangKy;

class Nguoi{
	public:
		Nguoi();
		Nguoi(string hoten,string quequan ,string sdt);
		string hoten;
		string diachi;
		string sdt;
		void nhap();
		void xuat();
};

class SinhVien : public Nguoi {
	
	private:
		static int MSV;
		
	public:
		SinhVien();
		SinhVien(string hoten,string quequan,string sdt,string lop);
};

int SinhVien::MSV = 1000;

int main(){
	return 0;
}

