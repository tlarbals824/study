#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
	queue<int> bfs;
	vector<int> map[8];
	for(int i=0;i<6;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		map[x].push_back(y);
	}
	bfs.push(1);
	while(!bfs.empty()){
		int tmp=bfs.front();
		bfs.pop();
		printf("%d ",tmp);
		for(int i=0;i<map[tmp].size();i++){
			bfs.push(map[tmp][i]);
		}
	}
	
}