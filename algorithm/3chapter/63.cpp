#include<iostream>

using namespace std;


int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int graph[n+1][n+1]={0};
	for(int i=0;i<m;i++){
		int from,to,size;
		scanf("%d %d %d",&from,&to,&size);
		graph[from][to]=size;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
}