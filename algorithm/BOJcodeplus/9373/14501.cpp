#include<bits/stdc++.h>

using namespace std;

int n;
int T[16];
int P[16];
int res=-1;

void dfs(int day,int sum){
	if(day>n+1) return;
	if(day==n+1){
		res=max(res,sum);
	}else{
		dfs(day+1,sum);
		dfs(day+T[day],sum+P[day]);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>T[i]>>P[i];
	}
	dfs(1,0);
	
	cout<<res<<endl;
}