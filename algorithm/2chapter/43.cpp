#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int num[n];
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	
	int sum=0;
	int max=num[0];
	for(int i=0;i<n;i++){
		sum+=num[i];
		if(max<num[i]) max=num[i];
	}
	
	int lt=1,rt=sum;
	int res;
	int mid;
	while(rt>=lt){
		mid=(lt+rt)/2;
		int count=1;
		int sum1=0;
		for(int i=0;i<n;i++){
			sum1+=num[i];
			if(sum1>mid){
				count++;
				sum1=num[i];
				continue;
			}
		}
		if(mid>=max&&count<=m){
			res=mid;
			rt=mid-1;
		}else{
			lt=mid+1;
		}
	}
	printf("%d\n",res);
}

