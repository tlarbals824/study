#include<iostream>

using namespace std;
int ch[11]={0};
int num;
void dfs(int a){
	if(a==num+1){
		for(int i=1;i<=num;i++)
			if(ch[i]==1) printf("%d ",i);
		printf("\n");
	}else{
		ch[a]=1;
		dfs(a+1);
		ch[a]=0;
		dfs(a+1);
	}
}


int main(){
	scanf("%d",&num);
	dfs(1);
	
}