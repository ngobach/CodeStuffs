#include <iostream>
using namespace std;
class Sample{
	private:
		int a,b,c;
		string s;
	public:
		Sample();
		void print();
		void setVar(int a,int b,int c);
		void setString(string s);
};
Sample::Sample(){
	a = -1;
	b = -1;
	c = -1;
	s = "Unset!!!";
}
void Sample::print(){
	cout << "a=("<<a<<"),b=("<<b<<"),c=("<<c<<")" << endl;
	cout << "String: \"" << s << "\"" << endl;
}
void Sample::setVar(int d,int e,int f){
	this->a = d;
	this->b = e;
	this->c = f;
}

void Sample::setString(string s){
	this->s = s;
}
int main(){
	Sample *sp = new Sample();
	sp->setVar(0,6,9);
	//sp->setString("Hello World!!");
	sp->print();
	return 0;
}

