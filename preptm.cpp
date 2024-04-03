#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
	int id;
	char task[20];
	char employ[20];
	char due[20];
	Node *next;
	Node *prev;
}*head=NULL,*tail=NULL;

Node *createNode(int id, char task[],char employ[], char due[]){
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->id=id;
	strcpy(newNode->task,task);
	strcpy(newNode->employ,employ);
	strcpy(newNode->due,due);
	newNode->next=newNode->prev=NULL;
	return newNode;
}
void insertNode(int id, char task[],char employ[], char due[]){
	Node *newNode=createNode(id,task,employ,due);
	if(!head){
		head=tail=newNode;
	}else{
		if(strcmp(newNode->due,head->due)<0){
			newNode->next=head;
			head->prev=newNode;
			head=newNode;
		}else if(strcmp(newNode->due,tail->due)>=0){
			tail->next=newNode;
			newNode->prev=tail;
			tail=newNode;
		}else{
			Node *curr=head;
			while(curr){
				if(strcmp(newNode->due,curr->due)>0){
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
void viewAll(){
	if(!head){
		printf("No Data\n");
	}else{
		Node *curr=head;
		while(curr){
			printf("=======\nID : %d\nTask %s\nEmployee: %s\nDue Date : %s\n=======",curr->id,curr->task,curr->employ,curr->due);
			curr=curr->next;
		}
	}
	printf("\n");
}
void viewPart(int count){
	if(!head){
		printf("No Data\n");
	}else{
		Node *curr=head;
		int start=0;
		while(curr&&start<count){
			printf("=======\nID : %d\nTask %s\nEmployee: %s\nDue Date : %s\nStatus : Completed\n=======",curr->id,curr->task,curr->employ,curr->due);
			start++;
			curr=curr->next;
		}
	}
	printf("\n");
}
void removePart(int count){
	while(count>0&&head){
		Node *temp = head;
        head = head->next;
        if (head)
            head->prev = NULL;
        free(temp);
        count--;
	}
}
int main(){
	int count;
	char task[20],employ[20],due[20];
	printf("Number of tasks : ");
	scanf("%d",&count); getchar();
	for(int i=1;i<=count;i++){
		printf("Task Description : ");
		scanf("%[^\n]",task);getchar();
		printf("Assigned Employee : ");
		scanf("%s",employ); getchar();
		printf("Due Date : ");
		scanf("%s",due); getchar();
		insertNode(i,task,employ,due);
	}
	viewAll();
	printf("Is there any done tasks? ");
	char ans[20];
	scanf("%s",ans);getchar();
	if(strcmp(ans,"Yes")==0){
		int count;
		printf("How many?");
		scanf("%d",&count);
		viewPart(count);
		removePart(count);
	}
	printf("The rest tasks : \n");
	viewAll();
}
