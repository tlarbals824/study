#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int money[n+1]={0};
	int price[n+1];
	for(int i=1;i<=n;i++)
		cin>>price[i];
	
	for(int i=1;i<=n;i++){// i번째 물건
		for(int j=i;j<=n;j++){// 카드 최대 개수
			money[j]=max(money[j-i]+price[i],money[j]);
		}
	}
	cout<<money[n]<<'\n';
}