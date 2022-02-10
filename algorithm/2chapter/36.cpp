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
	for(int i=1;i<size;i++){
		int tmp=num[i];
		int j=0;
		for(j=i-1;j>=0;j--){
			if(tmp<num[j]){
				num[j+1]=num[j];
			}else break;
		}
		num[j+1]=tmp;
	}
	for(int i=0;i<size;i++){
		printf("%d ",num[i]);
	}
	printf("\n");
}