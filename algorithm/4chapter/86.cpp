#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<pair<int,int>> home;
vector<pair<int,int>> pizza;
bool ch[50]={0};
vector<pair<int,int>> selectPizza(13);
int map[52][52];
int n,m;
int cityMin=INT_MAX;

int abs(int num){
	if(num<0) return -num;
	return num;
}


void dfs(int x,int s){
	if(x==m){
		int res=0;
		for(int i=0;i<home.size();i++){
			int min=INT_MAX;
			for(int j=0;j<m;j++){
				int x=abs(home[i].first-selectPizza[j].first);
				int y=abs(home[i].second-selectPizza[j].second);
				int sum=x+y;
				if(min>sum) min=sum;
			}
			res+=min;
		}
		if(cityMin>res) cityMin=res;
	}else{
		for(int i=s;i<pizza.size();i++){
			if(!ch[i]){
				selectPizza[x].first=pizza[i].first;
				selectPizza[x].second=pizza[i].second;
				ch[i]=1;
				dfs(x+1,s+1);
				ch[i]=0;
			}
		}
	}
}


int main(){

	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]==1) home.push_back({i,j});
			else if(map[i][j]==2) pizza.push_back({i,j});
		}
	}
	dfs(0,0);
	printf("%d\n",cityMin);

}