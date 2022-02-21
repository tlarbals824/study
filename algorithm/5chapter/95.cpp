#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	vector<int> num(n+1),dy(n+1);
	for(int i=1;i<=n;i++)
		cin>>num[i];
	
	dy[1]=1;
	int res=0;
	for(int i=2;i<=n;i++){
		int Max=0;
		for(int j=i-1;j>0;j--){
			if(num[i]>num[j]&&Max<dy[j]) Max=dy[j];
		}
		dy[i]=Max+1;
		if(res<dy[i]) res=dy[i];
	}
	cout<<res<<endl;

}
