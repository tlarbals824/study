#include<iostream>
#include<queue>

using namespace std;

int main(){
	priority_queue<int> q;
	while(1){
		int num;
		scanf("%d",&num);
		if(num==-1) return 0;
		if(num>0)
			q.push(num);
		else if(q.empty()){
			printf("-1\n");
		}else{
			int tmp=q.top();
			q.pop();
			printf("%d\n",tmp);
		}
	}
}