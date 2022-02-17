#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct Money{
	int money,time;
	Money(int m,int t){
		money=m;
		time=t;
	}
	bool operator<(const Money& b)const{
		return time>b.time;
	}
};



int main(){
	int cnt;
	scanf("%d",&cnt);
	vector<Money> M;
	priority_queue<int> q;
	int maxTime=-1;
	int res=0;
	
	for(int i=0;i<cnt;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		M.push_back(Money(x,y));
		if(maxTime<y) maxTime=y;
	}
	sort(M.begin(),M.end());
	
	for(int i=0;i<maxTime;i++){
		for(int j=0;j<cnt;j++){
			Money tmp=M[j];
			if(tmp.time==maxTime-i){
				q.push(tmp.money);
			}
		}
		if(!q.empty()){
			res=res+q.top();
			q.pop();
		}
	}
	printf("%d\n",res);
	
	
	
}