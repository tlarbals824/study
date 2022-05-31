#include<iostream>
#include<climits>
#include<queue>

using namespace std;

int Count=10e8;
int r1,c1,r2,c2;
int n;
int diry[6]={-1,1,-2,2,-1,1};
int dirx[6]={-2,-2,0,0,2,2};
int ch[300][300]={0};
void bfs(){
    queue<pair<pair<int,int>, int> > q;
    q.push(make_pair(make_pair(c1,r1),0));
    ch[c1][r1]=1;
    while(!q.empty()){
        int tmpy=q.front().first.first;
        int tmpx=q.front().first.second;
        int cnt=q.front().second;
        q.pop();
        if(tmpy==c2&&tmpx==r2){
            cout<<cnt;
            return;
        }
        for(int i=0;i<6;i++){
            int yy=tmpy+diry[i];
            int xx=tmpx+dirx[i];
            if(yy>n||yy<0||xx>n||xx<0) continue;
            if(ch[yy][xx]) continue;
            ch[yy][xx]=1;
            q.push(make_pair(make_pair(yy,xx),cnt+1));
        }
    }
    cout<<-1<<'\n';

}

int main(){

    ios_base::sync_with_stdio(false);
    cin>>n;
    cin>>r1>>c1>>r2>>c2;
    bfs();

}