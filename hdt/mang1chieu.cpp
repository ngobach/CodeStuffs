#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int *a,n;
	cout << "Nhap so phan tu mang: ";
	cin >> n;
	/** CAP PHAT BO NHO DONG CHO MANG **/
	a = new int[n];
	
	/** NHAP VAO MANG **/
	for (int i=0;i<n;i++){
		cout << "a[" << i << "]=";cin >> a[i];
	}
	
	/** HIEN THI MANG SO NGUYEN **/
	cout << "Danh sach da nhap la: " << endl;
	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
	
	/** HIEN THI CAC SO AMSTRONG **/
	cout << "Danh sach cac so Amstrong la: " << endl;
	for (int i=0;i<n;i++){
		int x = a[i],t = 0,d = 0;
		while (x > 0){
			d++;
			x /= 10;
		}
		x = a[i];
		while (x > 0){
			t += pow(x%10,d);
			x /= 10;
		}
		if (t == a[i])
			cout << t << " ";
	}
	
	/** GIAI PHONG BO NHO **/
	delete a;
}
