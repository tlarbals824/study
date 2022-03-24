#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	int n,k;	
	cin>>n>>k;
	int dp[100100];
	fill_n(dp,100100,INT_MAX-1);
	dp[n]=0;
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int tmp=q.front();
		if(tmp==k) break;
		q.pop();
		if(tmp+1<100001&&dp[tmp+1]>dp[tmp]+1){
			dp[tmp+1]=dp[tmp]+1;
			q.push(tmp+1);
		} 
		if(tmp-1>=0&&dp[tmp-1]>dp[tmp]+1){
			dp[tmp-1]=dp[tmp]+1;
			q.push(tmp-1);
		}
		if(tmp*2<100001&&dp[tmp*2]>dp[tmp]){
			dp[tmp*2]=dp[tmp];
			q.push(tmp*2);
		}
	}
	cout<<dp[k]<<'\n';
}