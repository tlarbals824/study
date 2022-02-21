#include<bits/stdc++.h>

using namespace std;

struct BBB{
	int base;
	int height;
	int weight;
	BBB(int a, int b,int c){
		base=a;
		height=b;
		weight=c;
	}	
	bool operator<(const BBB& b)const{
		return base>b.base;
	}
};


int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	vector<BBB> tower;
	for(int i=0;i<n;i++){
		int b,h,w;
		cin>>b>>h>>w;
		tower.push_back(BBB(b,h,w));
	}
	
	sort(tower.begin(),tower.end());
	
	int dy[n];
	dy[0]=tower[0].height;
	int res=dy[0];
	
	for(int i=1;i<n;i++){
		int Max=0;
		for(int j=i-1;j>=0;j--){
			if(tower[i].weight<tower[j].weight&&Max<dy[j])
				Max=dy[j];
		}
		dy[i]=Max+tower[i].height;
		if(res<dy[i]) res=dy[i];
	}
	
	cout<<res<<endl;
	
}