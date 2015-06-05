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


class dsts
{
    private:
        Thisinh dsts[100];
        int n;
    public:
        void Nhapds()
        {
            int  i;
            cout << "Nhap so thi sinh can nhap: ";
            cin >> n;
            for (i=0;i<n;i++)
            {
                cout << "Nhap thi sinh thu " << i+1 << endl;
                dsts[i].Input();
            }
        }

        void Hthids()
        {
            cout << "\n\nDanh sach thi sinh da nhap vao: \n";
            for (int i=0;i<n;i++)
                dsts[i].Output();
        }

        void Sapxep()
        {
            int i,j;
            Thisinh temp;
            for (i=0;i<n-1;i++)
                for (j=i+1;j<n;j++)
                    if(dsts[i].getTong()>dsts[j].getTong())
                        {
                            temp = dsts[i];
                            dsts[i]=dsts[j];
                            dsts[j]=temp;
                        }
                cout << "\n\nDanh sach sinh vien sap xep theo tong diem tang dan: \n";
                    for (i=0;i<n;i++)
                        dsts[i].Output();
        }

        void Hthids2()
        {
             cout << "\n\nDanh sach sinh vien co tong diem tren 18: \n";
                for (int i=0;i<n;i++)
                    if(dsts[i].getTong()>=18)
                        dsts[i].Output();
        }
};

main()
{
    dsts A;
    A.Nhapds();
    A.Hthids();
    A.Sapxep();
    A.Hthids2();
}
