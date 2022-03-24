#include<bits/stdc++.h>

using namespace std;
int n;
int cal[4];
int num[20];
int minres=INT_MAX;
int maxres=-INT_MAX;


void dfs(int cnt,int sum){
	if(cnt==n){
		minres=min(sum,minres);
		maxres=max(sum,maxres);
	}else{
		for(int i=0;i<4;i++){
			if(cal[i]!=0){
				int tmp;
				cal[i]--;
				if(i==0){
					tmp=sum+num[cnt];
				}else if(i==1){
					tmp=sum-num[cnt];
				}else if(i==2){
					tmp=sum*num[cnt];
				}else if(i==3){
					tmp=sum/num[cnt];
				}
				dfs(cnt+1,tmp);
				cal[i]++;
			}
		}
	}
}



int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	for(int i=0;i<4;i++)
		cin>>cal[i];
	
	dfs(1,num[0]);
	cout<<maxres<<'\n'<<minres<<'\n';
}