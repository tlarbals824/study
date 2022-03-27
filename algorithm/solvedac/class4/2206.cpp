#include<bits/stdc++.h>

using namespace std;
int n,m;
int dp[1010][1010];
int ch[1010][1010][2];
int dirx[4]={-1,0,1,0};
int diry[4]={0,1,0,-1};

int main(){
	
	cin>>n>>m;	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&dp[i][j]);
			ch[i][j][1]=ch[i][j][0]=10e8;
		}
	}
	ch[0][0][1]=1;
	queue<pair<int,pair<int,int>>> q;
	q.push({1,{0,0}});
	while(!q.empty()){
		int y=q.front().second.first;
		int x=q.front().second.second;
		int t=q.front().first;
		q.pop();
		for(int i=0;i<4;i++){
			int tmpy=y+diry[i];
			int tmpx=x+dirx[i];
			if(tmpy<0||tmpx<0||tmpy>=n||tmpx>=m) continue;
			if(dp[tmpy][tmpx]==1){
				if(t==1&&ch[tmpy][tmpx][0]>ch[y][x][1]+1){
					ch[tmpy][tmpx][0]=ch[y][x][1]+1;
					q.push({0,{tmpy,tmpx}});
				}
			}else{
				if(t==1){
					if(ch[tmpy][tmpx][1]>ch[y][x][1]+1){
						ch[tmpy][tmpx][1]=ch[y][x][1]+1;
						q.push({1,{tmpy,tmpx}});
					}
				}else{
					if(ch[tmpy][tmpx][0]>ch[y][x][0]+1){
						ch[tmpy][tmpx][0]=ch[y][x][0]+1;
						q.push({0,{tmpy,tmpx}});
					}
				}
			}
		}
	}
	if(min(ch[n-1][m-1][1],ch[n-1][m-1][0])==10e8) cout<<-1<<'\n';
	else cout<<min(ch[n-1][m-1][1],ch[n-1][m-1][0])<<'\n';
}