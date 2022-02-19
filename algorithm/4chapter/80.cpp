#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

vector<pair<int,int>> map[21];

struct Dijkstra{
	int vtx;
	int size;
	Dijkstra(int x,int y){
		vtx=x;
		size=y;
	}
	bool operator<(const Dijkstra& a)const{
		return size>a.size;
	}
};

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		map[x].push_back({y,z});
	}
	int vertex[n+1]={0};
	for(int i=2;i<=n;i++)
		vertex[i]=INT_MAX;
	
	priority_queue<Dijkstra> q;
	q.push(Dijkstra(1,0));
	
	while(!q.empty()){
		Dijkstra tmp=q.top();
		q.pop();
		if(tmp.size>vertex[tmp.vtx]) continue;
		for(int i=0;i<map[tmp.vtx].size();i++){
			if(vertex[map[tmp.vtx][i].first]>map[tmp.vtx][i].second+tmp.size){
				vertex[map[tmp.vtx][i].first]=map[tmp.vtx][i].second+tmp.size;
				q.push(Dijkstra(map[tmp.vtx][i].first,map[tmp.vtx][i].second+tmp.size));
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(vertex[i]!=INT_MAX){
			printf("%d : %d\n",i,vertex[i]);
		}else printf("%d : impossible\n",i);
	}
	
}
