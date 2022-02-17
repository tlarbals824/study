#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
	vector<int> map[21];
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		map[x].push_back(y);
	}
	
	int dis[n+1]={0};
	bool ch[n+1]={0};
	ch[1]=1;
	queue<int> q;
	q.push(1);
	
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		for(int i=0;i<map[tmp].size();i++){
			if(!ch[map[tmp][i]]){
				q.push(map[tmp][i]);
				dis[map[tmp][i]]=dis[tmp]+1;
				ch[map[tmp][i]]=1;
			}
		}
	}
	
	for(int i=2;i<=n;i++){
		printf("%d : %d\n",i,dis[i]);
	}
}