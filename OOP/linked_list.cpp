#include <iostream>
using namespace std;
typedef int DataT;
typedef void (*DataAction)(DataT &x);

struct Node {
	DataT v;
	Node *next;
};

class LinkedList{
	private:
		Node *head;
		Node *tail;
		int size;
	public:
		LinkedList(){
			init();
		}
		void init(){
			head = NULL;
			tail = NULL;
			size = 0;
		}
  		bool isEmpty(){
			return size==0;
  		}
  		bool isFull(){
  			return false; // neva get full
  		}
  		int getSize(){
  			return size;
  		}
  		void insert(DataT x){
  			Node* n = new Node();
  			n->v = x;
			n->next = NULL;
  			if (isEmpty()){
				head = n;
				tail = n;
  			}else{
  				tail->next = n;
				tail = n;
  			}
  			size++;
  		}
  		void duyet(DataAction act){
  			for (Node *n = head;n!=NULL;n=n->next){
  				act(n->v);
  			}
  		}
};
void hienthi(DataT &x){
	cout << '(' << x << ')';
}
int main(){
	LinkedList *list = new LinkedList();
	list->insert(3);list->insert(5);list->insert(999);
	list->duyet(&hienthi);
	return 0;
}

