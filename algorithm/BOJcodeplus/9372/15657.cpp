#include<bits/stdc++.h>

using namespace std;

vector<int> inputNum;
int res[9];
int n,m;

void dfs(int cnt,int s){
	if(cnt==m){
		for(int i=0;i<m;i++){
			cout<<res[i]<<' ';
		}
		cout<<'\n';
	}else{
		for(int i=s;i<=n;i++){
			res[cnt]=inputNum[i-1];
			dfs(cnt+1,i);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		inputNum.push_back(a);
	}
	sort(inputNum.begin(),inputNum.end());
	dfs(0,1);
}