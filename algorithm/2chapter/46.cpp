#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n;
	int sum=0;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	int k;
	scanf("%d",&k);
	
	if(sum<k) {
		printf("-1\n");
		return 0;
	}
	
	int time=0;
	int cur=0;
	while(1){
		if(a[cur]>0){
			a[cur]--;
			time++;
		}
		
		if(time==k){
			int tmp=cur;
			cur=(cur+1)%n;
			while(1) {
				if(a[cur]!=0) break;
				else if(tmp==cur){
					printf("-1\n");
					return 0;
				}
				cur=(cur+1)%n;
			}
			printf("%d\n",cur+1);
			return 0;
		}
		
		cur=(cur+1)%n;
	}
}