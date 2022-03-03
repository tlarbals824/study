#include<bits/stdc++.h>

using namespace std;

char dp[30][30];
int ch[30][30]={0};
int dirX[4]={-1,0,1,0};
int dirY[4]={0,1,0,-1};
int n;
vector<int> res;
int cnt;
void dfs(int x,int y){
	cnt++;
	ch[x][y]=1;
	for(int i=0;i<4;i++){
		int xx=x+dirX[i];
		int yy=y+dirY[i];
		if(xx>n||xx<1||yy>n||yy<1) continue;
		if(dp[xx][yy]=='1'&&ch[xx][yy]==0){
			dfs(xx,yy);
		}
	}
}


int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>dp[i][j];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i][j]=='1'&&ch[i][j]==0){
				cnt=0;
				dfs(i,j);
				res.push_back(cnt);
			}
		}
	}
	cout<<res.size()<<'\n';
	sort(res.begin(),res.end());
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<'\n';
	}
	
}