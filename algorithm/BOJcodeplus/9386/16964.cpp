#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> dp[100100];
int res[100100];
int tmp[100100];
int ch[100100]={0};
int cnt=1;
bool cmp(const int &a,const int &b){
	return res[a]<res[b];
}
void dfs(int start){
	for(int i=0;i<dp[start].size();i++){
		if(ch[dp[start][i]]==0){
			ch[dp[start][i]]=1;
			tmp[dp[start][i]]=cnt++;
			dfs(dp[start][i]);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	for(int i=0;i<n-1;i++){
		int from,to;
		cin>>from>>to;
		dp[from].push_back(to);
		dp[to].push_back(from);
	}
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		res[num]=i;
	}
	for(int i=1;i<=n;i++){
		sort(dp[i].begin(),dp[i].end(),cmp);
	}
	tmp[1]=0;
	ch[1]=1;
	dfs(1);

	for(int i=1;i<=n;i++){
		if(tmp[i]!=res[i]){
			cout<<0<<'\n';
			return 0;
		}
	}
	cout<<1<<'\n';
	return 0;
}