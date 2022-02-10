#include<iostream>

using namespace std;
int ch[11];
int res[11];
int size;
int sum=0;
bool flag=false;

void dfs(int a){
	if(a==size+1){
		int resSum=0;
		for(int i=1;i<=size;i++){
			if(ch[i]==1) resSum+=res[i];
		}
		if(sum/2==resSum) flag=true;
	}else{
		ch[a]=1;
		dfs(a+1);
		ch[a]=0;
		dfs(a+1);
	}
}

int main(){
	scanf("%d",&size);
	for(int i=1;i<=size;i++){
		scanf("%d",&res[i]);
		sum+=res[i];
	}
	dfs(1);
	if(flag) printf("YES\n");
	else printf("NO\n");
}