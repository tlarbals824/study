#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> num;

bool next_permutation(vector<int> &a){
	if(a.begin()==a.end()) return false;
	int i=n-1;
	while(a[i]<a[i-1]&&i>0){
		i=i-1;
	}
	
	if(i==0) return false;
	else{
		int j=n-1;
		while(a[j]<=a[i-1])
			j--;
		swap(a[j],a[i-1]);
		j=n-1;
		while(i<j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	num.resize(n);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	if(next_permutation(num)){
		for(int i=0;i<n;i++)
			cout<<num[i]<<' ';
	}else{
		cout<<"-1";
	}
	
}
