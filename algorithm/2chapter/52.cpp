#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	
	int a[1501];
	a[1]=1;
	int p2,p3,p5;
	p2=p3=p5=1;
	int min;
	for(int i=2;i<=n;i++){
		if(a[p2]*2<a[p3]*3) min=a[p2]*2;
		else min=a[p3]*3;
		if(a[p5]*5<min) min=a[p5]*5;
		if(min==a[p2]*2) p2++;
		if(min==a[p3]*3) p3++;
		if(min==a[p5]*5) p5++;
		a[i]=min;
	}
	printf("%d\n",a[n]);
}