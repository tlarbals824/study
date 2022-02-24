#include<bits/stdc++.h>

using namespace std;

int memo[21][21]={0};
int Map[21][21]={0};

int Run(int x,int y){
	if(memo[x][y]!=0) return memo[x][y];
	if(x==1&&y==1) return memo[1][1]=Map[1][1];
	else{
		if(x==1) return memo[x][y]=Run(x,y-1)+Map[x][y];
		else if(y==1) return memo[x][y]=Run(x-1,y)+Map[x][y];
		else return memo[x][y]=min(Run(x-1,y),Run(x,y-1))+Map[x][y];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>Map[i][j];
	
	cout<<Run(n,n)<<endl;


}