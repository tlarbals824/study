#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<pair<int,int>> vertex[21];
bool ch[21]={0};
int res=INT_MAX;

void dfs(int srt,int end,int sum){
	if(srt==end){
		if(res>sum)
			res=sum;
	}else{
		for(int i=0;i<vertex[srt].size();i++){
			if(!ch[vertex[srt][i].first]){
				ch[vertex[srt][i].first]=true;
				dfs(vertex[srt][i].first,end,sum+vertex[srt][i].second);
				ch[vertex[srt][i].first]=false;
			}
		}
	}
}


int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int from,to,size;
		scanf("%d %d %d",&from,&to,&size);
		vertex[from].push_back({to,size});
	}
	ch[1]=true;
	dfs(1,n,0);
	
	printf("%d\n",res);
}