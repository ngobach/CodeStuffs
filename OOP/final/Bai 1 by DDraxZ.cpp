#include<iostream>
#define Pi 3.14159265359

using namespace std;

class circle
{
	private:
		float r;
	public:
		void input()
		{
			cout << "Nhap vao ban kinh cua hinh tron r = ";
			cin >> r;
		}
		
		float chuvi()
		{
			return 2*Pi*r; 
		}
		
		float dientich()
		{
			return Pi*r*r;
		}
};

main()
{
	circle A;
	A.input();
	cout << "Chu vi hinh tron la: " << A.chuvi();
	cout << endl;
	cout << "Dien tich hinh tron la: " << A.dientich();
}
