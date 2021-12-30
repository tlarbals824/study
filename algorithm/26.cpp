#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int runner[n];
	int runnerScore[n];
	for(int i=0;i<n;i++){
		scanf("%d",&runner[i]);
		runnerScore[i]=i+1;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(runner[i]>runner[j]) runnerScore[i]--;
		}
	}
	for(int i=0;i<n;i++){
		printf("%d ",runnerScore[i]);
	}
}