#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int h,w;
	scanf("%d %d",&h,&w);
	int a[h+1][w+1]={0};
	int dy[h+1][w+1]={0};
	
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++)
			scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			dy[i][j]=dy[i-1][j]+dy[i][j-1]-dy[i-1][j-1]+a[i][j];
	int x,y;
	scanf("%d %d",&x,&y);
	
	int max=-1;
	for(int i=x;i<=h;i++){
		for(int j=y;j<=w;j++){
			int num=dy[i][j]-dy[i][j-y]-dy[i-x][j]+dy[i-x][j-y];
			if(max<num) max=num;
		}
	}
	printf("%d\n",max);
}