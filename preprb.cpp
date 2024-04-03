#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
	char card[5];
	Node *next;
	Node *prev;
}*head1=NULL,*head2=NULL,*tail1=NULL,*tail2=NULL;

Node *createNode(char card[]){
	Node *newNode=(Node*)malloc(sizeof(Node));
	strcpy(newNode->card,card);
	newNode->next=newNode->prev=NULL;
	return newNode;
}
void insertCard(char card[],Node **head,Node **tail){
	Node *newNode=createNode(card);
	if(!*head){
		*head=*tail=newNode;
	}else{
		//pushtail
		(*tail)->next=newNode;
		newNode->prev=*tail;
		(*tail)=newNode;
	}
}
void printElement(Node **head){
	if(!(*head)){
		return;
	}
	Node *curr=*head;
	while(curr->next!=NULL){
		printf("%s <-> ",curr->card);
		curr=curr->next;
	}
	printf("%s\n",curr->card);
}
void removeElement(char card[],Node **head,Node **tail){
	if(!(*head))return;
	else{
		Node *curr=*head;
		if(strcmp(curr->card,card)==0){
			if(*head==*tail){
				*head=*tail=NULL;
			}else{
				(*head)=(*head)->next;
				(*head)->prev=NULL;
				free(curr);
			}
		}
		else if(strcmp((*tail)->card,card)==0){
			(*tail)=(*tail)->prev;
			(*tail)->next=NULL;
		}else{
			while(curr){
				if(strcmp(curr->card,card)==0){
					curr->next->prev=curr->prev;
					curr->prev->next=curr->next;
				}
				curr=curr->next;
			}
		}
		
	}
}
void calculatePoint(Node* head1, Node* head2, int* AndyPt, int* BobPt){
    Node* currAndy = head1;
    Node* currBob = head2; 
    while(currAndy != NULL && currBob != NULL){
        if(currAndy->card[0] > currBob->card[0]){
            (*AndyPt)++;
        }else if(currAndy->card[0] < currBob->card[0]){
            (*BobPt)++;
        }else{
            if(currAndy->card[1] == 'R' && currBob->card[1] == 'B'){
                (*AndyPt)++;
            }else if(currAndy->card[1] == 'B' && currBob->card[1] == 'R'){
                (*BobPt)++;
            }
        }
        currAndy = currAndy->next;
        currBob = currBob->next;
    }
}
int main(){
	char andyCard[][5] = {"7R", "4R", "6B", "0B", "8R", "5R", "3B"};
    char bobCard[][5] = {"1B", "7B", "2R", "9R", "0R", "5B", "3R"};
    
    for(int i=0;i<7;i++){
    	insertCard(andyCard[i],&head1,&tail1);
	}
	for(int i=0;i<7;i++){
    	insertCard(bobCard[i],&head2,&tail2);
	}
	printf("Andy discard card phase\n");
    printElement(&head1);
    char firstAndy[5], secondAndy[5];
    
    printf("Enter 1st card label to delete: ");
    scanf("%s", firstAndy);
    removeElement(firstAndy, &head1,&tail1);
    printf("Modified link list after 1st deletion: \n");
    printElement(&head1);
    
    printf("Enter 2st card label to delete: ");
    scanf("%s", secondAndy);
    removeElement(secondAndy, &head1,&tail1);
    printf("Modified link list after 2st deletion: \n");
    printElement(&head1);
    
    printf("Bob discard card phase\n");
    printElement(&head2);
    char firstBob[5], secondBob[5];
    
    printf("Enter 1st card label to delete: ");
    scanf("%s", firstBob);
    removeElement(firstBob, &head2,&tail2);
    printf("Modified link list after 1st deletion: \n");
    printElement(&head2);
    
    printf("Enter 2st card label to delete: ");
    scanf("%s", secondBob);
    removeElement(secondBob, &head2,&tail2);
    printf("Modified link list after 2st deletion: \n");
    printElement(&head2);
	
	printf("Andy Cards:\n");
    printElement(&head1);

    printf("Bob Cards:\n");
    printElement(&head2);
    
    int AndyPt = 0, BobPt = 0;
    calculatePoint(head1, head2, &AndyPt, &BobPt);

    printf("Andy's points: %d\n", AndyPt);

    printf("Bob's points: %d\n", BobPt);

    if(AndyPt > BobPt){
        printf("Andy wins!\n");
    }else if(AndyPt < BobPt){
        printf("Bob wins!\n");
    }else{
        printf("It's a tie!\n");
    }


}
