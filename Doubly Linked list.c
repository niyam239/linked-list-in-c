// Niyam Muliya  //  @niyam239  // Charusat  //
#include<stdio.h>
#include<stdlib.h>

struct node* create(int);
void insertFirst(int);
void insertLast(int);
void insertLeftSide(int,int);
void insertRightSide(int,int);
void deletefirst();
void deletelast();
void deleteLeftSide();
void deleteRightSide();
void display();

struct node{
	int data;
	struct node *prev,*next;
}*left=NULL,*right=NULL;

int main(){
	char response='y';
	printf("1. Insert a node at front\n");
	printf("2. Insert a node at end\n");
	printf("3. Insert a node left to given node information\n");
	printf("4. Insert a node right to given node information\n");
	printf("5. Delete a node at front\n");
	printf("6. Delete a node at end\n");
	printf("7. Delete a node left to given node information\n");
	printf("8. Delete a node right to given node information\n");
	printf("9. Display a LinkList\n");
	printf("10. Exit");
	
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
				printf("\t:> Enter value of a node whose left side you want to insert node: ");
				scanf("%d",&after);
				insertLeftSide(value,after);
				break;
			case 4:
				printf("\t:> Enter a value: ");
				scanf("%d",&value);
				printf("\t:> Enter value of a node whose right side you want to insert node: ");
				scanf("%d",&after);
				insertRightSide(value,after);
				break;
			case 5:
				deletefirst();
				break;
			case 6:
				deletelast();
				break;
			case 7:
				deleteLeftSide();
				break;
			case 8:
				deleteRightSide();
				break;
			case 9:
				display();
				break;
			case 10:
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
	n1->prev=NULL;
	n1->next=NULL;
	return n1;
}

void insertFirst(int v){
	struct node *p;
	p=create(v);
	if(left==NULL && right==NULL){
		left=p;
		right=p;
	}
	else{
		p->next=left;
		left->prev=p;
		left=p;
	}
	printf("\t:> %d node inserted at First. ",v);
}

void insertLast(int v){
	struct node *p;
	p=create(v);
	if(left==NULL && right==NULL){
		left=p;
		right=p;
	}
	else{
		right->next=p;
		p->prev=right;
		right=p;
	}	
	printf("\t:> %d node inserted at last. ",v);
}

void insertLeftSide(int v,int after){
	struct node *p,*t=right;
	p=create(v);
	
	while(t!=NULL && t->data!=after){
		t=t->prev;
	}
	
	if(left==NULL && right==NULL){
		left=p;
		right=p;
	}
	else if(t==NULL){
		printf("\t:> The entered value does not exist in Linked-list !!!");
		return ;
	}
	else if(t==left){
		p->next=t;
		p->prev=NULL;
		t->prev=p;
		left=p;
	}
	else{
		p->prev=t->prev;
		t->prev->next=p;
		p->next=t;
		t->prev=p;
	}
	printf("\t:> %d node inserted. ",v);
}

void insertRightSide(int v,int after){
	struct node *p,*t=left;
	p=create(v);
	
	while(t!=NULL && t->data!=after){
		t=t->next;
	}
	
	if(left==NULL && right==NULL){
		left=p;
		right=p;
	}
	else if(t==NULL){
		printf("\t:> The entered value does not exist in Linked-list !!!");
		return ;
	}
	else if(t==right){
		p->prev=t;
		p->next=NULL;
		t->next=p;
		right=p;
	}
	else{
		p->next=t->next;
		t->next->prev=p;
		p->prev=t;
		t->next=p;
	}
	printf("\t:> %d node inserted. ",v);
}

void deletefirst(){
	struct node *p;
	int v;
	
	if(left==NULL && right==NULL){
		printf("\t:> Linked-list is empty !!! ",v);
		return ;
	}
	else if(left==right){
		v=left->data;
		left=NULL;
		right=NULL;
	}
	else{
		p=left;
		v=left->data;
		left=left->next;
		left->prev=NULL;
		p=NULL;
		
	}
	printf("\t:> %d node Deleted from first. ",v);
}

void deletelast(){
	struct node *p;
	int v;
	
	if(left==NULL && right==NULL){
		printf("\t:> Linked-list is empty ! ",v);
		return ;
	}
	else if(left==right){
		v=left->data;
		left=NULL;
		right=NULL;
	}
	else{
		p=right;
		v=right->data;
		right=right->prev;
		right->next=NULL;
		p=NULL;
	}
	printf("\t:> %d node Deleted from last. ",v);
}

void deleteLeftSide(){
	struct node *p,*t=right;
	int v,after;
	
	if(left==NULL && right==NULL){
		printf("\t:> Linked-list is empty ! ",v);
		return ;
	}
	
	printf("\t:> Enter value of a node whose previous node you want to delete: ");
	scanf("%d",&after);
				
	while(t!=NULL && t->data!=after){
		t=t->prev;
	}
	
	if(t==NULL){
		printf("\t:> The entered value does not exist in Linked-list !!!");
		return ;
	}
	else if(t==left){
		printf("\t:> No nodes are available on the left side of a given node. !!!");
		return ;
	}
	else{
		p=t->prev;
		v=p->data;
		if(p->prev==NULL){
			t->prev=NULL;
			left=t;
		}
		else{
			t->prev=p->prev;
			p->prev->next=t;
		}
		p=NULL;
		
	}
	printf("\t:> %d node deleted. ",v);
}

void deleteRightSide(){
	struct node *p,*t=left;
	int v,after;
	
	if(left==NULL && right==NULL){
		printf("\t:> Linked-list is empty ! ",v);
		return ;
	}
	
	printf("\t:> Enter value of a node whose next node you want to delete: ");
	scanf("%d",&after);
				
	while(t!=NULL && t->data!=after){
		t=t->next;
	}
	
	if(t==NULL){
		printf("\t:> The entered value does not exist in Linked-list !!!");
		return ;
	}
	else if(t==right){
		printf("\t:> No nodes are available on the right side of a given node. !!!");
		return ;
	}
	else{
		p=t->next;
		v=p->data;
		if(p->next==NULL){
			t->next=NULL;
			right=t;
		}
		else{
			t->next=p->next;
			p->next->prev=t;
		}
		p=NULL;
		
	}
	printf("\t:> %d node deleted. ",v);
}

void display(){
	struct node *t=left;
	if(t==NULL){
		printf("\t:> Link-list is empty...!!!"); 
		return;
	}
	printf("\n\tprev_Address | Value | next_Address\n");
	printf("\t-----------------------------------\n");
	while(t!=NULL){
		printf("\t%12u | %5d | %12u\n",t->prev,t->data,t->next);
		t=t->next;
	}
	printf("\n\tAddress of Left  node: %u",left);
	printf("\n\tAddress of Right node: %u",right);
}

