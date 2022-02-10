#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int size;
	scanf("%d",&size);
	int x[size],y[size];
	for(int i=0;i<size;i++){
		scanf("%d",&x[i]);
	}
	for(int i=0;i<size;i++){
		scanf("%d",&y[i]);
	}
	int sum=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(x[i]>y[j]) sum+=y[j];
			else sum+=x[i];
		}
	}
	printf("%d\n",sum);
}