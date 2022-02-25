#include<bits/stdc++.h>

using namespace std;

int num[9]={0};
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
			if(!num[i]){
				num[i]=1;
				res[cnt]=inputNum[i-1];
				dfs(cnt+1,i+1);
				num[i]=0;
			}
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