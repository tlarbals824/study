#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	
	vector<int> nine(9);
	for(int i=0;i<9;i++)
		cin>>nine[i];
	
	for(int i=0;i<9;i++){
		for(int j=i+1;j<9;j++){
			int sum=0;
			for(int k=0;k<9;k++){
				if(k==i||k==j) continue;
				else {
					sum+=nine[k];
				}
			}
			if(sum==100){
				vector<int> p;
				for(int k=0;k<9;k++){
				if(k==i||k==j) continue;
				else 
					p.push_back(nine[k]);
				}
				sort(p.begin(),p.end());
				for(int i=0;i<7;i++)
					cout<<p[i]<<' ';
				return 0;
			}
		}
	}
}