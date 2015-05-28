#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

class xau
{
private:
    char *str;
    int length;
public:
    xau();
    xau(char *s);
    ~xau();
    void nhap();
    void hienthi();
    char* operator + (xau s);
};

void xau::nhap()
{
    str = new char[100];
    cout << "Nhap xau la ten cua ban: ";
    gets(str);
}

xau::xau()
{
    nhap();
    length = strlen(str);
}

xau::xau(char *s)
{
    str = new char[100];
    strcpy(str,s);
    length = strlen(str);
}

void xau::hienthi()
{
    cout << "+Xau da nhap: " << str << endl << "+Do dai xau: " << length << endl << endl;
}

xau::~xau()
{
    delete str;
}


char* xau::operator + (xau s)
{
    char *a = new char[200];
    strcpy(a,str);
    strcat(a,s.str);
    return a;
}

main()
{
    xau s1;
    s1.hienthi();
    char s[50]=" Ban vua su dung ham tao 1 tham so!";
    xau s2(s);
    s2.hienthi();
    char *a;
    a = s1 + s2;
    cout << "\n\nXau sau khi noi: " << a;
}
