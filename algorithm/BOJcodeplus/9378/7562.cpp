#include<bits/stdc++.h>

using namespace std;

int knightMoveDirX[8]={-2,-1,1,2,2,1,-1,-2};
int knightMoveDirY[8]={-1,-2,-2,-1,1,2,2,1};
int l;
int startx,starty;
int endx,endy;

int dfs(int x,int y){
	int ch[310][310]={0};
	ch[x][y]=1;
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty()){
		int tmpx=q.front().first;
		int tmpy=q.front().second;
		q.pop();
		for(int i=0;i<8;i++){
			int xx=tmpx+knightMoveDirX[i];
			int yy=tmpy+knightMoveDirY[i];
			if(xx>=l||xx<0||yy>=l||yy<0) continue;
			if(ch[xx][yy]==0){
				ch[xx][yy]=ch[tmpx][tmpy]+1;
				q.push({xx,yy});
			}else{
				if(ch[xx][yy]>ch[tmpx][tmpy]+1){
					ch[xx][yy]=ch[tmpx][tmpy]+1;
					q.push({xx,yy});
				}
			}
		}
	}
	return ch[endx][endy]-1;
}


int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	vector<int> res;
	for(int i=0;i<n;i++){
		cin>>l;
		cin>>startx>>starty;
		cin>>endx>>endy;
		cout<<dfs(startx,starty)<<'\n';
	}
}