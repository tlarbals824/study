#include<bits/stdc++.h>

using namespace std;

int M[20][20];
int DP[20][20]={0};
int Max=-INT_MAX;
int n,m,k;
int dirX[4]={-1,0,1,0};
int dirY[4]={0,1,0,-1};

void dfs(int cnt,int sum){
	if(cnt==k){
		Max=max(Max,sum);
	}else{
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				bool flag=true;
				if(DP[i][j]) continue;
				else{
					for(int a=0;a<4;a++){
						int xx=i+dirX[a];
						int yy=j+dirY[a];
						if(xx<0||xx>=n||yy<0||yy>=m) continue;
						if(DP[xx][yy]) flag=false;
					}
				}
				if(flag){
					DP[i][j]=1;
					dfs(cnt+1,sum+M[i][j]);
					DP[i][j]=0;
				}
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>M[i][j];
	
	
	dfs(0,0);
	cout<<Max<<endl;
}