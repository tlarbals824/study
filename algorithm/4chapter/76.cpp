#include<iostream>

using namespace std;

int memo[21][21]={0};

int binomialCoefficient(int n,int r){
	if(n==r||r==0)return 1;
	else if(memo[n][r]!=0) return memo[n][r];
	else{
		return memo[n][r]=binomialCoefficient(n-1,r)+binomialCoefficient(n-1,r-1);
	}
}



int main(){
	int n,r;
	scanf("%d %d",&n,&r);
	int res=binomialCoefficient(n,r);
	printf("%d\n",res);
}