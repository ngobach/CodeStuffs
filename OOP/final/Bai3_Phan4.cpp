#include <iostream>
using namespace std;
class Nguoi{
	public:
		string hoten,diachi,sdt;
		void nhap();
		void hienthi();
};
class KhachHang: public Nguoi{
	private:
		static const int KH_MUALE = 1;
		static const int KH_MUABUON = 2;
	public:
		int maKH,loaiKH;
		void nhap();
		void hienthi();
};
class MatHang{
	private:
		int maHang;
		string tenHang;
		int nhomHang;
		int giaBan;
	public:
};
int main(){
}


