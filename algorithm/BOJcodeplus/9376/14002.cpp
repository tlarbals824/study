#include<bits/stdc++.h>

using namespace std;
int n;
int arr[1010];
int lis[1010]={0};
int dp[1010];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dp[0]=0;
	int Max=-1;
	int MaxIdx=0;
	for(int i=1;i<=n;i++){
		int idx=0;
		int cnt=1;
		for(int j=1;j<i;j++){
			if(arr[i]>arr[j]){
				if(dp[idx]<dp[j]){
					idx=j;
				}
			}
		}
		lis[i]=idx;
		dp[i]=dp[idx]+1;
		if(Max<dp[i]){
			Max=dp[i];
			MaxIdx=i;
		}
	}
	cout<<Max<<'\n';
	vector<int> res;
	int idx=MaxIdx;
	while(1){
		res.push_back(arr[idx]);
		idx=lis[idx];
		if(idx==0) break;
	}
	for(int i=Max-1;i>=0;i--){
		cout<<res[i]<<' ';
	}
}