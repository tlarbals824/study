#include<bits/stdc++.h>

using namespace std;
map<int,int> res;
vector<int> input;
int n,m;
long long r=0;
void rightdfs(int cnt,int sum){
	if(cnt==n){
		res[sum]++;
	}else{
		rightdfs(cnt+1,sum+input[cnt]);
		rightdfs(cnt+1,sum);
	}
}
void leftdfs(int cnt,int sum){
	if(cnt==n/2){
		r+=res[m-sum];
	}else{
		leftdfs(cnt+1,sum+input[cnt]);
		leftdfs(cnt+1,sum);
	}
}
int main(){
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		input.push_back(num);
	}
	rightdfs(n/2,0);
	leftdfs(0,0);
	
	if(m==0) cout<<r-1<<'\n';
	else cout<<r<<'\n';
}