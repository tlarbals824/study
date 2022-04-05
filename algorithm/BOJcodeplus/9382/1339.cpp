#include<bits/stdc++.h>

using namespace std;
int n;
vector<string> str;
int res=0;
void cal(){
	int ch[26]={0};
	for(int i=0;i<n;i++){
		int pow=1;
		for(int j=str[i].length()-1;j>=0;j--){
			ch[str[i][j]-'A']+=pow;
			pow*=10;
		}
	}
	sort(ch,ch+26);
	int num=9;
	for(int i=25;i>0;i--){
		if(ch[i]==0) break;
		res+=num*ch[i];
		num--;
	}
}



int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		str.push_back(s);
	}
	cal();
	cout<<res<<'\n';
}