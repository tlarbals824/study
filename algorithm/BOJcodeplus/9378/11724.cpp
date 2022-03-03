#include<bits/stdc++.h>

using namespace std;

vector<int> Map[1010];
int ch[1010]={0};
void dfs(int num){
	for(int i=0;i<Map[num].size();i++){
		if(!ch[Map[num][i]]){
			ch[Map[num][i]]=1;
			dfs(Map[num][i]);   
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		Map[x].push_back(y);
		Map[y].push_back(x);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!ch[i]){
			dfs(i);
			cnt++;
		}
	}
	cout<<cnt<<'\n';
}