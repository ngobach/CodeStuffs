#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <conio.h>
#define EPS .00001
using namespace std;

struct TriangleP {
	bool can;
	bool deu;
	bool vuong;
};
class Triangle{
	private:
		int a,b,c;
	public:
		void input();
		void output();
		int perimeter();
		double area();
		TriangleP check();
};
void Triangle::input(){
	do{
		cout << "Nhap 3 canh cua tam giac: ";
		cin >> a >> b >> c;
	}while (a+b<=c||a+c<=b||b+c<=a);
}
TriangleP Triangle::check(){
	TriangleP tp = {false,false,false};
	int arr[] = {a,b,c};
	sort(arr,arr+3);
	if (arr[0]==arr[2])
		tp.deu = true;
	else if (arr[0]==arr[1] || arr[1]==arr[2]){
		tp.can = true;
	}
	if (abs(arr[2]-sqrt(arr[0]*arr[0]+arr[1]*arr[1])) < EPS)
		tp.vuong = true;
	return tp;
}
void Triangle::output(){
	TriangleP tp = check();
	cout << "3 canh tam giac la: " << a << ", " << b << ", " << c << endl;
	cout << "Chu vi la: " << perimeter() << endl;
	cout << "Dien tich la: " << area() << endl;
	if (tp.deu){
		cout << "Tam giac deu!" << endl;
	}else if (tp.can && tp.vuong){
		cout << "Tam giac vuong can!" << endl;
	}else if (tp.can){
		cout << "Tam giac can!" << endl;
	}else if (tp.vuong){
		cout << "Tam giac vuong!" << endl;
	}else{
		cout << "Tam giac thuong." << endl;
	}
	cout << endl << endl;
}
int Triangle::perimeter(){
	return a+b+c;
}
double Triangle::area(){
	double p = perimeter()*1.0/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main(){
	Triangle t;
	while (true){
		t.input();
		t.output();
		fflush(stdin);
		cout << "An Q de thoat hoac nut bat ki de tiep tuc!" << endl;
		if (tolower(getch()) == 'q')
			exit(0);
	}
}

