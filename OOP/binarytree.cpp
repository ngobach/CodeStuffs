#include <iostream>

using namespace std;

struct Node{
	int val;
	Node *left,*right;
	Node(int x){
		val = x;
		left = NULL;right = NULL;
	}
	void put(int x){
		Node **n;
		if (x < val){
			n = &left;
		}else{
			n = &right;
		}
		if (*n == NULL){
			*n = new Node(x);
		}else{
			(*n)->put(x);
		}
	}
	void print(){
		if (left != NULL)
			left->print();
		cout << val << "; ";
		if (right != NULL)
			right->print();
	}
};

struct BinaryTree{
	Node *root;
	BinaryTree(){
		root = NULL;
	}
	void put(int x){
		if (!root){
			root = new Node(x);
		}else{
			root->put(x);
		}
	}
	
	void print(){
		if (root != NULL)
			root->print();
	}
};
int main(){
	int n,x;
	BinaryTree *tree = new BinaryTree();
	cout << "Nhap so luong n: ";
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> x;
		tree->put(x);
	}
	tree->print();
	return 0;
}

