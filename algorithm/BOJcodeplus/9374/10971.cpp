#include<bits/stdc++.h>

using namespace std;
int n;
int res=INT_MAX;
int DP[20][20];
int ch[20]={0};
void dfs(int start,int y,int cnt,int sum){
	if(cnt==n&&start==y){
		res=min(res,sum);
	}else{
		for(int i=1;i<=n;i++){
			if(!ch[i]){
				ch[i]=1;
				if(DP[y][i]!=0) dfs(start,i,cnt+1,sum+DP[y][i]);
				ch[i]=0;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>DP[i][j];
	
	for(int i=1;i<n;i++){
		dfs(i,i,0,0);
	}
	cout<<res<<'\n';
}