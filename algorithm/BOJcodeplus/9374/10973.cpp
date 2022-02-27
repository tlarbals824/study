#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> num;


int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	num.resize(n);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	if(prev_permutation(num.begin(),num.end())){
		for(int i=0;i<n;i++)
			cout<<num[i]<<' ';
	}else{
		cout<<"-1";
	}
	
}
