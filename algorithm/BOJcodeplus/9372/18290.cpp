#include<bits/stdc++.h>

using namespace std;

int M[11][11];
int DP[11][11]={0};
int Max=-1;
int n,m,k;
int dirX[4]={-1,0,1,0};
int dirY[4]={0,1,0,-1};

void dfs(int x,int y){
	
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cin>>M[i][j];
	}
	
	cin>>k;
	
	dfs(1,1);
	
}