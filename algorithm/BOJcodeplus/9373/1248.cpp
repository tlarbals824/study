#include<bits/stdc++.h>

using namespace std;

int n;
char S[11][11];
int res[11];
bool flag=false;
bool check(int);

void dfs(int cnt){
	if(cnt==n){
		for(int i=0;i<n;i++){
			cout<<res[i]<<' ';
		}
		exit(0);
	}else{
		for(int i=-10;i<=10;i++){
			res[cnt]=i;
			if(check(cnt))
				dfs(cnt+1);
		}
	}
}

bool check(int cnt){
	bool ch=true;
	int sum=0;
	for(int j=cnt;j>=0;j--){
		sum+=res[j];
		if(S[j][cnt]=='+'){
			if(sum<=0) ch=false;
		}else if(S[j][cnt]=='0'){
			if(sum!=0) ch=false;
		}else if(S[j][cnt]=='-'){
			if(sum>=0) ch=false;
		}
		
	}
	return ch;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			cin>>S[i][j];
		}
	}
	
	dfs(0);
}