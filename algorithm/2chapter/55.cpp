#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	
	int num[31];
	vector<char> res;
	stack<int> stk;
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	int count=1;
	for(int i=1;i<=n;i++){
		
		
		stk.push(num[i]);
		res.push_back('P');
		while(1){
			if(stk.empty()) break;
			if(stk.top()==count){
				stk.pop();
				res.push_back('O');
				count++;
			}else break;
		}
	}
	if(!stk.empty()) printf("impossible\n");
	else{
		for(int i=0;res[i]!='\0';i++) printf("%c",res[i]);
		printf("\n");
	}
}