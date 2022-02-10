#include<iostream>
#include<queue>
using namespace std;

int dirX[4]={-1,0,1,0};
int dirY[4]={0,1,0,-1};
bool tomatoCheck[1000][1000]={0};
int tomato[1000][1000];


int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	queue<pair<int,int>> to;
	
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			scanf("%d",&tomato[i][j]);
			if(tomato[i][j]==1) to.push(make_pair(i,j));
		}
	}
	while(!to.empty()){
		
	}
	
	for(int i=0;i<4;i++){
		if(tomato[x+dirX[i]][y+dirY[i]]==0)
	}
	
}