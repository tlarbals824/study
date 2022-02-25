#include<bits/stdc++.h>

using namespace std;

int num[9]={0};
int n,m;

void dfs(int cnt,int s){
	if(cnt==m+1){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(num[j]==i) cout<<j<<' ';
			}
		}
		cout<<endl;
	}else{
		for(int i=s;i<=n;i++){
			if(!num[i]){
				num[i]=cnt;
				dfs(cnt+1,i+1);
				num[i]=0;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;
	
	dfs(1,1);
}