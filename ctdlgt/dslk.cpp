#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* next;
};

class LinkedList{
	private:
		int count;
		Node* head;
	public:
		LinkedList();
		void input();
		void insert(int);
		void insertAt(int,int);
		void deleteAt(int);
		void display();
		int get(int);
		int getCount();
		bool isEmpty();
};

LinkedList::LinkedList(){
	count = 0;
	head = NULL;
}

void LinkedList::input(){
	int n,x;
	cout << "Nhap so luong phan tu muon then vao:";
	cin >> n;
	for (int i=0;i<n;i++){
		cout << "Nhap so muon them thu " << i+1 << ": ";
		cin >> x;
		insert(x);
	}
	count += n;
}

void LinkedList::insert(int val){
	Node* n = new Node();
	n->val = val;
	n->next = NULL;
	
	if (isEmpty()){
		head = n;
	}else{
		Node *t = head;
		while (t->next != NULL) t = t->next;
		t->next = n;
	}
	count++;
}

int LinkedList::getCount(){
	return count;
}

void LinkedList::deleteAt(int pos){
	if (pos < 0 || pos >= count)
		return;
	Node *t;
	t = head;
	if (pos == 0){
		head = head->next;
		delete t;
	}else{
		while (--pos) t = t->next;
		Node *n = t->next;
		t->next = n->next;
		delete n;
	}
	count--;
}

void LinkedList::display(){
	Node *n = head;
	while (n!=NULL){
		cout << n->val;
		n = n->next;
		if (n!=NULL)
			cout << ", ";
		else
			cout << endl;
	}
}

void LinkedList::insertAt(int pos,int val){
	if (pos < 0 || pos > count)
		return;
	Node* n = new Node();
	n->val = val;
	n->next = NULL;
	if (pos == 0){
		// chen dau
		n->next = head;
		head = n;
	}else{
		// chen giua
		Node *t = head;
		while (--pos) t = t->next;
		n->next = t->next;
		t->next = n;
	}
	count++;
}

int LinkedList::get(int pos){
	if (pos < 0 || pos >= count)
		return INT_MIN;
	Node *t = head;
	while (pos--) t = t->next;
	return t->val;
}

bool LinkedList::isEmpty(){
	return count == 0;
}





// ============ tests
void test1(){
	LinkedList ll;
	ll.insert(1);
	ll.insert(3);
	ll.insert(2);
	ll.insert(5);
	ll.insert(6);
	ll.display();
}
void test2(){
	LinkedList ll;
	ll.insert(1);
	ll.insert(3);
	ll.insert(2);
	ll.insert(5);
	ll.insert(6);
	ll.display();
	ll.deleteAt(0);
	ll.deleteAt(9999);
	ll.deleteAt(-100);
	ll.deleteAt(2);
	ll.display();
}
void test3(){
	LinkedList ll;
	ll.insert(1);
	ll.insert(3);
	ll.insert(2);
	ll.insert(5);
	ll.insert(6);
	cout << "Phan tu thu 4: " << ll.get(4) << endl;
}
void test4(){
	LinkedList ll;
	ll.insert(99);
	ll.input();
	ll.insert(88);
	ll.display();
}
int main(){
	cout << "TEST1:" << endl;test1();
	cout << "TEST2:" << endl;test2();
	cout << "TEST3:" << endl;test3();
	cout << "TEST4:" << endl;test4();
	return 0;
}

