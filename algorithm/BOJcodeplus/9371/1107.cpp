#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n;
	int m;
	cin>>n>>m;
	int unable[m];
	for(int i=0;i<m;i++)
		cin>>unable[i];
	
	int Min=100;
	
	for(int i=0;i<n;i++){
		int tmp[2]={n+i,n-i};
		for(int i=0;i<2;i++){
			
			int tmp1=tmp[i];
			if(tmp1<0) continue;
			
			bool flag=false;
			while(tmp1>0){
				int a=tmp1%10;
				for(int i=0;i<m;i++)
					if(a==unable[i]) flag=true;
				if(flag) break;
				else tmp1=tmp1/10;
			}
			if(!flag){
				if(abs(tmp[i]-n)<abs(Min-n))
					Min=tmp[i];
			}
		}
	}
	int tmp1=Min;
	cout<<Min<<endl;
	int cnt=0;
	while(tmp1>0){
		cnt++;
		tmp1=tmp1/10;
	}
	int res;
	if(Min==100)
		res=abs(Min-n);
	else res=cnt+abs(Min-n);
	cout<<res<<endl;
}