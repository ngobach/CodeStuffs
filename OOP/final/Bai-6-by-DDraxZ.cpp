#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Thisinh
{
private:
    static int dem;
    char mats[10] = "DDL";
    char hoten[50];
    float dtoan, dly, dhoa, tongdiem;
public:
    void Input()
    {
        char temp[20];
        fflush(stdin);
        cout << "Nhap vao ten thi sinh: ";
        gets(hoten);
        cout << "Nhap vao diem toan, ly, hoa: ";
        cin >> dtoan >> dly >> dhoa;
        tongdiem = dtoan + dly + dhoa;
        itoa(dem,temp,10);
        strcat(mats,temp);
        dem++;
        cout << "_________________________________\n";
    }

    void Output()
    {
        cout << mats << ", " << hoten << ", " << dtoan << ", " << dly << ", " << dhoa << endl;
    }

    float getTong()
    {
        return tongdiem;
    }
};

int Thisinh::dem = 110;

main()
{
    Thisinh A[100], temp;
    int i, n, j;
    cout << "Nhap so thi sinh can nhap: ";
    cin >> n;
    for (i=0;i<n;i++)
        A[i].Input();

    for (i=0; i<n; i++)
        A[i].Output();

    temp = A[0];
    for (i=0;i<n-1;i++)
        for (j=i+1;j<n;j++)
            if(A[i].getTong()>A[j].getTong())
                {
                    temp = A[i];
                    A[i]=A[j];
                    A[j]=temp;
                }

    cout << "\n\nDanh sach sinh vien sap xep theo tong diem tang dan: \n";
    for (i=0;i<n;i++)
        A[i].Output();

    cout << "\n\nDanh sach sinh vien co tong diem tren 18: \n";
    for (i=0;i<n;i++)
        if(A[i].getTong()>=18)
            A[i].Output();
}
