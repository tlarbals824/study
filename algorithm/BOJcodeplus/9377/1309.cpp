#include<bits/stdc++.h>

using namespace std;

int n;
int dp[200020];
int dir[2][3]={{-2,1,2},{-2,-1,2}};

int res=0;

void dfs(int cnt,int l){
	if(cnt==0){
		res++;
	}else{
		for(int i=l;i<=2*n;i++){
			int k=0;
			if(dp[i]) continue;
			bool flag=true;
			if(i%2==0) k=1;
			for(int j=0;j<3;j++){
				if(i+dir[k][j]<1||i+dir[k][j]>2*n) continue;
				if(dp[i+dir[k][j]]) flag=false;
			}
			if(flag){
				dp[i]=1;
				dfs(cnt-1,i+1);
				dp[i]=0;
			}
		}
	}
}


int main(){
	cin>>n;
	for(int i=0;i<=n;i++){
		dp[200020]={0};
		dfs(i,1);
	}
	cout<<res<<'\n';
}