#include<bits/stdc++.h>

using namespace std;
int ch[4001000];
int main(){
	int n;
	cin>>n;
	if(n==1){
		cout<<0<<'\n';
		return 0;
	}
	for(int i=2;i<=n;i++)
		ch[i]=i;
	vector<int> prime;
	for(int i=2;i<=n;i++){
		if(ch[i]==0) continue;
		for(int j=i+i;j<=n;j+=i)
			ch[j]=0;
		prime.push_back(i);
	}
	int cnt=0;
	int start=0;
	int end=0;
	int sum=prime[0];
	while(end<prime.size()&&start<=end){
		if(sum==n){
			cnt++;
		}
		if(sum>n){
			sum-=prime[start++];
		}else{
			sum+=prime[++end];
		}
	}
	cout<<cnt<<'\n';
}