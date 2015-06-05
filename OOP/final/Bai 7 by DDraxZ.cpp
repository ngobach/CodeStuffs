#include<iostream>
#include<iomanip>

using namespace std;

class Time
{
private:
    int h, m, s;
public:
    void setH(int x);
    void setM(int x);
    void setS(int x);
    void setTime(int x, int y, int z);
    void display24();
    void display12();
    void tang();
};

void Time::setH(int x)
{
    if(x>=0 && x<=23)
        h=x;
}

void Time::setM(int x)
{
    if(x>=0 && x<=59)
        m=x;
}

void Time::setS(int x)
{
    if(x>=0 && x<=59)
        s=x;
}

void Time::setTime(int x, int y, int z)
{
    setH(x);
    setM(y);
    setS(z);
}

void Time::display12()
{
    cout << setfill('0') << setw(2)  << h%12 << ':' << setw(2) << m << ':' << setw(2) << s << (h<12? " AM":" PM");
}

void Time::display24()
{
    cout << setfill('0') << setw(2)  << h << ':' << setw(2) <<  m << ':' << setw(2) << s;
}

void Time::tang()
{
    s++;
	m+=s/60;s%=60;
	h+=m/60;m%=60;
	h%=24;
}

main()
{
    Time T;
    T.setTime(23,59,58);
    for (int i=0; i<5; i++)
        {
            T.tang();
            T.display12();
            cout << endl;
            T.display24();
            cout << endl << endl;
        }
}
