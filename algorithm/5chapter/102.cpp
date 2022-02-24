#include<bits/stdc++.h>

using namespace std;

const int UNKNOWN=1e9;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> DP(n+1,vector<int>(n+1,UNKNOWN));
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		DP[a][b]=c;
	}
	

	for(int i=1;i<=n;i++)
		DP[i][i]=0;
	
	for(int mid=1;mid<=n;mid++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(DP[i][j]>DP[i][mid]+DP[mid][j])
					DP[i][j]=DP[i][mid]+DP[mid][j];
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(DP[i][j]!=UNKNOWN)
				cout<<DP[i][j]<<' ';
			else
				cout<<"M ";
		}
		cout<<endl;
	}
	
}