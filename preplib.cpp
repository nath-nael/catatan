#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
	char nama[20];
	Node *next;
	Node *prev;
}*head=NULL,*tail=NULL;

Node *createNode(char nama[]){
	Node *newNode=(Node*)malloc(sizeof(Node));
	strcpy(newNode->nama,nama);
	newNode->next=newNode->prev=NULL;
	return newNode;
}
void insertNode(char nama[]){
	Node *newNode=createNode(nama);
	if(!head){
		head=tail=newNode;
	}else{
		if(strcmp(newNode->nama,head->nama)<0){
			newNode->next=head;
			head->prev=newNode;
			head=newNode;
		}else if(strcmp(newNode->nama,tail->nama)>=0){
			tail->next=newNode;
			newNode->prev=tail;
			tail=newNode;
		}else{
			Node *curr=head;
			while(curr){
				if(strcmp(newNode->nama,curr->nama)>0){
					break;
				}
				curr=curr->next;
			}
			newNode->next=curr;
			newNode->prev=curr->prev;
			curr->prev=newNode;
		}
	}
}
void view(){
	if(!head){
		printf("No data\n");
	}else{
		printf("===================\n");
		Node *curr=head;
		while(curr){
			printf("Name : %s\n",curr->nama);
			curr=curr->next;
		}
	}
	puts("==================");
}
Node *searchNode(char nama[]){
	Node *curr=head;
	do{
		if(strcmp(curr->nama,nama)==0){
			return curr;
		}
		curr=curr->next;
	}while(curr);
	return NULL;
}
void deleteNode(Node *del){
		if(head==tail){
			head=tail=NULL;
			free(del);
		}
		else if(head==del){
			head=head->next;
			head->prev=NULL;
			free(del);
		}else if(tail==del){
			tail=tail->prev;
			tail->next=NULL;
			free(del);
		}else{
			del->next->prev=del->prev;
			del->prev->next=del->next;
		}
}
void remove(){
	char nama[20];
	printf("Hapus nama :");
	scanf("%s",nama);
	getchar();
	Node *del=searchNode(nama);
	if(!del){
		printf("No data\n");
	}else{
		deleteNode(del);
	}
}
void removeAll(){
	Node *curr=head;
	while(curr){
		deleteNode(curr);
		curr=curr->next;
		
	}
}
void add(){
	char nama[20];
	printf("Nama : ");
	scanf("%s",nama);
	getchar();
	insertNode(nama);
}
	void update(){
		printf("Update Nama : ");
		char nama[20];
		scanf("%s",nama); getchar();
		Node *up=searchNode(nama);
		if(!up){
			printf("Not found\n");
		}else{
			char newNama[20];
			printf("New Nama : ");
			scanf("%s",newNama);
			getchar();
			deleteNode(up);
			insertNode(newNama);
		}
	}
void menu(){
	int opt=-1;
	do{
		view();
		printf("1. Add\n");
		printf("2. View\n");
		printf("3. Update\n");
		printf("4. Delete\n");
		printf("5. Delete All\n");
		printf("6. Exit\n>> ");
		scanf("%d",&opt);
		getchar();
		switch(opt){
			case 1:{
				add();
				break;
			}
			case 2:{
				view();
				break;
			}
			case 3:{
				update();
				break;
			}
			case 4:{
				remove();
				break;
			}
			case 5:{
				removeAll();
				break;
			}
		}
	}while(opt!=6);
}
int main(){
	menu();
}
