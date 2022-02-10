#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int size;
	scanf("%d",&size);
	vector<int> is(size+1),os(size+1);
	for(int i=1;i<=size;i++){
		scanf("%d",&is[i]);
	}
	for(int i=size;i>0;i--){
		int pos=i;
		for(int j=0;j<is[i];j++){
			os[pos]=os[pos+1];
			pos++;
		}
		os[pos]=i;
	}
	for(int i=1;i<=size;i++){
		printf("%d ",os[i]);
	}
	printf("\n");
}
