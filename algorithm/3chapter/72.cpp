#include<iostream>
#include<queue>

using namespace std;

int main(){
	queue<int> q;
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		q.push(i);
	
	int cnt=0;
	
	while(q.size()>1){
		
		int tmp=q.front();
		q.pop();
		cnt++;
		if(cnt==k){
			cnt=0;
		}else{
			q.push(tmp);
		}
	}
	int tmp=q.front();
	printf("%d\n",tmp);
}