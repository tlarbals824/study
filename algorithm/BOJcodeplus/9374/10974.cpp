#include<iostream>

using namespace std;

int n;
int ch[10];
int res[10];
void dfs(int cnt){
	if(cnt==n){
		for(int i=0;i<n;i++){
			cout<<res[i]<<' ';
		}
		cout<<'\n';
	}else{
		for(int i=1;i<=n;i++){
			if(!ch[i]){
				ch[i]=1;
				res[cnt]=i;
				dfs(cnt+1);
				ch[i]=0;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	dfs(0);
}