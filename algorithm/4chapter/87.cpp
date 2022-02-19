#include<iostream>
#include<queue>

using namespace std;

int dirX[8]={-1,0,1,0,-1,1,-1,1};
int dirY[8]={0,-1,0,1,-1,-1,1,1};
int map[22][22]={0};
int cnt=0;

void bfs(int x,int y){
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty()){
		int tmpX=q.front().first;
		int tmpY=q.front().second;
		q.pop();
		map[tmpX][tmpY]=0;
		for(int i=0;i<8;i++){
			if(map[tmpX+dirX[i]][tmpY+dirY[i]]==1)
				q.push({tmpX+dirX[i],tmpY+dirY[i]});
		}
	}
	cnt++;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&map[i][j]);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(map[i][j]==1)
				bfs(i,j);
	
	printf("%d\n",cnt);
}