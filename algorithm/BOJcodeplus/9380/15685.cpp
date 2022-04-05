#include<bits/stdc++.h>

using namespace std;
int dp[200][200];
int diry[4]={0,-1,0,1};
int dirx[4]={1,0,-1,0};
void dfs(int x,int y,int g,int cnt,vector<int> stk,bool flag){
	if(cnt!=g){
		int tmpy=y;
		int tmpx=x;
		int yy,xx;
		for(int i=stk.size()-1;i>=0;i--){
			stk.push_back((stk[i]+3)%4);
			int tmp=(stk[i]+3)%4;
			if(flag){
				if(tmp==1) tmp=3;
				else if(tmp==3) tmp=1;
			}else{
				if(tmp==0) tmp=2;
				else if(tmp==2) tmp=0;
			}
			yy=tmpy+diry[tmp];
			xx=tmpx+dirx[tmp];
			dp[yy][xx]=1;
			tmpy=yy;
			tmpx=xx;
		}
		dfs(xx,yy,g,cnt+1,stk,flag);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y,d,g;
		cin>>x>>y>>d>>g;
		bool flag;
		if(d==0||d==2) flag=true;
		else flag=false;
		vector<int> stk;
		stk.push_back(d);
		dp[y][x]=1;
		dp[y+diry[d]][x+dirx[d]]=1;
		dfs(x+dirx[d],y+diry[d],g,0,stk,flag);
		
	}
	int cnt=0;
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(dp[i][j]==1){
				bool flag=true;
				for(int a=0;a<2;a++){
					for(int b=0;b<2;b++){
						if(dp[i+a][j+b]!=1) flag=false;
					}
				}
				if(flag) cnt++;
			}
		}
	}
	cout<<cnt<<'\n';
}