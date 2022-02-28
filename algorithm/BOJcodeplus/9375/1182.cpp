#include<bits/stdc++.h>

using namespace std;
int n,s;
int DP[21];
int cnt=0;

void dfs(int l,int sum){
	if(l==n){
		if(sum==s){
			cnt++;
		}
		return;
	}
	
	dfs(l+1,sum+DP[l]);
	dfs(l+1,sum);

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>s;
	for(int i=0;i<n;i++)
		cin>>DP[i];
	dfs(0,0);
	if(s==0) cnt--;
	cout<<cnt<<'\n';
}