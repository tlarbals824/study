#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n,l;
	cin>>n>>l;
	int dp[n][n];
	int ch[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>dp[i][j];
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		bool flag=true;
		bool check=false;
		int last=dp[i][0];
		int con=0;
		for(int j=0;j<n;j++){
			if(last==dp[i][j]) {
				con++;
			}else if(last!=dp[i][j]){
				if(last+1==dp[i][j]){
					
				}
				else if(last==dp[i][j]+1){
					
				}else{
					flag=false;
					break;
				}
			}
		}
		if(flag) cnt++;
	}
	cout<<cnt<<'\n';
}