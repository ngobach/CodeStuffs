#include <iostream>
#define PI 3.14159265359
using namespace std;
class Circle{
	private:
		double r;
	public:
		Circle();
		Circle(double r);
		void input();
		void output();
		double perimeter();
		double area();
};
Circle::Circle(){}
Circle::Circle(double r){this->r = r;}
void Circle::input(){
	cout << "Nhap ban kinh r: ";
	cin >> r;
}
void Circle::output(){
	cout << "Ban kinh: " << r << endl;
	cout << "Chu vi: " << perimeter() << endl;
	cout << "Dien tich: " << area() << endl;
}
double Circle::perimeter(){
	return 2*PI*r;
}
double Circle::area(){
	return PI*r*r;
}

int main(){
	Circle c;
	c.input();
	c.output();
}

