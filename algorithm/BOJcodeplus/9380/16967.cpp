#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int h,w,x,y;
	cin>>h>>w>>x>>y;
	int res[h+x][w+y];
	for(int i=0;i<h+x;i++){
		for(int j=0;j<w+y;j++){
			cin>>res[i][j];
		}
	}
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(i>=x&&j>=y){
				res[i][j]=res[i][j]-res[i-x][j-y];
			}
		}
	}
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout<<res[i][j]<<' ';
		}
		cout<<'\n';
	}
	
}