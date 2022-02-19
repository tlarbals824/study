#include<iostream>
#include<queue>


using namespace std;

int dirX[4]={-1,0,1,0};
int dirY[4]={0,1,0,-1};
queue<pair<int,int>> q;
int tomatoDay[1010][1010];

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	int map[n+2][m+2];
	int Max=-1;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]==1) q.push({i,j});
		}
	
	for(int i=0;i<m+2;i++) map[0][i]=map[n+1][i]=-1;
	for(int i=1;i<n+1;i++) map[i][0]=map[i][m+1]=-1;
	
	while(!q.empty()){
		int tmpX=q.front().first;
		int tmpY=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			if(map[tmpX+dirX[i]][tmpY+dirY[i]]==0){
				map[tmpX+dirX[i]][tmpY+dirY[i]]=1;
				q.push({tmpX+dirX[i],tmpY+dirY[i]});
				tomatoDay[tmpX+dirX[i]][tmpY+dirY[i]]=tomatoDay[tmpX][tmpY]+1;
			}
		}
	}
	bool ch=true;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(map[i][j]==0){
				ch=false;
			}
		}
	if(!ch){
		printf("-1");
	}else{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(Max<tomatoDay[i][j])
					Max=tomatoDay[i][j];
			}
		printf("%d",Max);
	}
	return 0;
}