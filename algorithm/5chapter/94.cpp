#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int num[n];
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	int dy[n];
	dy[0]=1;
	for(int i=1;i<n;i++){
		int Max=0;
		for(int j=i-1;j>=0;j--){
			if(num[i]>num[j]){
				if(dy[j]>Max) Max=dy[j];
			}
		}
		dy[i]=Max+1;
	}
	int Max=-1;
	for(int i=0;i<n;i++){
		
		if(Max<dy[i]) Max=dy[i];
	}
	cout<<Max<<endl;
}