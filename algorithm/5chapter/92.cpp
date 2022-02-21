#include<bits/stdc++.h>

using namespace std;

int memo[46]={0};

int netWorkLine(int x){
	if(memo[x]>0) return memo[x];
	if(x==1) return 1;
	else if(x==2) return 2;
	else return memo[x]=netWorkLine(x-1)+netWorkLine(x-2);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	netWorkLine(n);
	cout<<memo[n];
}