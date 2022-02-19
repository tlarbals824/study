#include<iostream>

using namespace std;

int n,r,cnt;
int a[16];
int ch[16]={0};
int res[16];
void dfs(int x){
	if(x==r){
		for(int i=0;i<r;i++){
			printf("%d ",res[i]);
		}
		cnt++;
		printf("\n");
	}else{
		for(int i=1;i<=n;i++){
			if(!ch[i]){
				res[x]=a[i];
				ch[i]=1;
				dfs(x+1);
				ch[i]=0;
			}
		}
	}
}


int main(){
	scanf("%d %d",&n,&r);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	dfs(0);
	printf("%d\n",cnt);
}