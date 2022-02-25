#include<iostream>

using namespace std;

int main(){
	int e,s,m;
	cin>>e>>s>>m;
	
	int num;
	for(int i=1;;i++){
		if((i-1)%15+1==e&&(i-1)%28+1==s&&(i-1)%19+1==m){
			num=i;
			break;
		}
	}
	 cout<<num;
}