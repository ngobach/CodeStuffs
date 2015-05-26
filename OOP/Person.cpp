#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define _i ::iterator
#define FOR(i,a,b) for (int (i)=(a);(i)<b;(i)++)

using namespace std;
typedef long long LL;

class Nguoi{
	private:
		string hoten;
		int ns;
		string que;
		string dc;
	public:
		Nguoi(){};
		Nguoi(string hoten,int ns,string que,string dc);
		~Nguoi();
		void nhap();
		void xuat();
};

class NhanVien : public Nguoi{
	
};

int main(){
	
	return 0;
}

