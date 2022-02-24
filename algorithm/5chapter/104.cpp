#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n,m;
	cin>>n>>m;
	vector<vector<int>> DP(n+1,vector<int>(n+1,0));
	vector<int> degree(n+1);
	queue<int> q;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		DP[a][b]=1;
		degree[b]++;
	}
	for(int i=1;i<=n;i++)
		if(degree[i]==0) q.push(i);
	
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		cout<<tmp<<' ';
		for(int i=1;i<=n;i++){
			if(DP[tmp][i]==1){
				degree[i]--;
				if(degree[i]==0) q.push(i);
			}
		}
	}

	
}