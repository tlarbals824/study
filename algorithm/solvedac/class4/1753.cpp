#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> m[20020];
int dp[20020];
int main(){
	ios_base::sync_with_stdio(false);
	

	int v,e,s;
	cin>>v>>e>>s;

	
	for(int i=1;i<=v;i++){
		dp[i]=10e8;
	}
	dp[s]=0;
	for(int i=0;i<e;i++){
		int from,to,cost;
		cin>>from>>to>>cost;
		m[from].push_back({to,cost});
	}
	priority_queue<pair<int,int>> q;
	q.push({0,s});
	while(!q.empty()){
		int dist=-q.top().first;
		int now=q.top().second;
		q.pop();
		if(dp[now]<dist) continue;
		
		for(int i=0;i<m[now].size();i++){
			int cost=dist+m[now][i].second;
			
			if(cost<dp[m[now][i].first]){
				dp[m[now][i].first]=cost;
				q.push({-cost,m[now][i].first});
			}
		}
	}
	
	
	
	
	for(int i=1;i<=v;i++){
		if(dp[i]==10e8) cout<<"INF"<<'\n';
		else cout<<dp[i]<<'\n';
	}
}