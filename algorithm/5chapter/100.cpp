#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> Coin(n);
	for(int i=0;i<n;i++)
		cin>>Coin[i];
	
	int m;
	cin>>m;
	
	vector<int> DP(m+1,m);
	for(int i=0;i<=m;i++){
		for(int j=0;j<n;j++){
			if(i>=Coin[j])
				DP[i]=min(DP[i],DP[i-Coin[j]]+1);
		}
	}

	cout<<DP[m]<<endl;
}
