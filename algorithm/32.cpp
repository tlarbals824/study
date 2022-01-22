#include<stdio.h>
#include<algorithm>
#include<vector>

int main(){
	int size;
	int idx;
	scanf("%d",&size);
	int selectSort[size];
	for(int i=0;i<size;i++){
		scanf("%d",&selectSort[i]);
	}
	for(int i=0;i<size;i++){
		idx=i;
		for(int j=i+1;j<size;j++){
			if(selectSort[idx]>selectSort[j]){
				idx=j;
			}
		}
		int tmp=selectSort[idx];
		selectSort[idx]=selectSort[i];
		selectSort[i]=tmp;
	}
	for(int i=0;i<size;i++){
		printf("%d ",selectSort[i]);
	}
	printf("\n");
}