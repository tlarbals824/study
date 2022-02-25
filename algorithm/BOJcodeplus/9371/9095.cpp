#include<bits/stdc++.h>

using namespace std;

int res=0;

void dfs(int n,int sum){
	if(sum==n){
		res++;
	}else{
		if(sum>n) return;
		dfs(n,sum+1);
		dfs(n,sum+2);
		dfs(n,sum+3);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		dfs(a,0);
		cout<<res<<endl;
		res=0;
	}
	
}