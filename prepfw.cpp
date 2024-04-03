#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
	int a;
	Node *next;
	Node *prev;
}*head=NULL,*tail=NULL;
Node *createNode(int a){
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->a=a;
	newNode->next=newNode->prev=NULL;
	return newNode;
}
void pushTail(int a){
	Node *newNode=createNode(a);
	if(!head){
		head=tail=newNode;
	}else{
		tail->next=newNode;
		newNode->prev=tail;
		tail=newNode;
		tail->next=NULL;
	}
}
void popMid(int cancel){
	if(!head)return;
	else{
		if(head->a==tail->a==cancel){
			head=tail=NULL;
		}else if(head->a==cancel){
			head=head->next;
			head->prev=NULL;
		}else if(tail->a==cancel){
			tail=tail->prev;
			tail->next=NULL;
		}else{
			Node *curr=head;
			while(curr){
				if(curr->a==cancel){
					curr->next->prev=curr->prev;
					curr->prev->next=curr->next;
				}
				curr=curr->next;
			}
		}
	}
}
void printList(){
	if(!head)return;
	else{
		Node *curr=head;
		while(curr){
			printf("%d ",curr->a);
			curr=curr->next;
		}
	}
}
int main(){
    int n1, n2;
    scanf("%d %d", &n1, &n2);getchar();

    int online[n1], walkin[n2];
    for(int i = 0; i < n1; i++){
        scanf("%d", &online[i]);getchar();
    }
    for(int j = 0; j < n2; j++){
        scanf("%d", &walkin[j]);getchar();
    }

    int list[n1+n2];
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2){
        list[k++] = online[i++];
        list[k++] = walkin[j++];
    }
    while(i < n1){
        list[k++] = online[i++];
    }
    while(j < n2){
        list[k++] = walkin[j++];
    }
    for(int i = 0; i < n1+n2; i++){
        pushTail(list[i]);
    }

    int c, cancel;
    scanf("%d", &c);getchar();
    for(int i = 0; i < c; i++){
        scanf("%d", &cancel);
        popMid(cancel);
    }

    printList();
    // deallocate(head);

    return 0;
}
