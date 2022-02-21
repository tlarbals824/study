#include<iostream>
#include<queue>

using namespace std;

int dirX[4]={-1,0,1,0};
int dirY[4]={0,1,0,-1};

struct Cond{
	int x,y,dist;
	Cond(int i,int j,int d){
		x=i;
		y=j;
		dist=d;
	}
	bool operator<(const Cond& a)const{
		if(dist!=a.dist)
			return dist>a.dist;
		else if(x!=a.x)
			return x>a.x;
		else 
			return y>a.y;
	}
};

struct Simba{
	int x,y,size,ate;
	void sizeUp(){
		size++;
		ate=0;
	}
};

int main(){
	int n,res=0;
	scanf("%d",&n);
	int map[n+1][n+1];
	int ch[n+1][n+1]={0};
	Simba simba;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]==9){
				simba.x=i;
				simba.y=j;
				map[i][j]=0;
			}
		}
	}
	
	priority_queue<Cond> q;
	q.push(Cond(simba.x,simba.y,0));
	simba.size=2;
	simba.ate=0;
	while(!q.empty()){
		Cond tmp=q.top();
		q.pop();
		if(map[tmp.x][tmp.y]!=0&&map[tmp.x][tmp.y]<simba.size){
			simba.x=tmp.x;
			simba.y=tmp.y;
			simba.ate++;
			if(simba.ate>=simba.size) simba.sizeUp();
			map[tmp.x][tmp.y]=0;
			while(!q.empty()) q.pop();
			res=tmp.dist;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					ch[i][j]=0;
		}
		for(int i=0;i<4;i++){
			int xx=tmp.x+dirX[i];
			int yy=tmp.y+dirY[i];
			if(xx<1||xx>n
			  ||yy<1||yy>n
			  ||map[xx][yy]>simba.size
			  ||ch[xx][yy]!=0)
				continue;
			q.push(Cond(xx,yy,tmp.dist+1));
			ch[xx][yy]=1;
		}
	}
	printf("%d\n",res);
}

