#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n,m;
	
	scanf("%d",&n);
	vector<int> a(n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	scanf("%d",&m);
	vector<int> b(m);
	for(int i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	int c[30000];
	int aPoint=0,bPoint=0,cPoint;
	while(aPoint<n&&bPoint<m){
		if(a[aPoint]<b[bPoint]) aPoint++;
		else if(a[aPoint]>b[bPoint]) bPoint++;
		else {
			c[cPoint++]=a[aPoint];
			aPoint++;
			bPoint++;
		}
	}
	
	for(int i=0;i<cPoint;i++){
		printf("%d ",c[i]);
	}
	printf("\n");
}