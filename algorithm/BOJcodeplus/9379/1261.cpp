#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n,m;
	cin>>n>>m;
	int dp[101][101];
	int ch[101][101];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%1d",&dp[i][j]);
			ch[i][j]=INT_MAX-1;
		}
	}
	
	
	int dirX[4]={-1,0,1,0};
	int dirY[4]={0,1,0,-1};
	
	queue<pair<int,int>> q;
	q.push({1,1});
	ch[1][1]=0;
	
	while(!q.empty()){
		int tmpx=q.front().first;
		int tmpy=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int xx=tmpx+dirX[i];
			int yy=tmpy+dirY[i];
			if(xx>m||xx<1||yy>n||yy<1) continue;
			if(dp[xx][yy]==1){
				if(ch[xx][yy]>ch[tmpx][tmpy]+1){
					ch[xx][yy]=ch[tmpx][tmpy]+1;
					q.push({xx,yy});
				}
			}else{
				if(ch[xx][yy]>ch[tmpx][tmpy]){
					ch[xx][yy]=ch[tmpx][tmpy];
					q.push({xx,yy});
				}
			}
		}
	}
	cout<<ch[m][n]<<'\n';
	
	
}