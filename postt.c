#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
int top=-1,topi=-1,check=0,b=0;
struct node{
char data[5];
struct node* left,*right;

};
struct node *create(char data[5]){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
strcpy(newnode->data,data);
newnode->left=newnode->right=NULL;
return newnode;
}
void push(struct node *tree[],struct node *newnode){
tree[++top]=newnode;

}

void inorder(struct node* head){
if(head){
inorder(head->left);
if(check%2==0){
	if(b==0){b=1;
		printf("(%s ",head->data);}
	else{b=0;
		printf("%s) ",head->data);}}
else
printf("%s ",head->data);
//check=(check+1)%2;
//if(check==2)
//	printf(")");
check++;
//if(check==0)
//	check=-1;
inorder(head->right);
}

}

int main(){
struct node *tree[30];
char exp[30];
int stack[30];
int num=0;
char temp[5];
fgets(exp,30,stdin);
for(int i=0;exp[i]!='\n'&&exp[i]!='\r';i++){
if(isdigit(exp[i])){
	num=num*10+exp[i]-'0';
	}
else if(exp[i]==' '){
	sprintf(temp,"%d",num);
	push(tree,create(temp));
	stack[++topi]=num;
	num=0;
	}
else{
	temp[0]=exp[i];
	temp[1]='\0';
	struct node *newnode=create(temp);
	struct node *bt=tree[top--];
	struct node *at=tree[top--];
	int b=stack[topi--];
	int a=stack[topi--];
	switch(exp[i]){case '+':stack[++topi]=a+b;break;case '-': stack[++topi]=a-b;break;case '*':stack[++topi]=a*b;break;case '/':stack[++topi]=a/b;break;
		}
	newnode->left=at;
	newnode->right=bt;
	push(tree,newnode);
	}


}
inorder(tree[0]);
printf(")\n%d",stack[0]);

}
