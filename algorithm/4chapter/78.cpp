#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int tree[26]={0};

struct Kruskal{
public:
	int srt;
	int dst;
	int size;
	Kruskal(int x,int y,int z){
		srt=x;
		dst=y;
		size=z;
	}
	
	bool operator<(const Kruskal& k){
		return size<k.size;
	}
};

int Find(int x){
	if(tree[x]==x) return x;
	else return tree[x]=Find(tree[x]);
}

bool Union(int x,int y){
	x=Find(x);
	y=Find(y);
	if(x!=y) {
		tree[x]=y;
		return true;	
	}else return false;
}

int main() {
	int v,e;
	scanf("%d %d",&v,&e);
	vector<Kruskal> kru;
	for(int i=0;i<e;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		Kruskal k(x,y,z);
		kru.push_back(k);
	}
	
	sort(kru.begin(),kru.end());
	
	for(int i=1;i<=v;i++)
		tree[i]=i;
	
	int res=0;
		
	for(int i=0;i<e;i++){
		Kruskal k=kru[i];
		if(Union(k.srt,k.dst)){
			res+=k.size;
		}

	}
	printf("%d\n",res);
	
}