#include<bits/stdc++.h>

using namespace std;
int res=INT_MAX;
int n,m;

void dfs(long num,int cnt){
	if(num>m) return;
	if(num==m){
		res=min(res,cnt);
	}else{
		dfs(num*2,cnt+1);
		dfs(num*10+1,cnt+1);
	}
}

int main(){
	cin>>n>>m;

	dfs(n,1);
	if(res==INT_MAX) cout<<-1;
	else cout<<res<<'\n';
}