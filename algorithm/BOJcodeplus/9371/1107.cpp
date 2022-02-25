#include<bits/stdc++.h>

using namespace std;

int n,m;
int button[10]={0};

bool check(int num){
	if(num==0){
		for(int i=0;i<m;i++){
			if(0==button[i])
				return false;
		}
	}
	int tmp=num;
	while(tmp>0){
		for(int i=0;i<m;i++){
			if(tmp%10==button[i])
				return false;
		}
		tmp=tmp/10;
	}
	return true;
}
int cnt(int num){
	if(num==0) return 1;
	int tmp=num;
	int cnt=0;
	while(tmp>0){
		cnt++;
		tmp=tmp/10;
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	cin>>m;
	
	for(int i=0;i<m;i++)
		cin>>button[i];
	
	int Min=abs(100-n);
	for(int i=0;i<=10000000;i++){
		if(check(i)){
			Min=min(Min,abs(n-i)+cnt(i));
		}
	}
	
	cout<<Min<<endl;
}