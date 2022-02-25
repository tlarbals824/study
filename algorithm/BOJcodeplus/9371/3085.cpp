#include<iostream>
using namespace std;

int s;
char Map[51][51]={0};
int res=0;
void maxColor();

int main(){
	ios_base::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s;i++){
		for(int j=0;j<s;j++){
			cin>>Map[i][j];
		}
	}
	
	for(int i=0;i<s;i++){
		for(int j=0;j<s-1;j++){
			char tmp=Map[i][j];
			Map[i][j]=Map[i][j+1];
			Map[i][j+1]=tmp;
			maxColor();
			tmp=Map[i][j];
			Map[i][j]=Map[i][j+1];
			Map[i][j+1]=tmp;
		}
	}
	for(int i=0;i<s;i++){
		for(int j=0;j<s-1;j++){
			char tmp=Map[j][i];
			Map[j][i]=Map[j+1][i];
			Map[j+1][i]=tmp;
			maxColor();
			tmp=Map[j][i];
			Map[j][i]=Map[j+1][i];
			Map[j+1][i]=tmp;
		}
	}
	cout<<res<<endl;
}
void maxColor(){


	int cnt=0;
	for(int i=0;i<s;i++){
		cnt=1;						//가로
		char a=Map[i][0];
		for(int j=1;j<s;j++){
			if(a==Map[i][j])
				cnt++;
			else {
				cnt=1;
			}
			a=Map[i][j];
			if(res<cnt) res=cnt;
		}
	}
	for(int i=0;i<s;i++){
		cnt=1;						//세로
		char a=Map[0][i];
		for(int j=1;j<s;j++){
			if(a==Map[j][i])
				cnt++;
			else {
				cnt=1;
			}
			a=Map[j][i];
			if(res<cnt) res=cnt;
		}
	}
}
