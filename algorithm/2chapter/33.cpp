#include<stdio.h>
#include<algorithm>
#include<vector>

int main(){
	int size;
	scanf("%d",&size);
	int grade[size];
	for(int i=0;i<size;i++){
		scanf("%d",&grade[i]);
	}
	int idx;
	for(int i=0;i<size;i++){
		idx=i;
		for(int j=i+1;j<size;j++){
			if(grade[idx]<grade[j]) idx=j;
		}
		int tmp=grade[idx];
		grade[idx]=grade[i];
		grade[i]=tmp;
	}
	int count=1;
	for(int i=1;i<size;i++){
		if(grade[i]!=grade[i-1]) count++;
		if(count==3){
			printf("%d\n",grade[i]);
			break;
		}
	}
}