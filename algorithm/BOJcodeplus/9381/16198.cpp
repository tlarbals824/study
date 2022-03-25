#include<bits/stdc++.h>

using namespace std;
int n;
int res=-1;
int dp[20];
void dfs(int sum,int cnt){
	if(cnt==n-2){
		res=max(res,sum);
	}else{
		for(int i=2;i<n;i++){
			if(dp[i]!=0){
				int tmp=dp[i];
				dp[i]=0;
				int s1,s2;
				for(int j=i-1;j>0;j--){
					if(dp[j]!=0){
						s1=dp[j];
						break;
					}
				}
				for(int j=i+1;j<=n;j++){
					if(dp[j]!=0){
						s2=dp[j];
						break;
					}
				}
				dfs(sum+s1*s2,cnt+1);
				dp[i]=tmp;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>dp[i];
	}
	dfs(0,0);
	cout<<res<<'\n';
}