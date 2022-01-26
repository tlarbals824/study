#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> num(n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	sort(num.begin(),num.end());
	
	int lt=0,rt=n-1;
	while(rt>=lt){
		int mid=(lt+rt)/2;
		if(num[mid]>m){
			rt=mid-1;
		}else if(num[mid]<m){
			lt=mid+1;
		}else{
			printf("%d\n",mid+1);
			break;
		}
	}
}

	