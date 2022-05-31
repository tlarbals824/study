#include<iostream>
#include<queue>

using namespace std;

int diry[4]={-1,0,0,1};
int dirx[4]={0,-1,1,0};
int n;
int ocean[30][30];
int ch[30][30]={0};
class Cond{
public:
    int y;
    int x;
    int cnt;
    Cond(int y,int x,int cnt){
        this->y=y;
        this->x=x;
        this->cnt=cnt;
    }
    bool operator<(const Cond& a)const{
        if(cnt!=a.cnt){
            return cnt>a.cnt;
        }else if(y!=a.y){
            return y>a.y;
        }else
            return x>a.x;
    }
};


class Shark {
public:
    int y;
    int x;
    int eatCnt;
    int size;
    void sizeUp(){
        eatCnt=0;
        size++;
    }
    Shark(){
        eatCnt=0;
        size=2;
    }
};

int main(){
    ios_base::sync_with_stdio(false);

    cin>>n;
    Shark s=Shark();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ocean[i][j];
            if(ocean[i][j]==9){
                s.y=i;
                s.x=j;
                ocean[i][j]=0;
            }
        }
    }
    int cnt=0;
    fill(&ch[0][0],&ch[29][30],0);
    priority_queue<Cond> q;
    q.push(Cond(s.y,s.x,0));
    
    while(!q.empty()){
        Cond tmp = q.top();
        q.pop();
        if(ocean[tmp.y][tmp.x]!=0&&ocean[tmp.y][tmp.x]<s.size){
            ocean[tmp.y][tmp.x]=0;
            s.y=tmp.y;
            s.x=tmp.x;
            s.eatCnt++;
            if(s.eatCnt==s.size) s.sizeUp();
            while(!q.empty()) q.pop();
            cnt=tmp.cnt;
            fill(&ch[0][0],&ch[29][30],0);
        }
        for(int i=0;i<4;i++){
            int yy=tmp.y+diry[i];
            int xx=tmp.x+dirx[i];
            if(yy>=n||yy<0||xx>=n||xx<0||
            ocean[yy][xx]>s.size||ch[yy][xx]!=0) continue;
            q.push(Cond(yy,xx,tmp.cnt+1));
            ch[yy][xx]=1;
        }
        
    }
    cout<<cnt<<'\n';
}