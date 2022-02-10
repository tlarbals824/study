#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a[n+2][n+2];
	for(int i=0;i<n+2;i++) a[0][i]=a[n+1][i]=0;
	for(int i=1;i<n+1;i++) a[i][0]=a[i][n+1]=0;
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	int count=0;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			if((a[i][j]>a[i-1][j])&&(a[i][j]>a[i+1][j])
				&&(a[i][j]>a[i][j-1])&&(a[i][j]>a[i][j+1])) count++;
		}
	}
	printf("%d\n",count);
}