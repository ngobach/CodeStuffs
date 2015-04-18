/*****************************************************************************************\
 *
 *		Cay nhi phan tim kiem
 *
 *		La cay ma moi nut cua no chi co toi da 2 nut con, duoc goi la nut trai va nut
 * phai
 *		Nut con ben trai cua 1 nut luon co gia tri nho hon nut cha, va gia tri cua nut cha
 * luon nho hon nut con ben phai
 *		Dac diem cua cay nhi phan tim kiem, la tat ca cac nut con, chau, ... thuoc nut con
 * ben trai cua mot nut deu nho hon no, va cac nut ben phai cua 1 nut deu lon hon no
 *
\*****************************************************************************************/

/* Khai bao thu vien */
#include <iostream>

/* khai bao namespace */
using namespace std;


/***
 * Khai bao cau truct Node
 *
 * @key: gia tri cua node do
 * @L: con tro den node ben trai
 * @R: con tro den node ben phai
 ***/
struct Node{
	int key;
	Node *L,*R;
};

/* Khai bao kieu du lieu NodePtr la con tro den 1 Node */
typedef Node *NodePtr;


/***
 * Ham khoi tao gia tri cho 1 cay nhi phan tim kiem
 *
 * @root: tham chieu den cay can khoi tao
 ***/
void init(NodePtr &root){
	root = NULL;
}


/***
 * Ham tao 1 node voi gia tri la gia tri cua x
 *
 * @x: gia tri ma node duoc tao se mang
 *
 * @return NULL neu nhu khong the tao node (vi bo nho day`)
 * @return con tro den node duoc tao neu nhu tao node thanh cong
 ***/
NodePtr getNode(int x){
	// cap phat bo nho cho 1 node va gan vao bien @node
	NodePtr node = new Node();
	if (node==NULL){
		// ham "new" tra ve NULL, co nghia la bo nho da day
		// @return NULL
		return NULL;
	}else{
		// tao node thanh cong, gan gia tri cua @x cho con tro @node
		node->key = x;
		return node;
	}
}



/***
 * Ham chen 1 so nguyen @x vao cay
 * Neu cay rong (root == null) thi tao node moi voi gia ri cua x va gan cho root
 * con khong thi so sanh gia tri cua @x va gia tri cua @root
 * + neu x lon hon root thi goi de quy voi root moi la root->R
 * + neu x nho hon root thi goi de quy voi root moi la root->R
 *
 * @root: tham chieu den goc cua cay can chen gia tri @x
 * @x: gia tri can chen
 ***/
void insert(NodePtr &root,int x){
	if (root == NULL){
		// tao node moi voi gia tri la @x va gan cho @root
		NodePtr node = getNode(x);
		if (node == NULL){
			// ham getNode tra ve null, bo nho day
			cout << "Bo nho day!!" << endl;
			// dung ham
			return;
		}else{
			// gan node duoc tao cho @root
			root = node;
			// gan xong thoat khoi ham
			return;
		}
	}else{
		// @root co gia tri, so sanh @x va gia tri cua @root
		if (x > root->key){
			// gia tri cua @x lon hon gia tri cua @root
			// goi ham de quy voi root moi la root->R
			insert(root->R,x);
		}else{
			// nguoc lai
			insert(root->L,x);
		}
	}
}

/***
 * Ham nhap du lieu cho cay nhi phan tim kiem
 *
 ***/
void nhap(NodePtr &root){
	int n,x;
	cout << "Nhap so luong node can chen vao: ";
	cin >> n;
	for (int i=0;i<n;i++){
		cout << "Nhap gia tri cho node thu " << i+1 << ": ";
		cin >> x;
		// goi ham chen node
		insert(root,x);
	}
}

/***
 * Ham duyet cay nhi phan tim kiem theo kieu trung thu tu
 * dac diem cua kieu duyet nay la: ket qua in ra phai theo
 * thu tu tang dan.
 * Thu tu duyet se la: duyet trai >> in ra >> duyet phai
 *
 * @root: con tro den cay can duyet
 ***/
void inOrder(NodePtr root){
	// kiem tra root co = NULL ko
	// neu co thi khong in nua va thoat khoi ham
	if (root==NULL)
		return;
	inOrder(root->L); // duyet trai
	cout << root->key << " ";
	inOrder(root->R); // duyet phai
	
}


/***
 * Ham duyet cay nhi phan theo kieu tien thu tu
 * thu tu: inra >> duyet trai >> duyet phai
 *
 * @root: con tro den cay can duyet
 ***/
void preOrder(NodePtr root){
	// kiem tra root co = NULL ko
	// neu co thi khong in nua va thoat khoi ham
	if (root==NULL)
		return;
	cout << root->key << " ";
	preOrder(root->L); // duyet trai
	preOrder(root->R); // duyet phai
}


/***
 * Ham duyet cay nhi phan theo kieu hau thu tu
 * thu tu: duyet trai >> duyet phai >> inra
 *
 * @root: con tro den cay can duyet
 ***/
void postOrder(NodePtr root){
	// kiem tra root co = NULL ko
	// neu co thi khong in nua va thoat khoi ham
	if (root==NULL)
		return;
	postOrder(root->L); // duyet trai
	postOrder(root->R); // duyet phai
	cout << root->key << " ";
}

int main(){
	NodePtr tree;
	// goi ham khoi tao
	init(tree);
	
	// nhap vao cho cay
	nhap(tree);
	
	// duyet cay nhi phan theo kieu trung thu tu
	cout << "Duyet trung thu tu: " << endl;
	inOrder(tree);
	cout << endl;

	// duyet cay nhi phan theo kieu tien thu tu
	cout << "Duyet tien thu tu: " << endl;
	preOrder(tree);
	cout << endl;

	// duyet cay nhi phan theo kieu hau thu tu
	cout << "Duyet hau thu tu: " << endl;
	postOrder(tree);
	cout << endl;
}
