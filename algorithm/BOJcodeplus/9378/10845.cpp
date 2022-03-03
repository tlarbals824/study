#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	int queue[10010];
	int idx=1;
	for(int i=0;i<n;i++){
		string str;
		int num;
		cin>>str;
		if(str=="push"){
			cin>>num;
			queue[idx++]=num;
		}else if(str=="pop"){
			if(idx==1){
				cout<<"-1\n";
			}else{
				cout<<queue[1]<<'\n';
				for(int i=2;i<idx;i++)
					queue[i-1]=queue[i];
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
				cout<<queue[1]<<'\n';
			}
		}else if(str=="back"){
			if(idx==1){
				cout<<"-1\n";
			}else{
				cout<<queue[idx-1]<<'\n';
			}
		}
	}
}