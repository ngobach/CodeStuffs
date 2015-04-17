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
	return t->count == MAXSIZE;
}

/**
 * Ham chen 1 nut vao cay
 *
 * @t: con tro den cay can chen vao
 * @x: nhan cua nut duoc chen
 **/
void insert(Tree *t,DataType x){

}

/**
 * Ham duyet cay tien thu tu
 *
 * @t: con tro den cay can duyet
 **/
void preOrder(Tree *t){

}


/**
 * Ham duyet cay trung thu tu
 *
 * @t: con tro den cay can duyet
 **/
void inOrder(Tree *t){
}


/**
 * Ham duyet cay hau thu tu
 *
 * @t: con tro den cay can duyet
 **/
void postOrder(Tree *t){

}


int main(){
}
