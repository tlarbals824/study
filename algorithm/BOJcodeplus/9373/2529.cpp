#include<bits/stdc++.h>

using namespace std;

int k;
string minResString;
string maxResString;
char sighOfInequality[10];
int ch[10]={0};
int res[10];
long Min=LONG_MAX;
long Max=-1;

void dfs(int cnt){
	if(cnt==k+1){
		for(int i=0;i<k;i++){
			if(sighOfInequality[i]=='<')
				if(res[i]>res[i+1]) return;
			if(sighOfInequality[i]=='>')
				if(res[i]<res[i+1]) return;
		}
		long tmp=0;
		char tmp_s[k+1];
		for(int i=0;i<=k;i++){
			tmp=tmp*10+res[i];
			tmp_s[i]=res[i]+'0';
		}
		if(Min>tmp) {
			Min=tmp;
			minResString=tmp_s;
		}
		if(Max<tmp){ 
			Max=tmp;
			maxResString=tmp_s;
		}
		
	}else{
		for(int i=0;i<10;i++){
			if(!ch[i]){
				ch[i]=1;
				res[cnt]=i;
				dfs(cnt+1);
				ch[i]=0;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>k;
	for(int i=0;i<k;i++)
		cin>>sighOfInequality[i];

	dfs(0);
	
	for(int i=0;i<=k;i++){
		cout<<maxResString[i];
	}
	cout<<'\n';
	for(int i=0;i<=k;i++){
		cout<<minResString[i];
	}
}
	