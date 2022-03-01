#include<bits/stdc++.h>

using namespace std;

int n;
long DP[110][11]={0};
long MOD=1000000000;

int main(){
	cin>>n;
	
	for(int i=1;i<10;i++){
		DP[1][i]=1;
		DP[1][10]=DP[1][10]+DP[1][i];
	}
	
	for(int i=2;i<=n;i++){
		for(int j=0;j<10;j++){
			int a=0;
			int b=0;
			if(j-1>=0) a=DP[i-1][j-1];
			if(j+1<10) b=DP[i-1][j+1];
			
			DP[i][j]=(a+b)%MOD;
			DP[i][10]=(DP[i][j]+DP[i][10])%MOD;
		}
	}
	cout<<DP[n][10]<<'\n';

}