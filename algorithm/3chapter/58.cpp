#include<iostream>

using namespace std;

void preorder(int a){
	if(a>7) return;
	printf("%d ",a);
	preorder(a*2);
	preorder(a*2+1);
}
void inorder(int a){
	if(a>7) return;
	inorder(a*2);
	printf("%d ",a);
	inorder(a*2+1);
}
void postorder(int a){
	if(a>7) return;
	postorder(a*2);
	postorder(a*2+1);
	printf("%d ",a);
}
int main(){
	preorder(1);
	printf("\n");
	inorder(1);
	printf("\n");
	postorder(1);
	printf("\n");
}