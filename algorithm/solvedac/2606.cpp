#include<iostream>
#include<vector>
using namespace std;

vector<int> a[101];
bool b[101]={0};
int count=-1;

void dfs(int num){
	count++;
	b[num]=true;
	for(int i=0;i<a[num].size();i++){
		if(!b[a[num][i]])
			dfs(a[num][i]);
	}
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);

	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1);
	printf("%d ",count);
}