
//PRANAV_JAGADEESH_1BM18CS071

// A complete working C program to demonstrate stack and queue implementation using linked List 
#include <stdio.h> 
#include <stdlib.h> 

// A linked list node 
struct Node 
{ 
int data; 
struct Node *next; 
}; 

/* Given a reference (pointer to pointer) to the head of a list and 
an int, inserts a new node on the front of the list. */
void insertFront(struct Node** head_ref, int new_data) 
{ 
	/* 1. allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 

	/* 2. put in the data */
	new_node->data = new_data; 

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref); 

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node; 
} 


/* Given a reference (pointer to pointer) to the head 
of a list and an int, appends a new node at the end */
void insertRear(struct Node** head_ref, int new_data) 
{ 
	/* 1. allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 

	struct Node *last = *head_ref; /* used in step 5*/

	/* 2. put in the data */
	new_node->data = new_data; 

	/* 3. This new node is going to be the last node, so make next of 
		it as NULL*/
	new_node->next = NULL; 

	/* 4. If the Linked List is empty, then make the new node as head */
	if (*head_ref == NULL) 
	{ 
	*head_ref = new_node; 
	return; 
	} 

	/* 5. Else traverse till the last node */
	while (last->next != NULL) 
		last = last->next; 

	/* 6. Change the next of last node */
	last->next = new_node; 
	return; 
} 


/*
 * Deletes the first node of the linked list
 */
void deleteAtFront(struct Node **head_ref)
{
	struct Node* toDelete = *head_ref;
    

    if(toDelete == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        
        *head_ref = toDelete->next;
        //toDelete = head_ref;

        printf("\nData deleted = %d\n", toDelete->data);

        /* Clears the memory occupied by first node*/
        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}

// This function prints contents of linked list starting from head 
void printList(struct Node *node) 
{ 
while (node != NULL) 
{ 
	printf(" %d ", node->data); 
	node = node->next; 
} 
} 

/* Driver program to test above functions*/
int main() 
{ 
/* Start with the empty list */
struct Node* head = NULL; 

int choice,value;
while(1)
{
	
 printf("\n Enter your choice: \n 1: Insert Front \n 2: Insert Rear 3: Delete First Node \n 4: Display \n 5: Exit \n");
 scanf("%d",&choice);
 switch(choice)
{
    case 1: 
    printf("Enter the data for node:");
    scanf("%d",&value);
    insertFront(&head,value);
    break;
    
    case 2: 
    printf("Enter the data for node:");
    scanf("%d",&value);
    insertRear(&head,value);
     break;
    
    case 3: 
    deleteAtFront(&head);
     break;
     
    case 4:
    printf("\n Created Linked list is: "); 
    printList(head);
    break;
    
    case 5:
    printf("\n Exiting ");
    exit(0);
    break;
    
    default:
    printf("\n Wrong choice");
    
    
}
}

return 0; 
} 

