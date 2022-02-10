#include<stdio.h>
#include<algorithm>
#include<vector>

int main(){
	int size;
	scanf("%d",&size);
	int num[size];
	for(int i=0;i<size;i++){
		scanf("%d",&num[i]);
	}
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){
			if(num[j]>num[j+1]){
				int tmp=num[j];
				num[j]=num[j+1];
				num[j+1]=tmp;
			}
		}
	}
	/*
	for(int i=0;i<size-1;i++){
		int exchg=0;
		for(int j=size-1;j>i;j--){
			if(num[j-1]>num[j]){
				exchg++;
				int tmp=num[j];
				num[j]=num[j-1];
				num[j-1]=tmp;
			}
		}
		if(exchg==0) break;
	}
	*/
	for(int i=0;i<size;i++){
		printf("%d ",num[i]);
	}
	printf("\n");
}