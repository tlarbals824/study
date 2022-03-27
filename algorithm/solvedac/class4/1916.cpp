#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> m[1010];
int n,a;

int main(){
	ios_base::sync_with_stdio(false);
	cin>>n>>a;
	for(int i=0;i<a;i++){
		int from,to,cost;
		cin>>from>>to>>cost;
		m[from].push_back({to,cost});
	}
	int start,end;
	cin>>start>>end;
	int dp[n+1];
	for(int i=1;i<=n;i++)
		dp[i]=10e8;
	
	
	priority_queue<pair<int,int>> q;
	q.push({0,start});
	dp[start]=0;
	while(!q.empty()){
		int dist=-q.top().first;
		int cur=q.top().second;
		q.pop();
		if(dp[cur]<dist) continue;
		
		for(int i=0;i<m[cur].size();i++){
			int cost=dist+m[cur][i].second;
			if(cost<dp[m[cur][i].first]){
				dp[m[cur][i].first]=cost;
				q.push({-cost,m[cur][i].first});
			}
		}
	}
	if(dp[end]!=10e8) cout<<dp[end]<<'\n';
	else cout<<-1<<'\n';
}