#include<bits/stdc++.h>

using namespace std;

int main(){
	int size,lit;
	cin>>size>>lit;
	vector<pair<int,int>> knapSack;
	for(int i=0;i<size;i++){
		int a,b;
		cin>>a>>b;
		knapSack.push_back({a,b});
	}
	vector<vector<int>> DP(size+1,vector<int>(lit+1));
	for(int i=1;i<=size;i++){
		int currentWeight=knapSack[i-1].first;
		int currentValue=knapSack[i-1].second;
		for(int j=0;j<=lit;j++){
			if(j<currentWeight){
				DP[i][j]=DP[i-1][j];
			}else{
				DP[i][j]=max(DP[i-1][j],
						max(DP[i-1][j-currentWeight]+currentValue,
						   DP[i][j-currentWeight]+currentValue));
			}
		}
	}
	cout<<DP[size][lit]<<endl;
}