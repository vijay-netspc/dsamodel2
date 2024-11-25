
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int total=0;
int top=-1;
struct node {
char data[5];
struct node *left,*right;

};

//struct cnode{
//char data;
//struct cnode *left,*right;
//};

struct node* create(char data[5]){
printf("data%s\n",data);
struct node* newnode=(struct node*)malloc(sizeof(struct node));
strcpy(newnode->data,data);
newnode->left=newnode->right=NULL;
printf("newnode: %s\n",newnode->data);
return newnode;
}
void push(struct node *tree[],struct node *newhead){
tree[++top]=newhead;
}
//struct cnode *ccreate(char ch){
//struct cnode *newnode=(struct cnode*)malloc(sizeof(struct cnode));
//newnode->data=ch;
//newnode->left=newnode->right=NULL;
//
//}

void inorder(struct node *head){
if(head){
inorder(head->left);

printf("%s ",head->data);

inorder(head->right);


}

}


int main(){
struct node *tree[30];
char exp[30],temp[5];
int num=0;
int stack[30],topi=-1;
printf("Enter the expression: ");
fgets(exp,30,stdin);
for(int i=0;exp[i]!='\r'&&exp[i]!='\n';i++)
	{if(isdigit(exp[i])){
		num=num*10+exp[i]-'0';
		//sprintf(temp,"%d",num);
		//push(tree,create(temp));
		}
	else if(exp[i]==' '){
		printf("%d\n",num);
		sprintf(temp,"%d",num);
                push(tree,create(temp));
		stack[++topi]=num;
		printf("stack:%d\n",stack[topi]);
		num=0;
	}
	else{
		printf("%c is the character\n",exp[i]);
		struct node *b=tree[top--];
		struct node *a=tree[top--];
		int num1=stack[topi--];
		int num2=stack[topi--];
		switch(exp[i]){case '+' : stack[++topi]=num2+num1;break;case '*': stack[++topi]=num2*num1;break; case '/':stack[++topi]=num2/num1;break;}
		temp[0]=exp[i];
		temp[1]='\0';
		struct node *newnode=create(temp);
		newnode->left=a;
		newnode->right=b;
		push(tree,newnode);
		}
	}
printf("\n");
inorder(tree[0]);
printf("%d\n",stack[top]);

}
