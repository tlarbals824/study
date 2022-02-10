#include<iostream>

using namespace std;

int main(){
	int num;
	scanf("%d",&num);
	int b=0;

	for(int i=1;i<=num;i++){
		int tmp=i;
		while(tmp%5==0){
			b++;
			tmp=tmp/5;
		}
	}
	printf("%d",b);
}