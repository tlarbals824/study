#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
char stk[1000];
int tmp=-1;

void push(int n){
	stk[++tmp]=n;
}
char pop(){
	return stk[tmp--];
}

int main(){

	string a="0123456789ABCDEF";
	
	int n,k;
	scanf("%d %d",&n,&k);
	while(n!=0){
		push(a[n%k]);
		n=n/k;
	}
	while(tmp!=-1){
		printf("%c",pop());
	}
	printf("\n");
}