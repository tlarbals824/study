#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int abs(int x){
	int num;
	if(x<0) num=-x;
	else num=x;
	
	return num;
}

int main(){
	int a[9];
	int resAvg[9],resNum[9];
	for(int i=0;i<9;i++){
		int sum=0;
		int avg;
		for(int j=0;j<9;j++){
			scanf("%d",&a[j]);
			sum+=a[j];
		}
		if(sum%9>4) avg=sum/9+1;
		else avg=sum/9;

		int min=abs(a[0]-avg);
		int res=a[0];
		
		for(int j=1;j<9;j++){
			if(min>abs(a[j]-avg)) {
				res=a[j];
				min=abs(a[j]-avg);
			}else if(min==abs(a[j]-avg))
				if(a[j]>res) res=a[j];
		}
		
		resAvg[i]=avg;
		resNum[i]=res;
		
	}	
	for(int i=0;i<9;i++)
		printf("%d %d\n",resAvg[i],resNum[i]);

}
