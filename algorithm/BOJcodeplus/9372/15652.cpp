#include<bits/stdc++.h>

using namespace std;

int num[9]={0};
int res[9];
int n,m;

void dfs(int cnt,int s){
	if(cnt==m){
		for(int i=0;i<m;i++){
			cout<<res[i]<<' ';
		}
		cout<<'\n';
	}else{
		for(int i=s;i<=n;i++){
			res[cnt]=i;
			dfs(cnt+1,i);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;
	
	dfs(0,1);
}