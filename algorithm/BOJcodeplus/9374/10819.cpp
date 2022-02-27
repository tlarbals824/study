#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> DP;
int res[10];
int ch[10]={0};
int resMax=-1e9;


void dfs(int cnt){
	if(cnt==n){
		int sum=0;
		for(int i=0;i<n-1;i++){
			sum+=abs(res[i]-res[i+1]);
		}
		resMax=max(resMax,sum);
	}else{
		for(int i=0;i<n;i++){
			if(!ch[i]){
				ch[i]=1;
				res[cnt]=DP[i];
				dfs(cnt+1);
				ch[i]=0;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	DP.resize(n);
	for(int i=0;i<n;i++)
		cin>>DP[i];
	dfs(0);
	cout<<resMax<<'\n';
}