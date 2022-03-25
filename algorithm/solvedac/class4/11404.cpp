#include<bits/stdc++.h>

using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int Mod=10e8;
	int res[200][200];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			res[i][j]=Mod;
		}
	}
	for(int i=0;i<m;i++){
		int from,to,cost;
		cin>>from>>to>>cost;
		res[from][to]=min(res[from][to],cost);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(res[i][j]>res[i][k]+res[k][j])
					res[i][j]=res[i][k]+res[k][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j||res[i][j]==Mod) cout<<0<<' ';
			else cout<<res[i][j]<<' ';
		}
		cout<<'\n';
	}
}