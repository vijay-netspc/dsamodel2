#include<stdio.h>
#include<stdlib.h>
int arr[30],n=0;
void rev_inorder(int arr[],int i){
if(i<n){
rev_inorder(arr,2*i+2);
if(arr[i]!=-1)
	printf("%d ",arr[i]);
rev_inorder(arr,2*i+1);

}

}
int ht(int arr[],int i){
if(i>=n||arr[i]==-1)
	return -1;
int left=ht(arr,2*i+1);
int right=ht(arr,2*i+2);
return (left>right?left:right)+1;

}


int is_avl(int arr[],int i){
//printf("%d\n",arr[i]);
if(i>=n||arr[i]==-1)
	return 1;
else if(2*i+1<n && arr[2*i+1]>arr[i] && arr[2*i+1]!=-1 || 2*i+2<n && arr[2*i+2]<arr[i] && arr[2*i+2]!=-1 || abs(ht(arr,2*i+1)-ht(arr,2*i+2))>1)
	return 0;
return is_avl(arr,2*i+1)&&is_avl(arr,2*i+2);


}
int null_path(int arr[],int i){
if(i>=n || arr[i]==-1)
	return 0;
int left=null_path(arr,2*i+1);
int right=null_path(arr,2*i+2);
return (left>right?right:left)+1;
}


int is_leftiest_heap(int arr[],int i){
if(i>=n || arr[i]==-1)
	return 1;
if(2*i+1<n && arr[2*i+1]<arr[i] && arr[2*i+1]!=-1 || 2*i+2<n && arr[2*i+2]<arr[i] && arr[2*i+2]!=-1|| null_path(arr,2*i+1)<null_path(arr,2*i+2) )
	return 0;
return is_leftiest_heap(arr,2*i+1)&&is_leftiest_heap(arr,2*i+2);
}

int main(){

int data;
char ch;

printf("Enter the binary tree: ");
int i=0;
do{
if(i==30)
	{
	printf("Tree is full\n");
	break;

	}
	scanf("%d%c",&data,&ch);
	arr[i++]=data;
}while(ch!='\n'&&ch!='\r');
n=i;
int is=1;
for(int i=0;i<n;i++){
	if(!is)
		break;
	for(int j=i+1;j<n;j++)
		if(arr[i]==arr[j] && arr[i]!=-1)
			{is=0;
			break;		}
	}
if(is&&is_avl(arr,0)==1){
	printf("yes\n");
	rev_inorder(arr,0);
	printf("\n");
}
else{
	printf("no\n");
}



if(is_leftiest_heap(arr,0))
	printf("yes\n");
else
	printf("no\n");

}
