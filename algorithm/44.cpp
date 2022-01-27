#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n,c,res,lt=1,rt,mid;
	
	scanf("%d %d",&n,&c);
	vector<int> x(n);
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);
	}
	sort(x.begin(),x.end());
	rt=x[n-1];
	while(lt<=rt){
		mid=(lt+rt)/2;
		int count=1;
		int pos=x[0];
		for(int i=1;i<n;i++){
			if(x[i]-pos>=mid){
				count++;
				pos=x[i];
			}
		}
		if(count>=c){
			res=mid;
			lt=mid+1;
		}else{
			rt=mid-1;
		}
	}
	printf("%d\n",res);
}