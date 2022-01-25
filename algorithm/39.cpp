#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n,m;
	scanf("%d",&n);
	int nNum[n];
	for(int i=0;i<n;i++){
		scanf("%d",&nNum[i]);
	}
	scanf("%d",&m);
	int mNum[m];
	for(int i=0;i<m;i++){
		scanf("%d",&mNum[i]);
	}
	int res[n+m];
	int count=0;
	int i,j;
	for(i=0,j=0;i<n||j<m;){
		if(nNum[i]<mNum[j]){
			res[count++]=nNum[i++];
		}else{
			res[count++]=mNum[j++];
		}
	}
	for(;i<n;){
		res[count++]=nNum[i++];
	}
	for(;j<m;){
		res[count++]=mNum[j++];
	}
	
	for(int i=0;i<n+m;i++){
		printf("%d ",res[i]);
	}
	printf("\n");
}