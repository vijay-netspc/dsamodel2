#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#include<time.h>
int n,count=0;
void printarr(int arr[]){
for(int i=0;i<n;i++)
	printf("%d ",arr[i]);

}
void insertion_sort(int arr[]){
for(int i=1;i<n;i++)
	{
	for(int j=0;j<=i;j++)
		{
		if(arr[j]>arr[i])
			{count++;
			int temp =arr[j];
			    arr[j]=arr[i];
			    arr[i]=temp;
			}

		}
	printf("\nIteration %d : ",i);
	printarr(arr);
	printf("\n");
	}


}
void shellsort(int arr[]){
int gap=n/2;
while(gap!=0){
for(int j=gap;j<n;j++){
	if(arr[j-gap]>arr[j]){
		int temp=arr[j-gap];
		    arr[j-gap]=arr[j];
		    arr[j]=temp;
		count++;
		for(int k=j-gap;k-gap>=0;k-=gap){
		if(arr[k-gap]>arr[k]){
			int temp=arr[k-gap];
			    arr[k-gap]=arr[k];
			    arr[k]=temp;
				count++;
			}
		}
		}


	}



printf("\nAt gap %d :",gap);
printarr(arr);
printf("\n");

gap/=2;
}

}
void merge(int arr[],int left,int mid,int right){
int n1=mid-left+1;
int n2=right-mid;
int l[n1],r[n2];
for(int i=left;i<=mid;i++)
	l[i-left]=arr[i];
for(int i=mid+1;i<=right;i++)
	r[i-mid-1]=arr[i];
int k=left,i=0,j=0;
for(;i<n1&&j<n2;k++)
{
if(l[i]<r[j])
	arr[k]=l[i++];
else
	arr[k]=r[j++];

}

while(i<n1)
	arr[k++]=l[i++];
while(j<n2)
	arr[k++]=r[j++];

}
void mergesort(int arr[],int left,int right){
if(left<right){
int mid =left+(right-left)/2;
mergesort(arr,left,mid);
mergesort(arr,mid+1,right);
merge(arr,left,mid,right);
printf("\nAt mid %d: ");
printarr(arr);
printf("\n");
}

}


int main(){
FILE *fp= fopen("numbers.txt","w");
do{
printf("Enter the number of elements: (range should be 5,40)");
scanf("%d",&n);
}while(n<5|| n>40);
for(int i=0;i<n;i++)
	fprintf(fp,"%d ",rand()%1000);
fclose(fp);
int arr[n];
FILE *fp1=fopen("numbers.txt","r");
for(int i=0;i<n;i++)
	fscanf(fp1,"%d ",&arr[i]);
fclose(fp1);


if(n<20)
	insertion_sort(arr);
if(n<30)
	shellsort(arr);
else
	mergesort(arr,0,n-1);
for(int i=0;i<n;i++)
	printf("%d ",arr[i]);
printf("\ncount:%d\n",count);

}
