// Niyam Muliya  //  @niyam239  // Charusat  //
#include<stdio.h>
#include<stdlib.h>
struct node* create(int);
void insertFirst(int);
void insertLast(int);
void insertAfterVal(int,int);
void deletefirst();
void deletelast();
void deleteVal();
void display();

struct node{
	int data;
	struct node *next;
}*head,*last;

int main(){
	char response='y';
	printf("1. Insert a node at front\n");
	printf("2. Insert a node at end\n");
	printf("3. Insert a node after given node information\n");
	printf("4. Delete a node at front\n");
	printf("5. Delete a node at end\n");
	printf("6. Delete a node by given node information\n");
	printf("7. Display a LinkList\n");
	printf("8. Exit");
	
	while(1){
		int choice;
		printf("\n\nChoice:> ");
		scanf("%d",&choice);
		int value,after;
		switch(choice){
			case 1:
				printf("\t:> Enter a value: ");
				scanf("%d",&value);
				insertFirst(value);
				break;
			case 2:
				printf("\t:> Enter a value: ");
				scanf("%d",&value);
				insertLast(value);
				break;
			case 3:
				printf("\t:> Enter a value: ");
				scanf("%d",&value);
				printf("\t:> Enter value of node after you want to insert node: ");
				scanf("%d",&after);
				insertAfterVal(value,after);
				break;
			case 4:
				deletefirst();
				break;
			case 5:
				deletelast();
				break;
			case 6:
				deleteVal();
				break;
			case 7:
				display();
				break;
			case 8:
				return 0;
			default:
				printf("\t:> Invalid choice...!!");
				break;
		}
	}
	return 0;
}
struct node* create(int v){
	struct node* n1;
	n1=(struct node*)malloc(sizeof(struct node));
	n1->data=v;
	n1->next=NULL;
	return n1;
}
void insertFirst(int v){
	struct node *p;
	p=create(v);
	if(head==NULL){
		head=p;
		last=p;
	}
	else{
		p->next=head;
		head=p;
	}
	printf("\t:> %d Value inserted at First. ",v);
}
void insertLast(int v){
	struct node *p;
	p=create(v);
	if(head==NULL){
		head=p;
		last=p;
	}
	else{
		last->next=p;
		last=p;
	}	
	printf("\t:> %d Value inserted at last. ",v);
}
void insertAfterVal(int v,int after){
	struct node *t=head,*p;
	p=create(v);
	while(t!=NULL && t->data!=after){
		t=t->next;
	}
	if(t==NULL){
		printf("\t:> Entered value does not exist in LinkedList !!!\n");
		return ;
	}
	else if(t==last){
		t->next=p;
		last=p;
	}
	else{
		p->next=t->next;
		t->next=p;
	}
	printf("\t:> %d Value inserted after given node. ",v);
}
void deletefirst(){
	struct node *p;
	int v;
	p=head;
	if(head==NULL){
		printf("\t:> Linked-list is empty !!! ",v);
		return ;
	}
	else if(head->next==NULL){
		v=head->data;
		head=NULL;
	}
	else{
		head=head->next;
		v=p->data;
		p=NULL;
	}
	printf("\t:> %d Value Deleted. ",v);
}
void deletelast(){
	struct node *p,*temp;
	p=head;
	int v;
	if(head==NULL){
		printf("\t:> Linked-list is empty !!! ",v);
		return ;
	}
	else if(head->next==NULL){
		v=head->data;
		head=NULL;
	}
	else{
		while(p->next!=NULL){
			temp=p;
			p=p->next;
		}
		temp->next=NULL;
		last=temp;
		v=p->data;
		p=NULL;
	}	
	printf("\t:> %d Value Deleted. ",v);
}
void deleteVal(){
	struct node *t=head,*p;
	int v;
	if(head==NULL){
		printf("\t:> Linked-list is empty !!! ",v);
		return ;
	}
	
	printf("\t:> Enter value of node that you want to delete: ");
	scanf("%d",&v);
	
	while(t!=NULL && t->data!=v){
		p=t;
		t=t->next;
	}
	
	if(t==NULL){
		printf("\t:> Entered value does not exist in LinkedList !!!\n");
		return ;
	}
	else if(t==head){
		head=head->next;
		t=NULL;
	}
	else{
		p->next=t->next;
		if(t->next==NULL){
			last=t;
		}
		t=NULL;
	}
	printf("\t:> %d Value Deleted. ",v);
}
void display(){
	struct node *t=head;
	if(t==NULL){
		printf("\t:> LinkList is empty...!!!"); 
		return;
	}
	printf("\n\tvalue | Address  | next_Address\n");
	printf("\t------------------------------\n");
	while(t!=NULL){
		printf("\t%4d  | %u | %u\n",t->data,t,t->next);
		t=t->next;
	}
	printf("\n\tAddress of Head node: %u",head);
	printf("\n\tAddress of Last node: %u",last);
}





