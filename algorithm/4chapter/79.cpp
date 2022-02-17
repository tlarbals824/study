#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>

using namespace std;



struct Prim{
public:
	int srt;
	int size;
	Prim(int x,int y){
		srt=x;
		size=y;
	}
	
	bool operator<(const Prim& p)const{
		return size>p.size;
	}
};


int main(){
	int v,e;
	scanf("%d %d",&v,&e);
	vector<pair<int,int>> map[26];
	bool ch[26]={0};
	
	for(int i=0;i<e;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		map[x].push_back({y,z});
		map[y].push_back({x,z});
	}
	
	priority_queue<Prim> prim;
	int res=0;
	prim.push(Prim(1,0));
	
	while(!prim.empty()){
		Prim tmp=prim.top();
		prim.pop();
		if(!ch[tmp.srt]){
			res+=tmp.size;
			ch[tmp.srt]=1;
			for(int i=0;i<map[tmp.srt].size();i++){
				if(!ch[map[tmp.srt][i].first]){
					prim.push(Prim(map[tmp.srt][i].first,map[tmp.srt][i].second));
				}
			}
		}
	}
	printf("%d\n",res);
}