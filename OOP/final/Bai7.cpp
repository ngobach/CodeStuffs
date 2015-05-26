#include <iostream>
#include <iomanip>
using namespace std;
class Time{
	private:
		int h,m,s;
	public:
		Time();
		void setHour(int h);
		void setMinute(int m);
		void setSecond(int s);
		void setTime(int h, int m, int s);
		void displayTime24();
		void displayTime12();
		void inc();
};
Time::Time(){
	h=m=s=0;
}

void Time::setHour(int x){
	if (x>=0 && x <24){
		h = x;
	}
}

void Time::setMinute(int x){
	if (x>=0 && x <60){
		m = x;
	}
}

void Time::setSecond(int x){
	if (x>=0 && x < 60){
		s = x;
	}
}

void Time::setTime(int h,int m, int s){
	setHour(h);setMinute(m);setSecond(s);
}
void Time::inc(){
	s++;
	m+=s/60;s%=60;
	h+=m/60;m%=60;
	h%=24;
}
void Time::displayTime24(){
	cout << setw(2) << setfill('0') << h << ':' << setw(2)  <<m << ':' << setw(2) <<s << endl;
}
void Time::displayTime12(){
	cout << setw(2) <<h%13 << ':' << setw(2) <<m << ':' << setw(2) <<s << ' ' << (h<12?"AM":"PM") << endl;
}
int main(){
	Time t;
	t.setTime(23,59,58);
	t.displayTime24();
	for (int i=0;i<5;i++){
		t.inc();
		t.displayTime24();
	}
}

