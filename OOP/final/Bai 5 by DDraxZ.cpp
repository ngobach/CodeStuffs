#include<iostream>
#include<cstdio>
#include <bits/stdc++.h>

using namespace std;

class Vector
{
private:
    float *v;
    int n;
public:
    Vector();
    Vector(int size);
    Vector(int size, float *a);
    void display();
    ~Vector();
    void clone(Vector s);
};

Vector::Vector()
{
    cout << "\n\nBan da goi ham khoi tao khong tham so!" << endl;
    cout << "Nhap vao so phan tu cua v: ";  cin >> n;
    v = new float[n];
    for(int i=0; i<n; i++)
    {
        cout << "Nhap vao phan tu thu " << i+1 << ": ";
        cin >> v[i];
    }
}

Vector::Vector(int size)
{
    cout << "\n\nBan da goi ham khoi tao 1 tham so!" << endl;
    n=size;
    v = new float[n];
    for(int i=0; i<n; i++)
    {
        cout << "Nhap vao phan tu thu " << i+1 << ": ";
        cin >> v[i];
    }
}

Vector::Vector(int size, float *a)
{
    cout << "\n\nBan da goi ham khoi tao 2 tham so!" << endl;
    n=size;
    v = new float[n];
    for(int i=0; i<n; i++)
        v[i]=a[i];
}

void Vector::display()
{
    cout << "\n\nBan da goi ham hien thi!";
    cout << "\nSo phan tu da nhap: " << n;
    cout << "\nDanh sach phan tu da nhap: ";
    for (int i=0; i<n; i++)
        cout << " " << v[i] << " ";
}

Vector::~Vector()
{
    cout << "\n\nBan da goi den ham huy bo!";
    delete v;
}

void Vector::clone(Vector s)
{
    cout << "\n\n\nBan da goi ham sao chep!" << endl;
    if (v!=NULL)
        delete v;
    n = s.n;
    v = new float[n];
    for(int i=0;i<n;i++)
        v[i]=s.v[i];
}

main()
{
    Vector v;
    v.display();
    Vector v1(5);
    v1.display();
    float a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Vector v2(10,a);
    v2.display();
    v.clone(v2);
    v.display();
}
