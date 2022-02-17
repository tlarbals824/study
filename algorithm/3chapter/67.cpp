#include<iostream>
#include<climits>
using namespace std;

int vertex[21][21]={0};
int res=INT_MAX;

void dfs(int srt,int end,int sum){
	if(srt==end){ 
		if(res>sum) {
			res=sum;
			return;
		}
	}else{
		int tmp;
		for(int i=1;i<=end;i++){
			if(vertex[srt][i]!=0){
				tmp=vertex[srt][i];
				vertex[srt][i]=0;
				dfs(i,end,sum+tmp);
				vertex[srt][i]=tmp;
			}
		}
	}
}


int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int from,to,size;
		scanf("%d %d %d",&from,&to,&size);
		vertex[from][to]=size;
	}
	
	dfs(1,n,0);

	printf("%d\n",res);
}