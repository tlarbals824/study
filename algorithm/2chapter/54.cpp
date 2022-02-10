#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

int main(){
	stack<char> res;
	string a;
	cin>>a;
	for(int i=0;a[i]!='\0';i++){
		if(a[i]=='(') res.push(a[i]);
		else{
			if(res.empty()||res.top()!='('){
				printf("NO\n");
				return 0;
			}
			res.pop();
		}
	}
	if(res.empty()) printf("YES\n");
	else printf("NO\n");
}