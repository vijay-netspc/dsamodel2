#include<stdio.h>
#include<stdlib.h>
int  M=11;
struct node{
int data;
struct node * next;

};


int count=0;
int hash(int data){
int x =(data+7)*(data+7);
x/=16;
x+=data;
x%=11;
return x;

}
int h2(int data){
int rev=0;
while(data){
rev=rev*10+data%10;
data/=10;
}
return rev;


}

void insert(int arr[],int data,int home_slot,int i){
int temp_ind=(home_slot+i*h2(data))%M;
if(arr[temp_ind]<0){
	printf("%d:%d\n",temp_ind,data);
	arr[temp_ind]=data;
	count+=1;
	return;
	}
if(arr[temp_ind]>=0)
	printf("%d:%d\n",temp_ind,arr[temp_ind]);
insert(arr,data,home_slot,i+1);

}



int search(int arr[],int data){
int home_slot=hash(data),temp_ind=home_slot;
int i=0;
while(arr[temp_ind]!=-1){
	if(arr[temp_ind]>=0){
		printf("%d:%d\n",temp_ind,arr[temp_ind]);}
	if(temp_ind!=-1)
		i+=1;
	if(arr[temp_ind]==data&&arr[temp_ind]>=0)
		return temp_ind;
	temp_ind=(home_slot+i*h2(data))%M;
}
printf("%d is not found\n",data);
return -1;
}


int main(){
int data,choice,arr[M];
struct node *array[M];
array[12]=(struct node*)malloc(sizeof(struct node));
array[12]->data=5;
//struct node *arrr=(struct node*)malloc(11*sizeof(struct node));

//printf("%d",sizeof(*arrr));
//M=100;
//printf("%d",sizeof(*arrr)/sizeof(*arrr[0]));
for(int i=0;i<M;i++)
	arr[i]=-1;
//printf("%d",h2(200));
do{
printf("1.Insert\n2.Search\n3.Delete\n4.Print\nEnter: ");
scanf("%d",&choice);
if(choice<=3 )
{
printf("Enter the element: ");
scanf("%d",&data);
}
switch(choice){
	case 1:if(count==M){printf("FULL\n");break;}
		int home_slot=hash(data);
		insert(arr,data,home_slot,0);
		break;
	case 2:
		search(arr,data);
		break;
	case 3:
		int ind=search(arr,data);
		if(ind>=0)
			{printf("%d is deleted\n",data);
			arr[ind]=-2;
			count-=1;
			}
	case 4:if(count==0){printf("Empty\n");break;}
		printf("heap contains: %d elements \n",count);
		for(int i=0;i<M;i++)
		    if(arr[i]>=0)
			printf("%d:%d\n",i,arr[i]);

}
}while(choice<5);


}
