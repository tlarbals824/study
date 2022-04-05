#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n,l;
	cin>>n>>l;
	int dp[n][n];

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>dp[i][j];
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		bool flag=true;
		int last=dp[i][0];
		int ch[n]={0};
		for(int j=0;j<n;j++){
			if(last==dp[i][j]) {
				continue;
			}else if(last!=dp[i][j]){
				if(last+1==dp[i][j]){
					bool check=true;
					for(int k=1;k<=l;k++){
						if(dp[i][j-k]!=last||ch[j-k]!=0){
							check=false;
							break;
						}
					}
					if(check){
						for(int k=1;k<=l;k++){
							ch[j-k]=1;
						}
						last=dp[i][j];
					}else{
						flag=false;
						break;
					}
				}
				else if(last==dp[i][j]+1){
					bool check=true;
					for(int k=0;k<l;k++){
						if(dp[i][j+k]!=dp[i][j]){
							check=false;
							break;
						}
					}
					if(check){
						for(int k=0;k<l;k++){
							ch[j+k]=1;
						}
						last=dp[i][j];
					}else{
						flag=false;
						break;
					}
				}else{
					flag=false;
					break;
				}
				
			}
		}
		if(flag) {
			cnt++;
		}
	}
	for(int i=0;i<n;i++){
		bool flag=true;
		int last=dp[0][i];
		int ch[n]={0};
		for(int j=0;j<n;j++){
			if(last==dp[j][i]) {
				continue;
			}else if(last!=dp[j][i]){
				if(last+1==dp[j][i]){
					bool check=true;
					for(int k=1;k<=l;k++){
						if(dp[j-k][i]!=last||ch[j-k]!=0){
							check=false;
							break;
						}
					}
					if(check){
						for(int k=1;k<=l;k++){
							ch[j-k]=1;
						}
						last=dp[j][i];
					}else{
						flag=false;
						break;
					}
				}
				else if(last==dp[j][i]+1){
					bool check=true;
					for(int k=0;k<l;k++){
						if(dp[j+k][i]!=dp[j][i]){
							check=false;
							break;
						}
					}
					if(check){
						for(int k=0;k<l;k++){
							ch[j+k]=1;
						}
						last=dp[j][i];
					}else{
						flag=false;
						break;
					}
				}else{
					flag=false;
					break;
				}
				
			}
		}
		if(flag) {
			cnt++;
		}
	}
	cout<<cnt<<'\n';
}