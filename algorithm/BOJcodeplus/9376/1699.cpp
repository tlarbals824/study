#include<bits/stdc++.h>

using namespace std;

int n;
int Min=INT_MAX;
int res[100010];
int dfs(int num){
	if(num==0) return 0;
	if(res[num]!=INT_MAX) return res[num];
	for(int i=1;i*i<=num;i++){
		res[num]=min(res[num],dfs(num-i*i)+1);
	}
	return res[num];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		res[i]=INT_MAX;
	cout<<dfs(n)<<'\n';
}