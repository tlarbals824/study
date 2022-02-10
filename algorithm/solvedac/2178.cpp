#include<iostream>

using namespace std;
int maze[102][102]={0};
bool mazeCheck[102][102]={0};
int dirX[4]={-1,0,1,0};
int dirY[4]={0,1,0,-1};

void dfs(int x,int y){
	
}



int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&maze[i][j]);
	int countMin=0;
	printf("%d",countMin);
}