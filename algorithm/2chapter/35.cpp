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
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-i-1;j++){
			if(num[j]>0&&num[j+1]<0){
				int tmp=num[j];
				num[j]=num[j+1];
				num[j+1]=tmp;
			}
		}
	}
	for(int i=0;i<size;i++){
		printf("%d ",num[i]);
	}
}