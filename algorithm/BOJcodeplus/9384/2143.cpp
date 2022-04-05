#include<bits/stdc++.h>

using namespace std;
int t,n,m;
vector<int> input1;
vector<int> input2;

long long cnt=0;


int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>t;
	cin>>n;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		input1.push_back(num);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int num;
		cin>>num;
		input2.push_back(num);
	}
	for(int i=0;i<n;i++){
		int sum=input1[i];
		for(int j=i+1;j<n;j++){
			sum+=input1[j];
			input1.push_back(sum);
		}
	}
	for(int i=0;i<m;i++){
		int sum=input2[i];
		for(int j=i+1;j<m;j++){
			sum+=input2[j];
			input2.push_back(sum);
		}
	}
	sort(input1.begin(),input1.end());
	sort(input2.begin(),input2.end());
	for(int i=0;i<input1.size();i++){
		int tmp=t-input1[i];
		cnt+=upper_bound(input2.begin(),input2.end(),tmp)-lower_bound(input2.begin(),input2.end(),tmp);
	}
	
	
	cout<<cnt<<'\n';
}