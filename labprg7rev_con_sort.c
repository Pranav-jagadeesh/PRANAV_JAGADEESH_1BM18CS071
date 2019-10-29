/* Program to sort ,reverse and concatenate single linked list.
PRANAV_JAGADEESH_1BM18CS071*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
}*stnode,*stnode2;
void display(struct node* head)
{
      struct node *temp = head;
      while(temp != NULL)
      {
   printf("%d --->",temp->data);
   temp = temp->next;
      }
}

void createNodeList1(int n)
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

void createNodeList2(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode2 = (struct node *)malloc(sizeof(struct node));
    

    if(stnode2 == NULL) //check whether the fnnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode2->data = num;      
        stnode2->next = NULL; // links the address field to NULL
        tmp = stnode2;
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
/* function to swap data of two nodes a and b*/
void swap1(struct node *a, struct node *b) 
{ 
	int temp = a->data; 
	a->data = b->data; 
	b->data = temp; 
} 

/* Bubble sort the given linked list */
void bubbleSort(struct node *start) 
{ 
	int swapped, i; 
	struct node *ptr1; 
	struct node *lptr = NULL; 

	/* Checking for empty list */
	if (start == NULL) 
		return; 

	do
	{ 
		swapped = 0; 
		ptr1 = start; 

		while (ptr1->next != lptr) 
		{ 
			if (ptr1->data > ptr1->next->data) 
			{ 
				swap1(ptr1, ptr1->next); 
				swapped = 1; 
			} 
			ptr1 = ptr1->next; 
		} 
		lptr = ptr1; 
	} 
	while (swapped); 
} 




/* Function to reverse the linked list */
static void reverse(struct node** head_ref) 
{ 
	struct node* prev = NULL; 
	struct node* current = *head_ref; 
	struct node* next = NULL; 
	while (current != NULL) { 
		// Store next 
		next = current->next; 

		// Reverse current node's pointer 
		current->next = prev; 

		// Move pointers one position ahead. 
		prev = current; 
		current = next; 
	} 
	*head_ref = prev; 
} 

void concatenate(struct node *a,struct node *b)
{
    if( a != NULL && b!= NULL )
    {
        if (a->next == NULL)
            a->next = b;
        else
            concatenate(a->next,b);
    }
    else
    {
        printf("Either a or b is NULL\n");
    }
}


int main()
 {
	int choice;
    int n,n2;
		printf("-------------------------------------------------------------\n");
		
    printf(" Input the num of nodes you want to create : ");
    scanf("%d", &n);
    createNodeList1(n);
    struct node *head;
  head = stnode; //Save address of first node in head
  printf("\nIntial list\n");
  display(head);
  while(1)
  {
  printf("\n1.sort list \n2.reverse list \n3.concatenate two lists \n4.exit \n");
  scanf("%d",&choice);
  
   switch(choice)
   {
    case 1:{ 
             /* sort the linked list */
        	bubbleSort(head);
	        printf("\nThe sorted list is:\n");
	        display(head);
			break; 
          }    
	 case 2:{
	         /* reverse the linked list */
	         reverse(&head); 
	        printf("\nThe reversed list is:\n");
	        display(head);
			break;
		    }
	 case 3:{
	          /* concate the linked list */
	          printf(" Input the num of nodes you want to create for second node : ");
              scanf("%d", &n2);
              createNodeList2(n2);
              struct node *head2;
              head2 = stnode2; //Save address of first node in head
              printf("\nIntial list\n");
              display(head2); 
              printf("\nConcatenated list:\n");
              concatenate(head,head2);
              display(head);
              break;
            }
   case 4:{
   	       exit(0);
          }
   default:{
   	        printf("Invalid choice\n");
	        break;
           }
   }
  }
          return(0);
}
