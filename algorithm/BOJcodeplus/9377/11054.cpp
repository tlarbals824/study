#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	int num[1010];
	int dpMax[1010];
	int dpMin[1010];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	
	for(int i=0;i<n;i++){
		int Max=0;
		for(int j=0;j<i;j++){
			if(num[i]>num[j])
				Max=max(Max,dpMax[j]);
		}
		dpMax[i]=Max+1;
	}
	for(int i=n-1;i>=0;i--){
		int Max=0;
		for(int j=n-1;j>i;j--){
			if(num[i]>num[j])
				Max=max(Max,dpMin[j]);
		}
		dpMin[i]=Max+1;
	}
	int res=-1;
	for(int i=0;i<n;i++){
		int Max=dpMax[i]+dpMin[i]-1;
		res=max(res,Max);
	}
	cout<<res<<'\n';
	
}