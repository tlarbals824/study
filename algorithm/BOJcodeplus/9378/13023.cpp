#include<bits/stdc++.h>

using namespace std;
int n,m;
vector<vector<int>> frd;
vector<int> ch;
bool flag=false;
void dfs(int num,int cnt){
	if(cnt==4){
		flag=true;
		return;
	}else{
		for(int i=0;i<frd[num].size();i++){
			int next=frd[num][i];
			if(ch[next]==0){
				ch[next]=1;
				dfs(next,cnt+1);
				ch[next]=0;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;
	frd.resize(n);
	ch.resize(n);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		frd[a].push_back(b);
		frd[b].push_back(a);
	}
	for(int i=0;i<n;i++){
		fill(ch.begin(),ch.end(),0);
		ch[i]=1;
		dfs(i,0);
		if(flag) break;
	}
	
	if(flag){
		cout<<1<<'\n';
	}else{
		cout<<0<<'\n';
	}
}