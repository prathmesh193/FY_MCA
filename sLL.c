#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node* createNode(int value)
{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	if(newNode==NULL)
	{
		printf("Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	newNode->data=value;
	newNode->next=NULL;
	return newNode;
}

void insertEnd(struct Node** head,int value)
{
	struct Node* newNode= createNode(value);
	if(*head==NULL)
	{
		*head=newNode;
		return;
	}
	struct Node* current=*head;
	while(current->next!=NULL)
	{
		current=current->next;
	}
	current->next=newNode;
}
void deleteNode(struct Node** head,int value)
{
	if(*head==NULL)
	{
		printf("List is empty.Cannot Delete.\n");
		return;
	}
	struct Node* temp=*head;
	struct Node* prev=NULL;
	
	if(temp!=NULL && temp->data == value)
	{
		*head = temp->next;
		free(temp);
		printf("Node with the value %d deleted.\n",value);
		return;
	}
	//Search for the node to be deleted
	while(temp!=NULL && temp->data!=value)
	{
		prev=temp;
		temp=temp->next;
	}
	//IF node is not present
	if(temp==NULL)
	{
		printf("Node with value %d not found.\n",value);
		return;
	}
	
	//Unlink the node from the linked list
	prev->next=temp->next;
	free(temp);
	printf("Node with the value % deleted.\n",value);
}

void reverseList(struct Node** head)
{
	struct Node* prev= NULL;
	struct Node* current= *head;
	struct Node* next=NULL;
	
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	*head=prev;
	printf("Linked list reversed.\n");
}
void searchNode(struct Node* head,int value)
{
	struct Node* current=head;
	int position=1;
	while(current!=NULL)
	{
		if(current->data==value)
		{
			printf("Node with the value %d found at position %d.\n",value,position);
			return;
		}
		current=current->next;
		position++;
	}
	printf("Node with the value %d not found.\n",value);
}
int countNodes(struct Node* head)
{
	int count=0;
	struct Node* current=head;
	while(current!=NULL)
	{
		count++;
		current=current->next;
	}
	return count;
}

void displayList(struct Node* head)
{
	if(head==NULL)
	{
		printf("List is Empty.\n");
		return;
	}
	struct Node* current=head;
	while(current!=NULL)
	{
		printf("%d->",current->data);
		current=current->next;
	}
	printf("NULL\n.");
}
void freeList(struct Node** head)
{
	struct Node* current=*head;
	struct Node* next;
	while(current!=NULL)
	{
		next=current->next;
		free(current);
		current=next;
	}
	*head=NULL;
}


int main()
{
	struct Node* head= NULL;
	int ch,value;
	do
	{
	
		printf("------MENU------\n");
		//printf("1.Create\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Reverse\n");
		printf("4.Search\n");
		printf("5.Count\n");
		printf("6.Display\n");
		printf("0.EXIT\n");
		printf("Enter your Choice: ");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1:
				printf("Enter the value to be insert:");
				scanf("%d",&value);
				insertEnd(&head,value);
				break;
			case 2:
				printf("Enter the value to be deleted:");
				scanf("%d",&value);
				deleteNode(&head,value);
				break;
			case 3:
				reverseList(&head);
				break;
			case 4:
				printf("Enter the value to be searched: ");
				searchNode(head,value);
				break;
			case 5:
				printf("Number of nodes: %d\n",countNodes(head));
				break;
			case 6:
				displayList(head);
				break;
			case 0:
				freeList(&head);
				printf("Program Exited.\n");
				break;
			default:
				printf("Invalid Choice. Please enter the valid option\n.");	
		}
	}while (ch!=0);
	
	return 0;
}