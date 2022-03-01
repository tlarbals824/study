#include<bits/stdc++.h>

using namespace std;

int res[1000010]={0};
int n;

int dfs(int num){
	if(res[num]!=0) return res[num];
	if(num==1) return res[1]=0;

	if(num%6==0) return res[num]=1+min(dfs(num/3),dfs(num/2));
	else if(num%3==0) return res[num]=1+min(dfs(num/3),dfs(num-1));
	else if(num%2==0) return res[num]=1+min(dfs(num/2),dfs(num-1));
	
	
	return res[num]=1+dfs(num-1);
}


int main(){
	cin>>n;
	cout<<dfs(n)<<'\n';
}