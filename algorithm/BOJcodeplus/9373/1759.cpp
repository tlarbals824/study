#include<bits/stdc++.h>

using namespace std;

int l,c;
char moEx[5]={'a','e','i','o','u'};
int ch[20]={0};
vector<char> letter;
vector<char> res;
void dfs(int cnt,int a){
	if(cnt==l){
		int moCnt=0;
		int zaCnt=0;
		for(int i=0;i<l;i++){
			bool moFlag=true;
			for(int j=0;j<5;j++){
				if(moEx[j]==res[i]){
					moCnt++;
					moFlag=false;
					break;
				}
			}
			if(moFlag) zaCnt++;
		}
		if(moCnt>0&&zaCnt>1){
			for(int i=0;i<l;i++)
				cout<<res[i];
			cout<<'\n';
		}
	}else{
		for(int i=a;i<c;i++){
			if(!ch[i]){
				ch[i]=1;
				res[cnt]=letter[i];
				dfs(cnt+1,i+1);
				ch[i]=0;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>l>>c;
	res.resize(l+1);
	letter.resize(c);
	for(int i=0;i<c;i++){
		cin>>letter[i];
	}
	sort(letter.begin(),letter.end());
	dfs(0,0);

}