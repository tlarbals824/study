#include<bits/stdc++.h>

using namespace std;
int dp[300];
int ch[300];
int main(){
	ios_base::sync_with_stdio(false);
	
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=2*n;i++)
		cin>>dp[i];
	
	queue<int> q;
	for(int i=2*n;i>0;i--){
		q.push(i);
	}
	int cnt=0;
	int r=0;
	while(cnt<k){
		r++;
		//1.
		int start=q.front();
		q.pop();
		q.push(start);
		int end;
		if(start>n+1){
			end=(start+n)%(2*n)-1;
		}else{
			end=start+n-1;
		}
		if(ch[end]==1){
			ch[end]=0;
		}
		//2.
		int tmp=end;
		while(tmp!=start){
			if(tmp==1){
				tmp=2*n;
			}else{
				tmp--;
			}
			if(ch[tmp]==1){
				if(tmp==2*n&&ch[1]==0&&(dp[1]>0)){
					ch[tmp]=0;
					if(end==1) ch[1]=0;
					else ch[1]=1;
					dp[1]--;
					if(dp[1]==0) cnt++;
				}else if(ch[tmp+1]==0&&dp[tmp+1]>0){
					ch[tmp]=0;
					if(tmp+1==end) ch[tmp+1]=0;
					else ch[tmp+1]=1;
					dp[tmp+1]--;
					if(dp[tmp+1]==0) cnt++;
				}
			}
		}
		//3.
		if(dp[start]>0){
			ch[start]=1;
			if(dp[start]==1){
				dp[start]=0;
				cnt++;
			}else dp[start]--;
		}
	}
	cout<<r<<'\n';
	
}