#include <stdio.h>
#include <vector>
#include <algorithm>

int main(){
	int num;
	scanf("%d",&num);
	int count1=0;
	int count2=0;
	for(int i=2;i<=num;i++){
		int tmp=i;
		int j=2;
		for(;;){
			if(tmp%j==0){
				if(j==2) count1++;
				if(j==5) count2++;
				tmp=tmp/j;
			}else{
				j++;
			}
			if(tmp==1) break;
		}
	}
	if(count1<count2) printf("%d\n",count1);
	else printf("%d\n",count2);
}