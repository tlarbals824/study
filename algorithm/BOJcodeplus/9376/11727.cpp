#include<bits/stdc++.h>

using namespace std;

int n;
int res[1010]={0};
int dfs(int cnt){
	if(cnt<=1) return 1;
	if(cnt==2) return 3;
	if(res[cnt]) return res[cnt];
	res[cnt]=(dfs(cnt-2)*2+dfs(cnt-1))%10007;
	return res[cnt];
}

int main(){
	cin>>n;
	cout<<dfs(n);
}