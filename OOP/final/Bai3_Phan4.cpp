#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

class Nguoi{
	public:
		string hoten,diachi,sdt;
		
		void nhap(){
			cout << "Nhap ho va ten: ";
			getline(cin,hoten);
			cout << "Nhap dia chi: ";
			getline(cin,diachi);
			cout << "Nhap so dien thoai: ";
			getline(cin,sdt);
		}
		
		void hienthi(){
			cout << "** Thong tin nguoi ***" << endl;
			cout << "Ho va ten: " << hoten << endl;
			cout << "Dia chi: " << diachi << endl;
			cout << "SDT: " << sdt << endl;
		}
};

class KhachHang: public Nguoi{
	private:
		static const int KH_MUALE = 1;
		static const int KH_MUABUON = 2;
		static int count;
		static string getLoaiKhachHang(int loaiKH){
			switch (loaiKH){
				case KH_MUALE:
					return "Khach hang mua le";
				case KH_MUABUON:
					return "Khach hang mua buon";
				default:
					return "Khach hang chua biet";
			}
		}
		
	public:
		int maKH,loaiKH;
		
		KhachHang():Nguoi(){
			maKH = ++count;
		}
		void nhap(){
			Nguoi::nhap();
			do{
				cout << "Nhap loai khach hang: " << endl;
				cout << "\t1. Khach hang mua le" << endl;
				cout << "\t2. Khach hang mua buon" << endl;
				cin >> loaiKH;
			} while (loaiKH < 1 || loaiKH > 2);
			cin.ignore(INT_MAX,'\n');
		}
		void hienthi(){
			Nguoi::hienthi();
			cout << "** Thong tin khach hang ***" << endl;
			cout << "Ma kh: " << maKH << endl;;
			cout << "Loai kh: " << getLoaiKhachHang(loaiKH) << endl;
		}
};
int KhachHang::count = 10000;

class MatHang{
	private:
		static const int NH_THOITRANG = 1;
		static const int NH_TIEUDUNG = 2;
		static const int NH_DIENMAY = 3;
		static const int NH_GIADUNG = 4;
		static int count;
		
		static string getNhomHang(int nh){
			switch (nh){
				case NH_THOITRANG:
					return "Hang thoi trang";
				case NH_TIEUDUNG:
					return "Hang tieu dung";
				case NH_DIENMAY:
					return "Hang dien may";
				case NH_GIADUNG:
					return "Hang gia dung";
			}
		}
		
	public:
		int maHang;
		string tenHang;
		int nhomHang;
		int giaBan;
		
		MatHang(){
			maHang = ++count;
		}
		
		void nhap(){
			cout << "Nhap ten hang: ";
			getline(cin,tenHang);
			do{
				cout << "Nhap nhom hang:" << endl;
				cout << "\t1. Hang thoi trang" << endl;
				cout << "\t2. Hang tieu dung" << endl;
				cout << "\t3. Hang dien may" << endl;
				cout << "\t4. Hang gia dung" << endl;
				cin >> nhomHang;
			}while (nhomHang<1 || nhomHang > 4);
			cout << "Nhap gia ban: ";
			cin >> giaBan;
			cin.ignore(INT_MAX, '\n');
		}
		
		void hienthi(){
			cout << "Thong tin mat hang: " << endl;
			cout << "Ma hang: " << maHang << endl;
			cout << "Ten hang: " << tenHang << endl;
			cout << "Nhom hang: " << getNhomHang(nhomHang) << endl;
			cout << "Gia ban: " << giaBan << endl;
		}
};

int MatHang::count = 1000;


class BangDanhSachMuaHang {
	public:
		KhachHang *kh;
		MatHang *mh[10];
		int sl[10],n;
		
		void nhap(KhachHang *pKh, MatHang *arr, int m){
			int t;
			kh = pKh;
			cout << "Nhap so mat hang can mua: ";
			cin >> n;
			
			for (int i=0;i<n;i++){
				while (true){
					cout << "Nhap ma hang cua mat hang can mua thu " << i + 1 << ": ";
					cin >> t;
					if (t>=arr[0].maHang && t < arr[0].maHang+m){
						break;
					}else{
						cout << "Ma hang nay khong ton tai, xin nhap lai!" << endl;
					}
				}
				mh[i] = arr + t - arr[0].maHang;
				cout << "Nhap so luong cua mat hang nay: ";
				cin >> sl[i];
			}
		}
		
		void hienthi(){
			cout << "*** Bang danh sach mua hang ***" << endl;
			cout << "Khach hang: " << kh->hoten << endl;
			cout << "So luong mat hang: " << n << endl;
			for (int i=0;i<n;i++){
				cout << "\t" << mh[i]->tenHang <<": " << sl[i] << endl;
			}
		}
};

bool cmp (const BangDanhSachMuaHang &a,const BangDanhSachMuaHang &b){
	return (a.kh->hoten < b.kh->hoten);
}
int main(){
	KhachHang kh[1000];
	MatHang mh[1000];
	BangDanhSachMuaHang ds[1000];
	int n1,n2;
	
	cout << "Nhap so luong khach hang: ";
	cin >> n1;
	cin.ignore(INT_MAX,'\n');
	
	for (int i=0;i<n1;i++){
		cout << "Nhap khach hang thu " << i + 1 << endl;
		kh[i].nhap();
		system("cls");
	}
	
	/* hien thi thong tin khach hang da nhap */
	system("cls");
	for (int i=0;i<n1;i++){
		kh[i].hienthi();
		cout << endl;
	}
	getch();system("cls");
	
	/* nhap danh sach mat hang */
	cout << "Nhap so luong mat hang: ";
	cin >> n2;
	cin.ignore(INT_MAX, '\n');
	for (int i=0;i<n2;i++){
		cout << "Nhap mat hang thu " << i + 1 << endl;
		mh[i].nhap();
		system("cls");
	}
	
	for (int i=0;i<n2;i++){
		mh[i].hienthi();
		cout << endl;
	}
	getch();system("cls");
	
	/* Nhap danh sach bang mua hang */
	for (int i=0;i<n1;i++){
		cout << "Nhap bang mua hang cho khach hang thu " << i+1 << endl;
		ds[i].nhap(kh+i,mh,n2);
	}
	system("cls");
	/* hien thi danh sach bang mua hang */
	for (int i=0;i<n1;i++){
		ds[i].hienthi();
		cout << endl;
	}
	getch();system("cls");
	
	/* sap xep danh sach bang mua hang */
	sort(ds,ds+n1,cmp);
	/* hien thi danh sach bang mua hang */
	cout << "Danh sach bang mua hang sau khi sap xep la:" << endl;
	for (int i=0;i<n1;i++){
		ds[i].hienthi();
		cout << endl;
	}
	getch();
}


