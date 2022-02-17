#include<iostream>

using namespace std;

int frd[1001];

int getpar(int x){
	if(frd[x]==x) return x;
	return frd[x]=getpar(frd[x]);
}


void friendUnion(int x,int y){
	if(getpar(x)!=getpar(y)) frd[getpar(x)]=getpar(y);
}


int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		frd[i]=i;
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		friendUnion(x,y);
	}
	int x,y;
	scanf("%d %d",&x,&y);
	if(frd[x]==frd[y]) printf("YES\n");
	else printf("NO\n");
	
}