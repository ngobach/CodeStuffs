#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define _i ::iterator
#define MAX_SIZE 1000
using namespace std;
typedef long long LL;

class NhanVien{
	private:
		string ma;
		string ten;
		string ngaysinh;
		int namcongtac;
		int mucluong;
	public:
		NhanVien(string ma = "",string ten = "", string ngaysinh = "", int namcongtac = 0, int mucluong = 0);
		void input();
		void display();
};

void NhanVien::input(){
	cout << "Nhap nhan vien" << endl;
	cout << "Nhap ma nhan vien: "; getline(cin,ma);
	cout << "Nhap ten nhan vien: "; getline(cin,ten);
	cout << "Nhap ngay sinh: "; getline(cin,ngaysinh);
	cout << "Nam cong tac: "; cin >> namcongtac;
	cout << "Muc luong: "; cin >> mucluong;
	cin.ignore();
}
void NhanVien::display(){
	cout << "Thong tin nhan vien" << endl;
	cout << "Ma nhan vien: " << ma << endl;
	cout << "Ten nhan vien: " << ten << endl;
	cout << "Ngay sinh: " << ngaysinh << endl;
	cout << "Nam cong tac: " << namcongtac << endl;
	cout << "Muc luong: " << mucluong << endl;
}

NhanVien::NhanVien(string ma,string ten, string ngaysinh, int namcongtac, int mucluong){
	
}

int main(){
	int n,m;
	NhanVien nv[MAX_SIZE];
	cout << "Nhap so luong nhan vien: ";
	cin >> n;cin.ignore();
	for (int i=0;i<n;i++){
		nv[i].input();
	}
	cout << "Nhap so luong nhan vien bo sung:";
	cin >> m;cin.ignore();
	for (int i=n;i<n+m;i++){
		nv[i].input();
	}
	n+=m;
	
	cout << "Danh sach nhan vien da nhap la: " << endl;
	for (int i=0;i<n;i++)
		nv[i].display();
	return 0;
}

