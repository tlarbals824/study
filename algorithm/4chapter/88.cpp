#include<iostream>
#include<queue>

using namespace std;

int map[9][9];
int dirX[4]={-1,0,1,0};
int dirY[4]={0,1,0,-1};
int cntMap[9][9];



int main(){
	for(int i=1;i<=7;i++)
		for(int j=1;j<=7;j++)
			scanf("%d",&map[i][j]);
	
	for(int i=0;i<9;i++) map[0][i]=map[8][i]=1;
	for(int i=1;i<8;i++) map[i][0]=map[i][8]=1;
	
	queue<pair<int,int>> q;
	q.push({1,1});
	while(!q.empty()){
		int tmpX=q.front().first;
		int tmpY=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			if(map[tmpX+dirX[i]][tmpY+dirY[i]]==0){
				if(cntMap[tmpX+dirX[i]][tmpY+dirY[i]]==0)
					cntMap[tmpX+dirX[i]][tmpY+dirY[i]]=cntMap[tmpX][tmpY]+1;
				else
					if(cntMap[tmpX][tmpY]+1<cntMap[tmpX+dirX[i]][tmpY+dirY[i]])
						cntMap[tmpX+dirX[i]][tmpY+dirY[i]]=cntMap[tmpX][tmpY]+1;
				map[tmpX][tmpY]=1;
				q.push({tmpX+dirX[i],tmpY+dirY[i]});
			}
		}
	}
	if(cntMap[7][7]==0) printf("-1\n");
	else printf("%d\n",cntMap[7][7]);
	
}