#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    float x,y;
public:
    Point();
    ~Point();
    void Input();
    void Output();
    float getLength(Point B);
};

Point::Point()
{

}

Point::~Point()
{

}

void Point::Input()
{
    cout << "Nhap vao toa do: ";
    cin >> x >> y;
}

void Point::Output()
{
    cout << "(" << x << ";" << y << ")" << endl;
}

float Point::getLength(Point B)
{
	return sqrt(pow((B.y-this->y),2)+pow((B.x-this->x),2));
}

main()
{
    Point A[100];
    int n, i, j, ddau, dcuoi;
    float max= 0;
    cout << "Nhap so diem can nhap: ";
    cin >> n;
    cout << endl;
    for (i=0; i<n; i++)
    {
        cout << "Nhap vao toa do diem thu " << i+1 << endl;
        A[i].Input();
    }

    cout << "\nDanh sach toa do da nhap: " << endl;
    for (i=0; i<n; i++)
    {
        A[i].Output();
    }
    
    for(i=0;i<n-1;i++)
    	for(j=i+1;j<n;j++)
    		if(A[i].getLength(A[j]) > max)
    		{
    			max = A[i].getLength(A[j]);
    			ddau=i+1;
    			dcuoi=j+1;
    		}
    		
    cout << "\nDo dai lon nhat = " << max << " giua diem thu " << ddau << " va diem thu " << dcuoi;
}
