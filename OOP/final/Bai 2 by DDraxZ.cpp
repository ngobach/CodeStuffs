#include<iostream>
#include<cmath>

using namespace std;

struct Point
{
	float x,y;
};

float getLength(Point A, Point B)
{
	return sqrt(pow((A.x-B.x),2)+pow((A.y-B.y),2));
}

class Triangel
{
	private:
		Point A, B, C;
		float a,b,c;
	public:	
		void Input()
		{
			cout << "Nhap vao toa do diem thu nhat: ";
			cin >> A.x >> A.y;
			cout << endl;
			cout << "Nhap vao toa do diem thu hai: ";
			cin >> B.x >> B.y;
			cout << endl;
			cout << "Nhap vao toa do diem thu ba: ";
			cin >> C.x >> C.y;
			cout << endl;
			a=getLength(B,C);
			b=getLength(A,C);
			c=getLength(A,B);
		}
/*		
		bool test()
		{
			if((A.x==B.x && A.y==B.y) || (A.x==C.x && A.y==C.y) || (C.x==B.x && C.y==B.y))
			{
				cout << "Tam giac khong hop le!!!" << " Nhap lai tam giac!" << endl;
				Input();
				return 1;
			}
			else if(getLength(A,B)+getLength(A,C) <= getLength(B,C) || getLength(B,A)+getLength(B,C) <= getLength(A,C) || getLength(C,A)+getLength(C,B) <= getLength(A,B))
			{
				cout << "Tam giac khong hop le!!!" << " Nhap lai tam giac!" << endl;
				Input();
				return 1;
			}
			else return 0;
		}
*/		
		bool test1()
		{
			if((A.x==B.x && A.y==B.y) || (A.x==C.x && A.y==C.y) || (C.x==B.x && C.y==B.y))
			{
				cout << "Tam giac khong hop le!!!" << " Nhap lai tam giac!" << endl;
				Input();
				return 1;
			}
			else if(a+b <= c || a+c <= b || b+c <= a)
			{
				cout << "Tam giac khong hop le!!!" << " Nhap lai tam giac!" << endl;
				Input();
				return 1;
			}
			else return 0;
		}
/*		
		float dientich()
		{
			float p=(getLength(A,B)+getLength(B,C)+getLength(A,C))/2;
			return sqrt(p*(p-getLength(A,B))*(p-getLength(B,C))*(p-getLength(A,C)));
		}
*/		
		
		float dientich()
		{
			float p=(a+b+c)/2;
			return sqrt(p*(p-a)*(p-b)*(p-c));
		}
		
		int ktra()
		{
			if (a==b && b==c && a==c)
				return 1; //tam giac deu
		 	else if (((sqrt(a * a + b * b) == c) && (a == b)) || ((sqrt(a * a + c * c) == b) && (a == c)) || ((sqrt(c* c + b * b) == a) && (c == b)))  
			 	return 2; //tam giac vuong can
		  	else if (( a == b) || (b == c) || (a == c))
			  	return 3; //tam giac can
         	else if ((sqrt(a * a + b * b) == c) || ((sqrt(a * a + c * c) == b)) || (sqrt(c* c + b * b) == a))
			 	return 4; //tam giac vuong
            else
            	return 5; //tam giac thuong
		}
		
		void display()
		{
			cout << "Tam giac da nhap la tam giac ";
			if (ktra() == 1)
				cout << "deu" << endl;
			if(ktra() == 2)
				cout << "vuong can" << endl;
			if(ktra() == 3)
				cout << "can" << endl;
			if(ktra() == 4)
				cout << "vuong" << endl;
			if(ktra() == 5)
				cout << "thuong" << endl;
			cout << "Dien tich tam giac la: " << dientich() << endl;
		}
};

main()
{
	Triangel A;
	A.Input();
	while (A.test1() !=0)
		A.test1();
	A.display();
}