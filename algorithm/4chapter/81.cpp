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
	
	int vertex[n+1]={0};
	for(int i=2;i<=n;i++)
		vertex[i]=INT_MAX;
	
	for(int i=0;i<n-1;i++){
		
	}
}