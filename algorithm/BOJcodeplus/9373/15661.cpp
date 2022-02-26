#include<bits/stdc++.h>

using namespace std;

int n;
int DP[30][30];
int team[30]={0};
int res=INT_MAX;

void dfs(int cnt,int l){
	if(l==n+1){
		int s1=0;
		int s2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(team[i]==1&&team[j]==1) s1=s1+DP[i][j];
				else if(team[i]==0&&team[j]==0) s2=s2+DP[i][j];
			}
		}
		res=min(res,abs(s1-s2));
		
	}else{
		for(int i=l;i<=n;i++){
			if(!team[i]){
				team[i]=1;
				dfs(cnt+1,i+1);
				team[i]=0;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>DP[i][j];
		}
	dfs(0,1);
	cout<<res;
}