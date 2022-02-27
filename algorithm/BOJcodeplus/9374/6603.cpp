#include<bits/stdc++.h>

using namespace  std;

int k;
int num[100]; 
int res[100];
int ch[100];
void dfs(int cnt,int l){
	if(cnt==6){
		for(int i=0;i<6;i++){
			cout<<res[i]<<' ';
		}
		cout<<'\n';
	}else{
		for(int i=l;i<k;i++){
			if(!ch[i]){
				ch[i]=1;
				res[cnt]=num[i];
				dfs(cnt+1,i+1);
				ch[i]=0;
			}
		}
	}
}

int main(){
	
	int prev=0;
	int cnt=0;
	int Line=0;
	while(1){
		cin>>k;
		if(k==0) break;
		for(int i=0;i<k;i++){
			cin>>num[i];
		}
		ch[100]={0};
		dfs(0,0);
		cout<<"\n";
	}
}