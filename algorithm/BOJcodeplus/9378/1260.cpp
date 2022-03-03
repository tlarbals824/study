#include<bits/stdc++.h>

using namespace std;

vector<int> Map[1010];
int n,m;
int start;
int ch[1010]={0};
void dfs(int num){
	cout<<num<<' ';
	for(int i=0;i<Map[num].size();i++){
		if(!ch[Map[num][i]]){
			ch[Map[num][i]]=1;
			dfs(Map[num][i]);
		}
	}
}
void bfs(int num){
	queue<int> q;
	q.push(num);
	ch[num]=1;
	while(!q.empty()){
		int tmp=q.front();
		cout<<tmp<<' ';
		q.pop();
		for(int i=0;i<Map[tmp].size();i++){
			if(!ch[Map[tmp][i]]){
				q.push(Map[tmp][i]);
				ch[Map[tmp][i]]=1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;
	cin>>start;
	for(int i=0;i<m;i++){
		int from,to;
		cin>>from>>to;
		Map[from].push_back(to);
		Map[to].push_back(from);
	}
	for(int i=1;i<=n;i++){
		sort(Map[i].begin(),Map[i].end());
	}
	ch[start]=1;
	dfs(start);
	cout<<'\n';
	fill(ch,ch+n+1,0);
	bfs(start);
}