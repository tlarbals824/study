#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,int>> a;
int n;
int Max=-1;

void dfs(int D,int sum){
	if(D>n+1) return;
	else if(D==n+1){
		if(Max<sum) Max=sum;
	}else{
		dfs(D+a[D-1].first,sum+a[D-1].second);
		dfs(D+1,sum);
	}
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		a.push_back({x,y});
	}
	dfs(1,0);
	printf("%d\n",Max);

}