#include<bits/stdc++.h>

using namespace std;

int n,m;
char DP[16];
int res=-1;
int ch[16]={0};
void dfs(int sum,int start){
	if(start==n*m){
		res=max(res,sum);
	}else{
		if(ch[start]) {
			dfs(sum,start+1);
		}else{
			//가로방향
			int tmp;
			int cnt=m-start%m;
			for(int i=0;i<cnt;i++){
				tmp=0;
				if(ch[start+i]) break;
				for(int j=0;j<=i;j++){
					tmp=tmp*10+(DP[start+j]-'0');
					ch[start+j]=1;
				}
				dfs(sum+tmp,start+1+i);
				for(int j=0;j<=i;j++){
					ch[start+j]=0;
				}
			}
			//세로방향
			cnt=n-start/m;
			for(int i=0;i<cnt;i++){
				tmp=0;
				if(ch[start+i*m]) break;;
				for(int j=0;j<=i;j++){
					tmp=tmp*10+(DP[start+j*m]-'0');
					ch[start+j*m]=1;
				}
				dfs(sum+tmp,start+1);
				for(int j=0;j<=i;j++){
					ch[start+j*m]=0;
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;
	int a=n*m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>DP[i*m+j];
		}
	}
	
	dfs(0,0);
	cout<<res<<'\n';
	
}