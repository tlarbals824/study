#include<iostream>
#include<queue>
#include<map>

using namespace std;

int ch[101]={0};
int dp[101];
int cnt[101];
int n,m;
void bfs(){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int i=1;i<7;i++){
            int nextTmp=tmp+i;
            if(nextTmp>100) continue;
            if(ch[nextTmp]!=0){
                nextTmp=dp[nextTmp];    
            }
            if(cnt[nextTmp]==0){
                cnt[nextTmp]=cnt[tmp]+1;
                q.push(nextTmp);
            }
        }
    }
    cout<<cnt[100]<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<100;i++){
        dp[i]=i+1;
        cnt[i]=0;
    }
    for(int i=0;i<n;i++){
        int from,to;
        cin>>from>>to;
        ch[from]=1;
        dp[from]=to;
    }
    for(int i=0;i<m;i++){
        int from,to;
        cin>>from>>to;
        ch[from]=-1;
        dp[from]=to;
    }
    bfs();
}