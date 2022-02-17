#include<iostream>

using namespace std;

int maze[9][9];
int cnt=0;
int dirX[4]={-1,0,1,0};
int dirY[4]={0,-1,0,1};

void dfs(int x,int y){
	if(x==7&&y==7){
		cnt++;
	}else{
		maze[x][y]=1;
		for(int i=0;i<4;i++){
			if(maze[x+dirX[i]][y+dirY[i]]==0){
				dfs(x+dirX[i],y+dirY[i]);
				maze[x+dirX[i]][y+dirY[i]]=0;
			}
		}
	}
}

int main(){
	for(int i=1;i<8;i++){
		for(int j=1;j<8;j++){
			scanf("%d",&maze[i][j]);
		}
	}
	for(int i=0;i<9;i++) maze[0][i]=maze[8][i]=1;
	for(int i=1;i<8;i++) maze[i][0]=maze[i][8]=1;
	
	dfs(1,1);
	
	printf("%d\n",cnt);	
}