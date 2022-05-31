#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n,m;
int res=10e8;
int dp[60][60];
int ch[60][60];
int virusCh[15]={0};
int diry[4]={-1,0,1,0};
int dirx[4]={0,-1,0,1};

vector<pair<int,int> > v;
void bfs(){
    queue<pair<int,int> > q;
    for(int i=0;i<v.size();i++){
        if(virusCh[i]==1){
            q.push(make_pair(v[i].first,v[i].second));
            ch[v[i].first][v[i].second]=0;
        }
    }
    int tmpCnt=0;
    while(!q.empty()){
        int tmpy=q.front().first;
        int tmpx=q.front().second;
        tmpCnt=max(tmpCnt,ch[tmpy][tmpx]);
        q.pop();
        for(int i=0;i<4;i++){
            int yy=tmpy+diry[i];
            int xx=tmpx+dirx[i];
            if(yy>=n||yy<0||xx>=n||xx<0||dp[yy][xx]==1||ch[yy][xx]!=-1) continue;
            q.push(make_pair(yy,xx));
            ch[yy][xx]=ch[tmpy][tmpx]+1;
        }
    }
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]!=1&&ch[i][j]==-1){
                flag=true;
                break;
            }
        }
    }
    if(!flag) res=min(res,tmpCnt);
}
void dfs(int cnt,int l){
    if(cnt==m){
        fill(&ch[0][0],&ch[n-1][n],-1);
        bfs();
    }else{
        for(int i=l;i<v.size();i++){
            virusCh[i]=1;
            dfs(cnt+1,i+1);
            virusCh[i]=0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dp[i][j];
            if(dp[i][j]==2){
                v.push_back(make_pair(i,j));
            }
        }
    }
    dfs(0,0);
    if(res!=10e8) cout<<res<<'\n';
    else cout<<-1<<'\n';
}