#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
}*stnode;

 void display(struct node* head)
 {
      struct node *temp = head;
      while(temp != NULL)
      {
       printf("%d --->",temp->data);
       temp = temp->next;
      }
 }

 void deleteFromFront(struct node* head)
 {
    printf("\nList after deleting from front\n");
    struct node* temp =  head;
    temp = temp->next;
    //*headRef = head;
    free(head);
 }

 void deleteFromEnd(struct node* head)
 {
    printf("\nList after deleting from end\n");
    struct node* temp = head;
    struct node* prev = NULL;
    while(temp->next!=NULL)
    {
	prev=temp;
     temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
 }

 void deleteFromMiddle(struct node* head, int position)
 {
    printf("\nList after deleting from specified location\n");
    struct node* temp = head;
    int i;
    for(i=2; i< position; i++)
    {
     if(temp->next!=NULL)
     {
        temp = temp->next;
     }
    }
  temp->next = temp->next->next;
  free(temp);
 }

 void createNodeList(int n)
 {
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));

    if(stnode == NULL) //check whether the fnnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
     // reads data for the node through keyboard

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode->data = num;      
        stnode->next = NULL; // links the address field to NULL
        tmp = stnode;
     // Creating n nodes and adding to linked list
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
 
                fnNode->data = num;      // links the num field of fnNode with num
                fnNode->next = NULL; // links the address field of fnNode with NULL
 
                tmp->next = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->next; 
            }
        }
    }
 }




 int main()
 {
  int choice;
  int position;
  int n;
		printf("\n\n Linked List : To create and display Singly Linked List :\n");
		printf("-------------------------------------------------------------\n");
		
    printf(" Input the num of nodes you want to create : ");
    scanf("%d", &n);
    createNodeList(n);
    struct node *head;
  head = stnode; //Save address of first node in head
  printf("\nIntial list\n");
  display(head); 
  while(1)
  {
	printf("\n\n 1. Delete at front\n 2. Delete at given position\n 3. Delete at end \n 4. Display\n 5.Exit");
	printf("\n\nenter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		{
			deleteFromFront(head);
			display(head); 
			break;
		}
		case 2:
		{
			printf("\nEnter the position to delete element\n");
			scanf("%d",&position);
			deleteFromMiddle(head, position);
			display(head);
			break;
		}
		case 3:
		{
			deleteFromEnd(head);
			display(head);
			break;
 		}
		case 4:
		{
			display(head); 
			break;
		}
		case 5:
		{
			exit(0);
		}
		default:
		{
			printf("Invalid choice --> Enter a valid choice from menu \n");
			break;
		}		
	}
  }
 } 
