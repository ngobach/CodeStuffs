#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int **A;
	int m,n;
	cout << "Nhap so hang va so cot: ";
	cin >> m >> n;
	
	/** cap phat bo nho dong **/
	A = new int*[m];
	for (int i=0;i<m;i++){
		A[i] = new int[n];
	}
	/** nhap vao mang 2 chieu **/
	cout << "Nhap vao mang 2 chieu:" << endl;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++){
			cout << "a["<< i <<"]["<< j <<"]=";cin >> A[i][j];
		}			
	/** hien thi mang 2 chieu da nhap **/
	cout << "Mang vua nhap la:" << endl;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++)
			cout << setw(5) << A[i][j];
		cout << endl;
	}
	
	/** hien thi cac phan tu lon nhat tren moi hang **/
	cout << "Cac phan tu lon nhat tren moi hang la: " << endl;
	for (int i=0;i<m;i++){
		int maxnum = A[i][0];
		for (int j=1;j<n;j++){
			maxnum = max(maxnum,A[i][j]);
		}
		cout << maxnum << " ";
	}
	cout << endl;
	
	/** hien thi cac phan tu nho nhat tren moi cot **/
	cout << "Cac phan tu nho nhat tren moi cot la: " << endl;
	for (int i=0;i<n;i++){
		int minnum = A[0][i];
		for (int j=1;j<m;j++){
			minnum = min(minnum,A[j][i]);
		}
		cout << minnum << " ";
	}
	cout << endl;
	
	/** giai phong bo nho **/
	for (int i=0;i<m;i++)
		delete A[i];
	delete A;
}

