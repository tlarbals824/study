#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	
	int count=0;
	int kCount=0;
	int a[n]={0};
	int i=0;
	while(count!=n-1){
		if(a[i]==0){
			kCount++;
		}
		if(kCount==k){
			a[i]=1;
			kCount=0;
			count++;
		}
		
		i=(i+1)%n;
	}
	for(i=0;i<n;i++)
		if(a[i]==0) printf("%d\n",i+1);
}