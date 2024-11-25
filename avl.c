#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *left,*right;
};

struct node* create(int data){
struct node *newnode = (struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->left=newnode->right=NULL;
return newnode;

}

int ht(struct node *head){
if(head==NULL)
	return -1;
int left=ht(head->left),right=ht(head->right);
return (left>right?left:right)+1;
}
struct node* single_r(struct node *head){
struct node* newhead=head->left;
head->left=newhead->right;
newhead->right=head;
return newhead;

}

struct node *single_l(struct node* head){
struct node *newhead=head->right;
head->right=newhead->left;
newhead->left=head;
return newhead;

}

struct node* balance(struct node *head){
if(abs(ht(head->left)-ht(head->right))>1){
	if(ht(head->right)>ht(head->left)){
		if(ht(head->right->left)>ht(head->right->right))
				head->right=single_r(head->right);
		head=single_l(head);

		}
	else{
		if(ht(head->left->right)>ht(head->left->left))
				head->left=single_l(head->left);
		head=single_r(head);
		}
	}



return head;

}

struct node* insert(struct node *head,struct node* newnode){
if(head==NULL){
	head=newnode;printf("first node...\n");}
else{
	if(head->data<newnode->data)
		head->right=insert(head->right,newnode);
	else if (head->data>newnode->data)
		head->left=insert(head->left,newnode);
	else{
		printf("%d is already in the tree\n",newnode->data);

		}

}

return balance(head);
}
int find_min(struct node* head){
if(head->left==NULL)
	return head->data;
return find_min(head->left);

}
struct node * search_del(struct node *head,int data,int is_del){
if(head==NULL){
	printf("%d is not found...\n",data);return head;}
else{
	if(head->data>data)
		head->left=search_del(head->left,data,is_del);
	else if(head->data<data)
		head->right=search_del(head->right,data,is_del);
	else{
		printf("%d is found....\n",data);
		if(is_del==2){
			if(!head->left&&!head->right){free(head);printf("%d is deleted\n",data);return NULL;}
			else if(!head->left&&head->right){struct node *temp=head->right;free(head);printf("%d is deleted\n",data);return temp;}
			else if(head->left&&!head->right){struct node *temp=head->left;free(head);printf("%d is deleted\n",data);return temp;}
			else{head->data=find_min(head->right);printf("%d is replaced by %d\n",data,head->data);head->right=search_del(head->right,head->data,is_del);}
			}

		}

}




return balance(head);
}

void level_order(struct node* head){
int rear=0,front=0;
struct node *que[100];
que[rear++]=head;
while(rear!=front){
struct node *temp=que[front++];
printf("%d ",temp->data);
if(temp->left)
	que[rear++]=temp->left;
if(temp->right)
	que[rear++]=temp->right;

}
}


int main(){
int data,ch,is_created=0;
struct node *head;
do{
printf("0.Create\n1.insert\n2.Delete\n3.Search\n4.LevelOrder\n5.Exit\nEnter: ");
scanf("%d",&ch);
switch(ch){
	case 0:
		head=NULL;
		is_created=1;
		break;
	case 1:
		if(!is_created){
			printf("Tree is not yet created...\n");
			break;
			}
		printf("Enter the element: ");
		scanf("%d",&data);
		head=insert(head,create(data));
		break;
	case 2:case 3:
		if(!is_created){
			printf("Tree is not yet created...\n");
			break;
			}
		if(head==NULL){
			printf("Tree is empty\n");
			break;
			}
		printf("Enter the element: ");
		scanf("%d",&data);
		head=search_del(head,data,ch);
		break;
	case 4:if(!is_created){printf("Tree is not yet created...\n");break;}
		if(head==NULL){printf("Tree is empty\n");break;}
		level_order(head);
		printf("\n");

	}


}while(ch<5);


}
