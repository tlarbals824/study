#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int num;
	scanf("%d",&num);
	printf("%d! = ",num);
	vector<int> ch(num+1); //기본적으로 vector는 0으로 초기화되어있음
	for(int i=2;i<=num;i++){
		int tmp=i;
		int j=2;
		for(;;){
			if(tmp%j==0){
				ch[j]++;
				tmp=tmp/j;
			}
			else{
				j++;
			}
			if(tmp==1) break;
		}
	}
	for(int i=2;i<=num;i++){
		if(ch[i]!=0) printf("%d ",ch[i]);
	}
	printf("\n");
}