#include<iostream>
#include<queue>
#include<climits>

using namespace std;

int dir[3]={-1,1,5};

int main(){
	int s,e;
	scanf("%d %d",&s,&e);
	
	
	int ch[10001]={0};
	ch[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		if(tmp==e) {
			printf("%d\n",ch[tmp]);
			break;
		}
		for(int i=0;i<3;i++){
			if(!ch[tmp+dir[i]]){
				q.push(tmp+dir[i]);
				ch[tmp+dir[i]]=ch[tmp]+1;
			}
		}
	}
}