#include<bits/stdc++.h>

using namespace std;

int memo[21][21]={0};
int Map[21][21]={0};

int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>Map[i][j];
	memo[1][1]=Map[1][1];
	for(int i=2;i<=n;i++) {
		memo[1][i]=memo[1][i-1]+Map[1][i];
		memo[i][1]=memo[i-1][1]+Map[i][1];
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			memo[i][j]=min(memo[i-1][j],memo[i][j-1])+Map[i][j];
		}
	}
	cout<<memo[n][n]<<endl;
}