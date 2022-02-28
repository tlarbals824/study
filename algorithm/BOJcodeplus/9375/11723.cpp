#include<bits/stdc++.h>

using namespace std;

int res=0;
void add(int x){
	res|=(1<<x);
}
void remove(int x){
	res&=(~(1<<x));
}
void check(int x){
	if(res&(1<<x)){
		cout<<"1\n";
	}else{
		cout<<"0\n";
	}
}
void toggle(int x){
	res=res^(1<<x);
}
void all(){
	res=(1<<21)-1;
}
void empty(){
	res=0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		string a;
		int x;
		cin>>a;
		if(a=="add"){
			cin>>x;
			add(x);
		}else if(a=="remove"){
			cin>>x;
			remove(x);
		}else if(a=="check"){
			cin>>x;
			check(x);
		}else if(a=="toggle"){
			cin>>x;
			toggle(x);
		}else if(a=="all"){
			all();
		}else if(a=="empty"){
			empty();
		}
	}
	return 0;
}