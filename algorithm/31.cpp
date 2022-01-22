#include<stdio.h>
#include<algorithm>
#include<vector>

int main(){
	char ch[8];
	int cCount=0,hCount=0;
	int sum;
	int count=1;
	scanf("%s",ch);
	while(1){
		if(ch[count]=='H') {
			count++;
			break;
		}
		cCount=cCount*10+(ch[count]-48);
		count++;
	}
	if(cCount==0) cCount=1;
	while(1){
		if(ch[count]=='\0') break;
		hCount=hCount*10+(ch[count]-48);
		count++;
	}
	if(hCount==0) hCount=1;
	sum=cCount*12+hCount;
	printf("%d\n",sum);
	
}