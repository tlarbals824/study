#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		int v,e;	
		int ch[20020]={0};
		bool flag;
		flag=true;
		cin>>v>>e;
		vector<int> dp[v+1];
		for(int j=0;j<e;j++){
			int from,to;
			cin>>from>>to;
			dp[from].push_back(to);
			dp[to].push_back(from);
		}
		
		
		
		
		
		
		
		if(flag){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
}