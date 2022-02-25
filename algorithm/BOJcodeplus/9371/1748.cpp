#include<bits/stdc++.h>

using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	
	int t=1;
	int tCnt=1;
	int n;
	cin>>n;
	int res=0;
	while(1){
		if(n>=t&&n<=t*10-1){
			res=res+(n-t+1)*tCnt;
			t=t*10;
			tCnt++;
			break;
		}else{
			res=res+(t*10-t)*tCnt;
			t=t*10;
			tCnt++;
		}
	}
	cout<<res<<endl;
}