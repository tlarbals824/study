#include<iostream>
#include<vector>
using namespace std;

vector<int> vtx[21];
int b[21]={0};
int cnt=0;
int n,m;

void dfs(int a){
	if(a==n) {
		cnt++;
	}
	else{
		for(int i=0;i<vtx[a].size();i++){
			if(b[vtx[a][i]]==false){
				b[vtx[a][i]]=true;
				dfs(vtx[a][i]);
				b[vtx[a][i]]=false;
			}
		}
	}
}

int main(){

	scanf("%d %d",&n,&m);

	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		vtx[x].push_back(y);
	}
	b[1]=1;
	dfs(1);
	
	printf("%d\n",cnt);
}