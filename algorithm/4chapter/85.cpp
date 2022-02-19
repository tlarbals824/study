#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int n;
vector<int> a;
int b[4];
int Min=INT_MAX;
int Max=-INT_MAX;

void dfs(int sum,int cnt){
	if(cnt==n-1){
		if(Min>sum) Min=sum;
		if(Max<sum) Max=sum;
	}else{
		for(int i=0;i<4;i++){
			if(b[i]>0){
				b[i]--;
				switch(i){
					case 0:
						dfs(sum+a[cnt+1],cnt+1);
						break;
					case 1:
						dfs(sum-a[cnt+1],cnt+1);
						break;
					case 2:
						dfs(sum*a[cnt+1],cnt+1);
						break;
					default:
						dfs(sum/a[cnt+1],cnt+1);
						break;
				}
				b[i]++;
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		a.push_back(x);
	}
	for(int i=0;i<4;i++)
		scanf("%d",&b[i]);
	
	dfs(a[0],0);

	printf("%d\n%d\n",Max,Min);

}