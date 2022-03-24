#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int s;
	bool dp[1010][1010]={false};
	queue<pair<int,pair<int,int>>> q;
	cin>>s;
	q.push({1,{0,0}});
	while(!q.empty()){
		int cnt=q.front().first;
		int time=q.front().second.first;
		int ch=q.front().second.second;
		q.pop();
		if(cnt==s){
			cout<<time<<'\n';
			return 0;
		}
		if(cnt-1>0&&!dp[cnt-1][ch]) {
			q.push({cnt-1,{time+1,ch}});
			dp[cnt-1][ch]=1;
		}
		if(cnt+ch<1001&&ch!=0&&!dp[cnt+ch][ch]) {
			q.push({cnt+ch,{time+1,ch}});
			dp[cnt+ch][ch]=1;
		}
		if(cnt!=0&&!dp[cnt][cnt]) {
			q.push({cnt,{time+1,cnt}});
			dp[cnt][cnt]=1;
		}
	}
}