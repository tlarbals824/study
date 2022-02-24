#include<bits/stdc++.h>

using namespace std;

const int UNKNOWN=1e9;

int main(){
	ios_base::sync_with_stdio(false);
	
	int peopleNum;
	cin>>peopleNum;
	
	vector<vector<int>> friends(peopleNum+1,vector<int>(peopleNum+1,UNKNOWN));
	for(int i=1;i<=peopleNum;i++) friends[i][i]=0;
	while(1){
		int a,b;
		cin>>a>>b;
		if(a==-1&&b==-1)
			break;
		else{
			friends[a][b]=1;
			friends[b][a]=1;
		}
	}
	
	for(int mid=1;mid<=peopleNum;mid++)
		for(int start=1;start<=peopleNum;start++)
			for(int end=1;end<=peopleNum;end++)
				if(friends[start][end]>friends[start][mid]+friends[mid][end])
					friends[start][end]=friends[start][mid]+friends[mid][end];
	
	for(int i=1;i<=peopleNum;i++){
		for(int j=1;j<=peopleNum;j++)
			cout<<friends[i][j]<<' ';
		cout<<endl;
	}
	
	
	int minFriend[peopleNum+1];
	int res=100;
	for(int i=1;i<=peopleNum;i++){
		int Max=-1;
		for(int j=1;j<=peopleNum;j++){
			if(friends[i][j]!=UNKNOWN)
				if(Max<friends[i][j])
					Max=friends[i][j];
		}
		minFriend[i]=Max;
		if(res>Max) res=Max;
	}
	
	
	int cnt=0;
	vector<int> a;
	for(int i=1;i<=peopleNum;i++){
		if(res==minFriend[i]){
			cnt++;
			a.push_back(i);
		}
	}
	cout<<res<<' '<<cnt<<endl;
	for(int i=0;i<cnt;i++)
		cout<<a[i]<<' ';
		
	cout<<endl;
	
}