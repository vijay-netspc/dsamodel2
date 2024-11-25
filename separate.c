
#include<stdio.h>
#include<stdlib.h>
int count=0;
int m=11;
struct node{
int data;
struct node *next;
};
int hash(int data){
	return data%m;}

int is_prime(int data){
for(int i=2; i<data/2;i++)
	if(data%i==0)
		return 0;
return 1;

}


int prime_next(int data){
if(is_prime(data+1))
	return data+1;
return prime_next(data+1);

}



struct node* create(int data){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
return newnode;
}
struct node* insert(struct node* head,int data){
struct node *newnode=create(data);
count=1;
if(head==NULL){printf("Entered as first node at index of %d\n",hash(data));
	head=newnode;}
else{printf("Probing Sequence...%d ",head->data);count+=1;
struct node *temp=head;
while(temp->next!=NULL){printf("%d ",temp->data);count+=1;
	temp=temp->next;}
//printf("%d is number of elements there\n",count);
temp->next=newnode;
}
printf("\n%d is number of elements there\n",count);
return head;


}
int search(struct node *head,int data){
if(head==NULL)
	return 0;
if(head->data==data)
	return 1;
return search(head->next,data);
}
struct node* del(struct node* head,int data){
if(head->data==data)
	return head->next;
struct node *temp=head;
while(temp->next->data!=data){
temp=temp->next;


}
temp->next=temp->next->next;
return head;

}

void rehasing(struct node *arr[]){
int num[m],j=0;
for(int i=0;i<m;i++)
	while(arr[i])
		{
		num[j++]=arr[i]->data;
		arr[i]=arr[i]->next;
		}
m=prime_next(m);
for(int i=0;i<m;i++)
	arr[i]=NULL;
for(int i=0;i<j;i++){
int ind=hash(num[i]);
arr[ind]=insert(arr[ind],num[i]);
}

}



int main(){
//----------------
struct node *arr[100];
//for(int i=0;i<100;i++)
//	arr[i]=NULL;
int data,choice;
do{
printf("1.Insert\n2.Search\n3.Delete\n4.Print\nEnter: ");
scanf("%d",&choice);
if(choice<=3){
printf("Enter the element: ");
scanf("%d",&data);
}
switch(choice){

case 1:count=0;
	int ind=hash(data);
	arr[ind]=insert(arr[ind],data);
	if(count>=0.6*m){
	rehasing(arr);}
	break;
case 2:
	ind=hash(data);
	if(search(arr[ind],data))
		printf("Found\n");
	else
		printf("Not Found\n");
	break;
case 3:
	ind=hash(data);
	if(search(arr[ind],data)){
		arr[ind]=del(arr[ind],data);
		printf("%d is deleted\n",data);}
	else
		printf("Not found\n");

	break;
case 4:
	for(int i=0;i<m;i++){
		struct node *temp=arr[i];
		if(!temp)
			printf("%d : NULL",i);
		else
			printf("%d : ",i);
		while(temp){
			printf("%d ",temp->data);temp=temp->next;}
		printf("\n");
		}
}


}while(choice<5);

}
