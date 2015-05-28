#include <iostream>
using namespace std;

class Vector{
	public:
		float *v;
		int n;
	private:
		void nhapn();
		void nhapv();
		void clone(Vector&);
	public:
		
		Vector();
		Vector(int);
		Vector(int,float*);
		Vector(Vector&);
		void display();
		~Vector();
		void operator= (Vector&);
};

void Vector::nhapn(){
	cout << "Nhap n: ";
	cin >> n;
}

void Vector::nhapv(){
	v = new float[n];
	for (int i=0;i<n;i++){
		cout << "Nhap toa do thu " << i+1 << ": ";
		cin >> v[i];
	}
}

void Vector::clone(Vector& vt){
	if (v!=NULL)
		delete v;
	n = vt.n;
	v = new float[n];
	for (int i=0;i<n;i++){
		v[i] = vt.v[i];
	}
}

Vector::Vector(){
	nhapn();
	nhapv();
}

Vector::Vector(int n){
	this->n = n;
	nhapv();
}

Vector::Vector(int n,float *v){
	this->n = n;
	this->v = new float[n];
	for (int i=0;i<n;i++){
		this->v[i] = v[i];
	}
}

Vector::Vector(Vector& vt){
	clone(vt);
}
void Vector::operator=(Vector& vt){
	clone(vt);
}

void Vector::display(){
	cout << "(";
	for (int i=0;i<n;i++){
		cout << v[i] << (i<n-1?", ":")");
	}
	cout << endl;
}

Vector::~Vector(){
	if (v!=NULL)
		delete v;
}

int main(){
	/*
	Vector v1;
	v1.display();
	
	Vector v2(4);
	v2.display();
	*/
	float f[] = {1.2,1.5,5,2.3};
	Vector v3(4, f);
	v3.display();
	
	Vector v4;
	v4.display();
	
	v3 = v4;
	v3.display();
}


