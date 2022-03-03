#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
	int deque[10010];
	int idx=1;
	cin>>n;
	for(int i=0;i<n;i++){
		string str;
		int num;
		cin>>str;
		if(str=="push_front"){
			cin>>num;
			for(int i=idx-1;i>0;i--){
				deque[i+1]=deque[i];
			}
			deque[1]=num;
			idx++;
		}else if(str=="push_back"){
			cin>>num;
			deque[idx++]=num;
		}else if(str=="pop_front"){
			if(idx==1){
				cout<<"-1\n";
			}else{
				cout<<deque[1]<<'\n';
				for(int i=1;i<idx;i++){
					deque[i]=deque[i+1];
				}
				idx--;
			}
		}else if(str=="pop_back"){
			if(idx==1){
				cout<<"-1\n";
			}else{
				cout<<deque[idx-1]<<'\n';
				idx--;
			}
		}else if(str=="size"){
			cout<<idx-1<<'\n';
		}else if(str=="empty"){
			if(idx==1){
				cout<<"1\n";
			}else{
				cout<<"0\n";
			}
		}else if(str=="front"){
			if(idx==1){
				cout<<"-1\n";
			}else{
				cout<<deque[1]<<'\n';
			}
		}else if(str=="back"){
			if(idx==1){
				cout<<"-1\n";
			}else{
				cout<<deque[idx-1]<<'\n';
			}
		}
	}
}