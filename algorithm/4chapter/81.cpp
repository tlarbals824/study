#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	vector<pair<int,int>> map[n+1];
	for(int i=0;i<m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		map[x].push_back({y,z});
	}
	int srt,dst;
	scanf("%d %d",&srt,&dst);
	
	int vertex[n+1]={0};
	for(int i=1;i<=n;i++)
		vertex[i]=INT_MAX;
	vertex[srt]=0;
	
	for(int i=0;i<n-1;i++){
		for(int j=1;j<=n;j++){
			if(vertex[j]!=INT_MAX){
				for(int k=0;k<map[j].size();k++){
					if(vertex[map[j][k].first]>vertex[j]+map[j][k].second)
						vertex[map[j][k].first]=vertex[j]+map[j][k].second;
				}
			}
		}
	}
	for(int j=1;j<=n;j++){
		if(vertex[j]!=INT_MAX){
			for(int k=0;k<map[j].size();k++){
				if(vertex[map[j][k].first]>vertex[j]+map[j][k].second){
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	printf("%d\n",vertex[dst]);
}