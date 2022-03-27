#include<bits/stdc++.h>

using namespace std;

int diry[5]={0,0,0,-1,1};
int dirx[5]={0,1,-1,0,0};
int dice[6]={0,0,0,0,0,0};

void move(int cal){
	if(cal==1){
		int tmp=dice[5];
		dice[5]=dice[3];
		dice[3]=dice[2];
		dice[2]=dice[1];
		dice[1]=tmp;
	}else if(cal==2){
		int tmp=dice[5];
		dice[5]=dice[1];
		dice[1]=dice[2];
		dice[2]=dice[3];
		dice[3]=tmp;
	}else if(cal==3){
		int tmp=dice[5];
		dice[5]=dice[0];
		dice[0]=dice[2];
		dice[2]=dice[4];
		dice[4]=tmp;
	}else{
		int tmp=dice[5];
		dice[5]=dice[4];
		dice[4]=dice[2];
		dice[2]=dice[0];
		dice[0]=tmp;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int n,m,x,y,k;
	cin>>n>>m>>y>>x>>k;
	int dp[30][30];
	queue<int> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>dp[i][j];
		}
	}
	for(int i=0;i<k;i++){
		int c;
		cin>>c;
		q.push(c);
	}
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		int yy=y+diry[tmp];
		int xx=x+dirx[tmp];
		if(yy<0||yy>=n||xx<0||xx>=m) continue;
		y+=diry[tmp];
		x+=dirx[tmp];
		move(tmp);
		if(dp[y][x]==0){
			dp[y][x]=dice[5];
			cout<<dice[2]<<'\n';
		}else{
			
			dice[5]=dp[y][x];
			dp[y][x]=0;
			cout<<dice[2]<<'\n';
		}
	}
}