#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;          // Data
    struct node *next; // Address 
}*head;

void createList(int n);
void deleteFromFront();
void deleteFromMiddle(int position);
void deleteFromEnd();
void displayList();

int main()
{
    int n, choice,position;

    /*
     * Create a singly linked list of n nodes
     */
     
    printf("\n\n Linked List : To create and display Singly Linked List :\n");
	printf("-------------------------------------------------------------\n");
    printf(" Input the num of nodes you want to create : ");
    scanf("%d", &n);
    createList(n);
    printf("\nIntial list \n");
    displayList();
    
    while(1)
  {
	printf("\n\n 1. Delete at front\n 2. Delete at given position\n 3. Delete at end \n 4. Display\n 5.Exit");
	printf("\n\nenter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		{
			 /* Delete first node from list */
            deleteFromFront();
			displayList(); 
			break;
		}
		case 2:
		{
			printf("\nEnter the position to delete element\n");
			scanf("%d",&position);
			 /* Delete middle node from list */
            deleteFromMiddle(position);
            displayList(); 
			break;
		}
		case 3:
		{
			/* Delete last node from list */
            deleteFromEnd();
            displayList(); 
			break;
		}
		case 4:
		{
			printf("\nData in the list \n");
            displayList(); 
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

    return 0;
}

/*
 * Create a list of n nodes
 */
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    /*
     * If unable to allocate memory for head node
     */
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        /*
         * Input data of node from the user
         */
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; // Link the data field with data
        head->next = NULL; // Link the address field to NULL

        temp = head;

        /*
         * Create n nodes and adds to linked list
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            /* If memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; // Link the data field of newNode with data
                newNode->next = NULL; // Link the address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

/*
 * Deletes the first node of the linked list
 */
void deleteFromFront()
{
    struct node *toDelete;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        head = head->next;

        printf("\nData deleted = %d\n", toDelete->data);

        /* Clears the memory occupied by first node*/
        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}

/*
 * Delete middle node of the linked list
 */
void deleteFromMiddle(int position)
{
    int i;
    struct node *toDelete, *prevNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        prevNode = head;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == head)
                head = head->next;

            prevNode->next = toDelete->next;
            toDelete->next = NULL;

            /* Delete nth node */
            free(toDelete);

            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }
}


/*
 * Delete last node of the linked list
 */
void deleteFromEnd()
{
    struct node *toDelete, *secondLastNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;

        /* Traverse to the last node of the list */
        while(toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == head)
        {
            head = NULL;
        }
        else
        {
            /* Disconnect link of second last node with last node */
            secondLastNode->next = NULL;
        }

        /* Delete the last node */
        free(toDelete);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}


/*
 * Display entire list
 */
void displayList()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL
     */
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d --->",temp->data); // Print the data of current node
            temp = temp->next;                // Move to next node
        }
    }
}
