#include<iostream>

using namespace std;

int num[101]={0};
int tmp[101];

void divide(int lt,int rt){
	int mid;
	int p1,p2,p3;
	if(lt<rt){
		mid=(lt+rt)/2;
		divide(lt,mid);
		divide(mid+1,rt);
		p1=lt;
		p2=mid+1;
		p3=lt;
		while(p1<=mid&&p2<=rt){
			if(num[p1]<num[p2]) tmp[p3++]=num[p1++];
			else tmp[p3++]=num[p2++];
		}
		while(p1<=mid) tmp[p3++]=num[p1++];
		while(p2<=rt) tmp[p3++]=num[p2++];
		for(int i=lt;i<=rt;i++)
			num[i]=tmp[i];
	}
}


int main(){
	int size;
	scanf("%d",&size);
	for(int i=1;i<=size;i++)
		scanf("%d",&num[i]);
	
	divide(1,size);
	
	for(int i=1;i<=size;i++)
		printf("%d ",num[i]);


}