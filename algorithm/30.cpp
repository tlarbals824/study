#include<stdio.h>
#include<algorithm>
#include<vector>

int main(){
	int num;
	scanf("%d",&num);
	int lt=1,rt,cur,k=1,res=0;
	while(lt!=0){
		lt=num/(k*10);
		rt=num%k;
		cur=(num/k)%10;
		if(cur>3) res+=(lt+1)*k;
		else if(cur==3) res+=((lt*k)+(rt+1));
		else res+=(lt*k);
		k=k*10;
	}
	printf("%d\n",res);
	return 0;
}