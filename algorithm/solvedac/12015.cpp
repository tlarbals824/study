#include<bits/stdc++.h>
//https://yabmoons.tistory.com/560
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	vector<int> num;
	vector<int> lis;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		num.push_back(tmp);
	}

	for(int i=0;i<n;i++){
		if(lis.size()==0||lis[lis.size()-1]<num[i]) lis.push_back(num[i]);
		else{
			int lt=0;
			int rt=lis.size()-1;
			int mid;
			while(lt<rt){
				mid=(lt+rt)/2;
				if(lis[mid]<num[i]){
					lt=mid+1;
				}else{
					rt=mid;
				}
			}
			lis[lt]=num[i];
		}
	}
	cout<<lis.size()<<'\n';
	for(int i=0;i<lis.size();i++){
		cout<<lis[i]<<' ';
	}
}