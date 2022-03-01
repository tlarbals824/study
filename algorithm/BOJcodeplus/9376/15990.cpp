#include<bits/stdc++.h>

using namespace std;
int n;
long long res[100010][4]={0};
int MOD=1000000009;
int main(){
	int x;
	cin>>x;
	res[1][1]=1;
	res[2][2]=1;
	res[3][1]=res[3][3]=res[3][2]=1;
	
	for(int num=4;num<=100000;num++){
			res[num][1]=(res[num-1][2]+res[num-1][3])%MOD;
			res[num][2]=(res[num-2][1]+res[num-2][3])%MOD;
			res[num][3]=(res[num-3][1]+res[num-3][2])%MOD;
	}
	
	for(int i=0;i<x;i++){
		cin>>n;	
		cout<<(res[n][1]+res[n][2]+res[n][3])%MOD<<'\n';
	}
}