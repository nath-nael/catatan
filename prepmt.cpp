#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

int initial=0;
struct Node{
	char category[20];
	char detail[20];
	int amount;
	Node *next;
	Node *prev;
}*head=NULL,*tail=NULL;
Node *createNode(char category[],char detail[],int amount){
	Node *newNode=(Node*)malloc(sizeof(Node));
	strcpy(newNode->category,category);
	strcpy(newNode->detail,detail);	
	newNode->amount=amount;
	newNode->next=newNode->prev=NULL;
	return newNode;
}
void push(char category[],char detail[],int amount){
	Node *newNode=createNode(category,detail,amount);
	if(!head){
		head=tail=newNode;
	}else{
		tail->next=newNode;
		newNode->prev=tail;
		tail=newNode;
		tail->next=NULL;
	}
}
int costFood=0;
int costHouse=0;
int costEnter=0;
int costOther=0;
void countCost(){
	if(!head)return;
	else{
		Node *curr=head;
		while(curr){
			if(strcmp(curr->category,"food")==0){
				costFood+=curr->amount;
			}
			else if(strcmp(curr->category,"house")==0){
				costHouse+=curr->amount;
			}
			else if(strcmp(curr->category,"entertainment")==0){
				costEnter+=curr->amount;
			}
			else if(strcmp(curr->category,"other")==0){
				costOther+=curr->amount;
			}
			curr=curr->next;
		}
		int cost=costFood+costHouse+costEnter+costOther;
		initial-=cost;
	}
}
void view1(){
	if(!head)return;
	else{
		printf("food : %d\n",costFood);
		printf("house : %d\n",costHouse);
		printf("entertainment: %d\n",costEnter);
		printf("other : %d\n",costOther);
	}
	printf("==================\n");
}
void view2(){
	if(!head)return;
	else{
		Node *curr=head;
		while(curr){
			printf("%s (%s) : %d\n",curr->detail,curr->category,curr->amount);
			curr=curr->next;
		}
	}
	printf("\n");
}
void remove(char detail[]){
	if(!head)return;
	else{
		if(strcmp(head->detail,detail)==0){
			if(head==tail){
				head=tail=NULL;
				return;
			}
			Node *curr=head;
			head=head->next;
			head->prev=NULL;
		}
		else if(strcmp(tail->detail,detail)==0){
			tail=tail->prev;
			tail->next=NULL;
		}
		Node *curr=head;
		while(curr){
			if(strcmp(detail,curr->detail)==0){
				initial+=curr->amount;
				curr->next->prev=curr->prev;
				curr->prev->next=curr->next;
				free(curr);
			}
			curr=curr->next;
		}
		
	}
}
int main(){
	scanf("%d",&initial);
	int temp=initial;
	int num;
	scanf("%d",&num);
	char category[20],detail[20];
	int amount;
	for(int i=1;i<=num;i++){
		scanf("%s %s %d",category,detail,&amount);
		push(category,detail,amount);
	}
	char detail2[20];
	scanf(" %s",detail2);
	remove(detail2);
	countCost();
	printf("Acount Balance: %d\n",initial);
	view1();
	view2();
	
}
