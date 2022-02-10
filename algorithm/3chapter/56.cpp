#include<iostream>

using namespace std;

void nPrint(int a){
	if(a>1){
		nPrint(a-1);
	}
	printf("%d ",a);
}


int main(){
	int num;
	scanf("%d",&num);
	nPrint(num);
}