#include<bits/stdc++.h>

using namespace std;

int diry[4]={-1,0,1,0};
int dirx[4]={0,-1,0,1};
char dp[30][30];
int n,m;
vector<pair<int,int>> coin;
int res=11;
void dfs(int cnt,int y1,int x1,int y2,int x2){
	if(cnt>10) return;
	
	for(int i=0;i<4;i++){
		int num=0;
		int tmpy1,tmpx1;
		int tmpy2,tmpx2;
		if(dp[y1+diry[i]][x1+dirx[i]]!='#'){
			tmpy1=y1+diry[i];
			tmpx1=x1+dirx[i];
		}else{
			tmpy1=y1;
			tmpx1=x1;
		}
		if(dp[y2+diry[i]][x2+dirx[i]]!='#'){
			tmpy2=y2+diry[i];
			tmpx2=x2+dirx[i];
		}else{
			tmpy2=y2;
			tmpx2=x2;
		}
		if(tmpy1>n||tmpy1<=0||tmpx1>m||tmpx1<=0) num++;
		if(tmpy2>n||tmpy2<=0||tmpx2>m||tmpx2<=0) num++;
		
		if(num==1){
			res=min(cnt,res);
			continue;
		}else if(num==2) continue;
		else{
			dfs(cnt+1,tmpy1,tmpx1,tmpy2,tmpx2);
		}
	}
	
	
}


int main(){
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>dp[i][j];
			if(dp[i][j]=='o'){
				coin.push_back({i,j});
			}
		}
	}
	dfs(1,coin[0].first,coin[0].second,coin[1].first,coin[1].second);
	if(res==11) cout<<-1<<'\n';
	else cout<<res<<'\n';
}