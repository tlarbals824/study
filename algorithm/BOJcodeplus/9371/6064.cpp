#include<iostream>
#include<vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	vector<int> stk;
	for(int j=0;j<t;j++){
		int n,m,x,y;
		cin>>n>>m>>x>>y;
		int x1=0;
		int y1=0;
		while(1){
			if(x1>m||y1>n){
				stk.push_back(-1);
				break;
			}
			if(x1*n+x>y1*m+y){
				y1++;
			}else if(x1*n+x<y1*m+y){
				x1++;
			}else{
				stk.push_back(x1*n+x);
				break;
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<stk[i]<<endl;
	}
} v                           