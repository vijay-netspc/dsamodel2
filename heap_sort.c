#include<stdio.h>
int n=0;
void heapify(int arr[],int i){
int smallest=i;
if(2*i+1<n && arr[2*i+1]>arr[smallest])
	smallest=2*i+1;
if(2*i+2<n && arr[2*i+2]>arr[smallest])
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
int arr[30],data;
char ch;
printf("Enter the elements: ");
do{
scanf("%d%c",&data,&ch);
arr[n++]=data;
}while(ch!='\n'&&ch!='\r');

for(int i=(n-1)/2;i>=0;i--)
	heapify(arr,i);



for(int i=0;i<n;i++)
	printf("%d ",arr[i]);
printf("\n");
for(;n>0;)
	printf("%d ",delmin(arr));
}
