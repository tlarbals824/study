#include<stdio.h>
#include<algorithm>
#include<vector>

int main(){
	int num;
	scanf("%d",&num);
	int count=0;
	for(int i=1;i<=num;i++){
		int tmp=i;
		for(;;){
			if(tmp%10==3) count++;
			tmp=tmp/10;
			if(tmp<1) break;
		}
	}
	printf("%d",count);
}