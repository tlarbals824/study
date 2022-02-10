#include<iostream>

using namespace std;

int num[11];
int n,m;
int count=0;

void dfs(int a,int sum){
	if(a>n+1) return;
	if(a==n+1&&sum==m) count++;
	else{
		dfs(a+1,sum+num[a]);
		dfs(a+1,sum);
		dfs(a+1,sum-num[a]);
	}
}


int main(){
	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	dfs(1,0);
	if(count!=0) printf("%d\n",count);
	else printf("-1\n");
	
}