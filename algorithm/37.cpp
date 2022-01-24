#include<stdio.h>
#include<algorithm>
#include<vector>

int main(){
	int s,n;
	scanf("%d %d",&s,&n);
	int cache[s]={0};
	for(int x=0;x<n;x++){
		int num;
		scanf("%d",&num);
		int flag=0;
		for(int i=0;i<s;i++){
			if(cache[i]==num){ //cache_Hit
				flag=1;
				for(int j=i-1;j>=0;j--){
					cache[j+1]=cache[j];
				}
				cache[0]=num;
				break;
			}
		}
		if(flag==0){ //cache_Miss
			for(int k=s-2;k>=0;k--){
					cache[k+1]=cache[k];
				}
			cache[0]=num;
		}
		for(int i=0;i<s;i++){
			printf("%d ",cache[i]);
		}
		printf("\n");
	}
	printf("\n");	
	for(int i=0;i<s;i++){
		printf("%d ",cache[i]);
	}
	printf("\n");
}