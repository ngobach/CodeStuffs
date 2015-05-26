#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAXN 1000

using namespace std;
typedef long long LL;
LL BIT[MAXN];
void update(int idx,int x){
	while (idx < MAXN){
		BIT[idx] += x;
		cout << "increase " << idx << " by " << x << endl;
		idx += idx & - idx;
	}
}
LL get(int i){
	LL rs = 0;
	while (i > 0){
		rs += BIT[i];
		i -= i & -i;
	}
	return rs;
}
int main(){
	memset(BIT,0,sizeof(BIT));
	update(1,2);
	update(100,4);
	cout << get(101);
	return 0;
}

