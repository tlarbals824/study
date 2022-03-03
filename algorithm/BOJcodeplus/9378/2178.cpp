#include<bits/stdc++.h>

using namespace std;

int n,m;
char dp[120][120];
int ch[120][120]={0};
int dirX[4]={-1,0,1,0};
int dirY[4]={0,1,0,-1};

void dfs(int x,int y){
	if(x==n-1&&y==m-1){
		return;
	}else{
		for(int i=0;i<4;i++){
			int xx=x+dirX[i];
			int yy=y+dirY[i];
			if(xx>=n||xx<0||yy>=m||yy<0) continue;
			if(dp[xx][yy]=='0') continue;
			if(ch[xx][yy]==0){
				ch[xx][yy]=ch[x][y]+1;
				dfs(xx,yy);
			}else{
				if(ch[xx][yy]>ch[x][y]+1){
					ch[xx][yy]=ch[x][y]+1;
					dfs(xx,yy);
				}
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>dp[i][j];
		}
	}
	ch[0][0]=1;
	dfs(0,0);
	cout<<ch[n-1][m-1]<<'\n';
}