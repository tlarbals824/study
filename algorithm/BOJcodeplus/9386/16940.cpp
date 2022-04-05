#include<bits/stdc++.h>

using namespace std;

int res[100100];
int tmp[100100];
int ch[100100]={0};
vector<int> dp[100100];
bool cmp(const int&a,const int&b){
	return res[a]<res[b];
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
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
	
	
	queue<int> q;
	q.push(1);
	ch[1]=1;
	int cnt=0;
	
	while(!q.empty()){
		int t=q.front();
		tmp[t]=cnt++;
		q.pop();
		for(int i=0;i<dp[t].size();i++){
			if(ch[dp[t][i]]==0){
				ch[dp[t][i]]=1;
				q.push(dp[t][i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(tmp[i]!=res[i]){
			cout<<0<<'\n';
			return 0;
		}
	}
	cout<<1<<'\n';
	return 0;
}