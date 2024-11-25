#include<stdio.h>
int n=0;
void percolate_up(int arr[],int n){
if(n==0){//printf("return");
	return;}
int parent_ind =(n-1)/2;
if(arr[parent_ind]>arr[n]){
	//printf("hii");
	int temp = arr[parent_ind];
            arr[parent_ind]=arr[n];
	    arr[n]=temp;
	percolate_up(arr,(n-1)/2);

}}
void heapify(int arr[],int i){
int smallest =i;
if(2*i+1<n && arr[2*i+1]<arr[smallest])
	smallest=2*i+1;
if(2*i+2<n && arr[2*i+2]<arr[smallest])
	smallest=2*i+2;
if(smallest!=i)
{
int temp=arr[smallest];
arr[smallest]=arr[i];
arr[i]=temp;
heapify(arr,smallest);

}


}
int delmin(int arr[]){
int temp=arr[0];
arr[0]=arr[--n];
heapify(arr,0);
return temp;


}

int main(){
int arr[30];
int data,ch;
//case order should not be changed....

do{
printf("1.Insert\n2.Delete min\n3.Remove\n4.Print\nEnter: ");
scanf("%d",&ch);
switch(ch){
case 1:if(n==30){printf("FULL\n");break;}
	printf("Enter the element");
	scanf("%d",&data);
	arr[n]=data;
	percolate_up(arr,n++);
	break;
case 3:
	printf("Enter the location of element: (not index) : ");
	scanf("%d",&data);
	if(data>n||n==0){printf("Location beyond the array\n");break;}
	if(data!=1){
	int temp=arr[data-1];
	printf("%d is reduced to %d and ",temp,arr[0]-1);
	arr[data-1]=arr[0]-1;
	percolate_up(arr,data-1);}
case 2:
	if(n==0)
	{printf("Empty\n");break;}
	printf("Deleted : %d\n",delmin(arr));
case 4:
	if(n==0){printf("Empty\n");break;}
	printf("In heap: ");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

}while(ch<5);

}
