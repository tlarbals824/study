#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;
int dp[10][10];
int ch[10][10];
int diry[4]={0,1,0,-1};
int dirx[4]={-1,0,1,0};
int rst=0;

vector<pair<int,int> > v;

void bfs(){
    queue<pair<int,int> > q;
    for(int i=0;i<v.size();i++){
        q.push(make_pair(v[i].first,v[i].second));
        ch[v[i].first][v[i].second]=1;
    }
    while(!q.empty()){
        int tmpy=q.front().first;
        int tmpx=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int yy=tmpy+diry[i];
            int xx=tmpx+dirx[i];
            if(dp[yy][xx]==0&&ch[yy][xx]==0){
                if(yy<0||yy>=n||xx<0||xx>=m) continue;
                ch[yy][xx]=1;
                q.push(make_pair(yy,xx));
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dp[i][j]==0&&ch[i][j]==0) cnt++;
        }
    }
    rst=max(cnt,rst);
}

void dfs(int cnt,int y){
    if(cnt==3){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ch[i][j]=0;
            }
        }
        bfs();
    }else{
        for(int i=y;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==0){
                    dp[i][j]=1;
                    dfs(cnt+1,i);
                    dp[i][j]=0;
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<n;i++){ //n^2
        for(int j=0;j<m;j++){
            cin>>dp[i][j];
            if(dp[i][j]==2){
                v.push_back(make_pair(i,j));
            }
        }
    }
    dfs(0,0);
    cout<<rst<<'\n';
}