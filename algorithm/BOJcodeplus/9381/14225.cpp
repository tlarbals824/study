#include<bits/stdc++.h>

using namespace std;

vector<int> dp;
int s;
int res[2000100]={0};
int ch[30]={0};
void dfs(int sum,int l){
	if(l==s){
		res[sum]=1;
	}else{
		dfs(sum+dp[l],l+1);
		dfs(sum,l+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>s;
	for(int i=0;i<s;i++){
		int a;
		cin>>a;
		dp.push_back(a);
	}
	dfs(0,0);
	for(int i=1;i<2000100;i++){
		if(res[i]==0){
			cout<<i<<'\n';
			return 0;
		}
	}
}