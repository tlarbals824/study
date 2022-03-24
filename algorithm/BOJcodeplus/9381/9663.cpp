#include<bits/stdc++.h>

using namespace std;
int n;
int cnt=0;
int dp[20][20]={0};
void dfs(int c,int y,int x){
	if(c==n){
		cnt++;
	}else{
		if(check(y,x)){
			dp[y][x]=1;
			if(x+1==n){
				dfs(c+1,y+1,0);
			}else{
				dfs(c+1,y,x+1);
			}
			dp[y][x]=0;
			if(x+1==n){
				dfs(c,y+1,0);
			}else{
				dfs(c,y,x+1);
			}
		}else{
			if(x+1==n){
				dfs(c,y+1,0);
			}else{
				dfs(c,y,x+1);
			}
		}
	}
}
bool check(int y,int x){
	//가로
	for(int i=0;i<n;i++){
		if(dp[y][i]==1){
			return false;
		}
	}
	//세로
	for(int i=0;i<n;i++){
		if(dp[i][x]==1){
			return false;
		}
	}
	//대각선1
	for(int )
	//대각선2
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	dfs(0,0,0);
}