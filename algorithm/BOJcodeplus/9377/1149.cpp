#include<bits/stdc++.h>

using namespace std;

int n;
int price[1010][3];

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>price[i][0]>>price[i][1]>>price[i][2];
	}
	
	int prev;
	for(int i=1;i<=n;i++){
		price[i][0]+=min(price[i-1][1],price[i-1][2]);
		price[i][1]+=min(price[i-1][0],price[i-1][2]);
		price[i][2]+=min(price[i-1][1],price[i-1][0]);
	}
	cout<<min(price[n][0],min(price[n][1],price[n][2]));
}