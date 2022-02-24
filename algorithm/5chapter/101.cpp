#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	
	int n,m;
	cin>>n>>m;
	vector<int> score;
	vector<int> time;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		score.push_back(a);
		time.push_back(b);
	}
	
	vector<vector<int>> DP(n+1,vector<int>(m+1,0));
	
	for(int i=1;i<=n;i++){
		int currentScore=score[i-1];
		int currentTime=time[i-1];
		for(int j=0;j<=m;j++){
			if(j<currentTime)
				DP[i][j]=DP[i-1][j];
			else
				DP[i][j]=max(DP[i-1][j],DP[i-1][j-currentTime]+currentScore);
		}
	}
	
	cout<<DP[n][m]<<endl;
}