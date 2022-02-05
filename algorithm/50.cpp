#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int H,W;
	scanf("%d %d",&H,&W);
	
	int ter[H][W];
	
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			scanf("%d",&ter[i][j]);
		}
	}
	int min=-1;
	
	int x,y;
	scanf("%d %d",&x,&y);
	for(int i=x-1;i<H;i++){
		for(int j=y-1;j<W;j++){
			int sum=0;
			for(int a=0;a<x;a++){
				for(int b=0;b<y;b++){
					sum+=ter[i-a][j-b];
				}
			}
			if(min<sum) min=sum;
		}
	}
	printf("%d\n",min);
	
}