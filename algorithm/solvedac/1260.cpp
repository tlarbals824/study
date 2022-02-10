#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


vector<int> a[1001];
bool b[1001]={0};

void dfs(int num){
	printf("%d ",num);
	b[num]=true;
	for(int i=0;i<a[num].size();i++){
		if(!b[a[num][i]])
			dfs(a[num][i]);
	}
}
void bfs(int num){
	queue<int> c;

	c.push(num);
	b[num]=true;
	while(!c.empty()){
		int tmp=c.front();
		c.pop();
		printf("%d ",tmp);
		for(int i=0;i<a[tmp].size();++i){
			if(!b[a[tmp][i]]){
				c.push(a[tmp][i]);
				b[a[tmp][i]]=true;
			}
		}
	}
	
}


int main(){
	int n,m,v;
	scanf("%d %d %d",&n,&m,&v);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		sort(a[i].begin(),a[i].end());
	}
	fill(b,b+n+1,false);
	dfs(v);
	printf("\n");
	fill(b,b+n+1,false);
	bfs(v);
	printf("\n");
}