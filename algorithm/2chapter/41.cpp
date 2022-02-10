#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int num;
	scanf("%d",&num);
	int count=2;
	int size=0;
	for(;;){
		int sum=0;
		for(int i=0;i<count;i++){
			sum+=(i+1);
		}
		if(sum>num) break;
		if((num-sum)%count==0){
			size++;
			for(int i=0;i<count;i++){
				printf("%d ",i+1+(num-sum)/count);
				if(i==count-1) printf("= %d\n",num);
				else printf("+ ");
			}
		}
		count++;
	}
	printf("%d\n",size);
}