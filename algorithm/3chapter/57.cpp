#include<iostream>

using namespace std;

void binaryTrans(int a){
	if(a/2!=0)
		binaryTrans(a/2);
	printf("%d",a%2);
}


int main(){
	int num;
	scanf("%d",&num);
	binaryTrans(num);
}