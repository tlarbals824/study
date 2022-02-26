#include<bits/stdc++.h>

using namespace std;

int DP[510][510]={0};
int ch[510][510];
int res=-1;
int dirX[4]={-1,0,1,0};
int dirY[4]={0,1,0,-1};
int n,m;
void Tetromino4(int x,int y,int cnt,int sum){
	if(cnt==3){
		res=max(res,sum);
	}else{
		for(int i=0;i<4;i++){
			int xx=x+dirX[i];
			int yy=y+dirY[i];
			if(xx<0||xx>=n||yy<0||yy>=m) continue;
			if(!ch[xx][yy]){
				ch[xx][yy]=1;
				Tetromino4(xx,yy,cnt+1,sum+DP[xx][yy]);
				Tetromino4(x,y,cnt+1,sum+DP[xx][yy]);
				ch[xx][yy]=0;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);

	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>DP[i][j];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ch[500][500]={0};
			ch[i][j]=1;
			Tetromino4(i,j,0,DP[i][j]);
		}
	}
	cout<<res;
			
}