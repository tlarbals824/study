#include<bits/stdc++.h>

using namespace std;
int dp[10][10];
vector<pair<int,int>> s;
void dfs(int cnt,int m){
	if(cnt!=m){
		int ch[10]={0};
		int y=s[cnt].first;
		int x=s[cnt].second;
		for(int i=0;i<9;i++){
			ch[dp[y][i]]=1;
			ch[dp[i][x]]=1;
		}
		int tmpy=y/3;
		int tmpx=x/3;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				int tmp=dp[tmpy*3+i][tmpx*3+j];
				ch[tmp]=1;
			}
		}
		for(int i=1;i<10;i++){
			if(ch[i]==0){
				dp[y][x]=i;
				dfs(cnt+1,m);
				dp[y][x]=0;
			}
		}
	}else{
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<dp[i][j]<<' ';
			}
			cout<<'\n';
		}
		exit(0);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	
	int cnt=0;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>dp[i][j];
			if(dp[i][j]==0){
				s.push_back({i,j});
				cnt++;
			}
		}
	}

	dfs(0,cnt);
}