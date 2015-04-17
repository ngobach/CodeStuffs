#include <iostream>
#define MAXNODE 1000
//      ^ khai bao hang MAXNODE = 1000

using namespace std;

// khai bao kieu du lieu ta se su dung la kieu so nguyen
typedef int DataType;

/**
 * Khai bao cau truc cay
 * @labels: mang chua nhan cua cac nodes
 * @parents: mang chua chi so nut cha cua nut do
 * @count: so nut hien co trong cay
 **/
typedef struct{
	DataType labels[MAXNODE];
	int parents[MAXNODE];
	int count;
} Tree;


/** Ham khoi tao gia tri ban dau cho cay
 * @t: con tro den cay can khoi tao
 **/
void init(Tree *t){
	// dat count = 0
	t->count = 0;
}


/**
 * Ham kiem tra xem 1 cay co ro~ng hay ko
 *
 * @t: con tro den cay can kiem tra
 * @return true neu cay rong
 * @return false neu nguoc lai
 **/
bool empty(Tree *t){
	// neu count bang 0 tuc la rong
	return t->count == 0;
}


/**
 * Hàm kiem tra 1 cay co day hay ko
 *
 * @t: con tro den cay can kiem tra
 * @return true neu cay da day
 * @return false neu chua day
 **/
bool full(Tree *t){
	return t->count == MAXNODE;
}

/**
 * Ham chen 1 nut vao cay
 *
 * @t: con tro den cay can chen vao
 * @x: nhan cua nut duoc chen
 **/
void insert(Tree *t,int parent,DataType x){
	// vi hien tai trong cay da co "count" node
	// nen node tiep theo se co chi so la count
	int nextNode = t->count;
	// gan cha cua node moi la @parent
	t->parents[nextNode] = parent;
	// gan nhan cho node moi la @x
	t->labels[nextNode] = x;
	// tang bien count len
	t->count++;
}

/**
 * Ham yeu cau nhap du lieu cho toan bo cay
 *
 * @t: cay can nhap
 **/
void nhap(Tree *t){
	int n;
	cout << "Nhap so luong nut cua cay: ";
	cin >> n;
	// neu n <= 0 thi thoat khoi ham
	if (n<=0)
		return;
	// yeu cau nhap nhan cho nut goc
	cout << "Nhap nhan cho nut goc: ";
	cin >> t->labels[0];
	// dat cha cua nut goc la -1 theo quy uoc
	t->parents[0] = -1;
	t->count++;
	// nhap vao nhan va cha cua cac nut con lai
	// for tu` 1 vi bo qua nut da nhap cho cha
	for (int i=1;i<n;i++){
		int par;
		DataType x;
		cout << "Nhap cha va nhan cua nut thu " << i << ": ";
		cin >> par >> x;
		if (full(t)){
			cout << "Cay da day!!";
			return;
		} else {
			// goi ham chen them 1 nut vao cay
			insert(t,par,x);
		}
	}
}

/**
 * LeftMostChild: Ham nay tim nut con dau tien cua 1 cay
 *
 * @t: cay can tim
 * @parent: nut can tim nut con dau tien
 *
 * @return -1 neu khong tim thay nut nao ( day la 1 la' )
 * @return mot so nguyen duong chi ra nut con dau tien cua nut can
 */
int lmc(Tree *t,int parent){
	// dac diem cua cay boi mang la
	// tat ca nut con cua 1 nut thi co chi so lon hon nut do
	// nen ta bat dau tim kiem tu parent+1
	for (int i=parent+1;i<t->count;i++){
		if (t->parents[i]==parent){
			// da tim thay nut con dau tien co nut cha la @parent
			return i;
			// sau khi return se thoat luon ra khoi ham
		}
	}
	// neu chuong trinh co the chay den day
	// dieu do co nghia la da chay het vong for
	// nhung van khong the tim thay nut con nao cua nut @parent
	// tra ve -1
	return -1;
}

/**
 * RightSibling: ham nay tim ra em tiep theo cua 1 nut
 *
 * @t: con tro den cay
 * @anh: nut can tim nut em ke tiep
 *
 * @return -1 neu ko co em ( la nut cuoi cung)
 * @return mot so nguyen duong chi ra nut em tiep theo cua @anh
 **/
int rs(Tree *t,int anh){
	// lay nut cha cua @anh
	int par = t->parents[anh];
	// bat dau tim kiem tu nut anh+1
	for (int i=anh+1;i<t->count;i++){
		if (t->parents[i] == par){
			// da tim thay em ke tiep cua @anh
			return i;
		}
	}
	// tuong tu nhu ham @lmc
	return -1;
}


/**
 * Ham duyet cay tien thu tu
 *
 * @t: con tro den cay can duyet
 * @n: node can duyet
 **/
void preOrder(Tree *t,int n){
	// thu tu duyet la: nut do >> trai >> phai
	cout << t->labels[n] << " ";
	// de quy de in cac nut con tu trai sang phai
	// tim cay con dau tien
	int child = lmc(t,n);
	while (child != -1){
		// chung nao child != -1 tuc la van co the in
		preOrder(t,child);
		// tim em ke tiep cua child
		child = rs(t,child);
	}
}


/**
 * Ham duyet cay trung thu tu
 *
 * @t: con tro den cay can duyet
 * viet tuong tu
 **/
void inOrder(Tree *t,int n){
}


/**
 * Ham duyet cay hau thu tu
 *
 * @t: con tro den cay can duyet
 * viet tuong tu
 **/
void postOrder(Tree *t,int n){

}


int main(){
	// khai bao 1 cay
	Tree t;
	// goi ham khoi tao
	init(&t);
	// nhap du lieu cho cay
	nhap(&t);
	// duyet cay
	cout << "Duyet cay tien thu tu la: " << endl;
	preOrder(&t,0);
}
