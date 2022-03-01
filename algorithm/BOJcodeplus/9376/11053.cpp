#include<bits/stdc++.h>

using namespace std;

int DP[1010]={0};
int NUM[1010];
int n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>NUM[i];
	}
	
	DP[1]=1;
	int cnt=-1;
	for(int i=1;i<=n;i++){
		DP[i]=1;
		for(int j=i-1;j>0;j--){
			if(NUM[i]>NUM[j]){
				DP[i]=max(DP[i],DP[j]+1);
			}
		}
		cnt=max(cnt,DP[i]);
	}
	cout<<cnt<<'\n';
}