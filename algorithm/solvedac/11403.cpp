#include<iostream>
#include<queue>

using namespace std;

int main(){
	int size;
	scanf("%d",&size);
	int a[size][size];
	int b[size][size]={0};
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++){
			scanf("%d",&a[i][j]);
		}
	
	for(int i=0;i<size;i++){
		queue<int> cross;
		cross.push(i);
		while(!cross.empty()){
			int tmp=cross.front();
			cross.pop();
			for(int j=0;j<size;j++){
				if(a[tmp][j]==1&&b[i][j]==0) {
					b[i][j]=1;
					cross.push(j);
				}
			}
		}
	}
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	
}