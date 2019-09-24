/*PRANAV_JAGADEESH_1BM18CS071*/


#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
void display(struct node* head)
{
      struct node *temp = head;
      printf("\n\nList elements are - \n");
      while(temp != NULL)
      {
   printf("%d --->",temp->data);
   temp = temp->next;
      }
}
void insertAtMiddle(struct node *head, int position, int value) {
    struct node *temp = head;
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;
    
    int i;
    for(i=2; i < position; i++) 
	{
    if(temp->next != NULL)
	 {
        temp = temp->next;
    }
}
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAtFront(struct node** headRef, int value) {
    struct node* head = *headRef;
    
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    
    *headRef = head;
}
void insertAtEnd(struct node* head, int value){
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    
    struct node *temp = head;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = newNode;
}



int main() {
	int ele;      
    int choice;
    int position;
  /* Initialize nodes */
  struct node *head;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;
  /* Allocate memory */
  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));
  /* Assign data values */
  one->data = 1;
  two->data = 2;
  three->data = 3;
  /* Connect nodes */
  one->next = two;
  two->next = three;
  three->next = NULL;
  /* Save address of first node in head */
  head = one;
  display(head);
  while(1) 
  {
      printf("\n\n 1.Insert at front\n 2.Insert at given position \n 3.Insert at end \n 4.Display\n 5.Exit");
      
      printf("\nEnter your choice\n");
      scanf("%d", &choice);
      
      switch(choice)
      {
          case 1: {
              printf("\nEnter element to be inserted at front\n");
              scanf("%d", &ele);
              insertAtFront(&head, ele);
              display(head);
              break;
              
                  }
          
          case 2: { 
          			printf("\nEnter element to be inserted at given position\n");
                    scanf("%d", &ele);
          			printf("\nEnter position\n");
          			scanf("%d", &position);
		  			insertAtMiddle(head, position, ele);
                    display(head);
                    break;
                  }
          case 3: {
              printf("\nEnter element to be inserted at end\n");
              scanf("%d", &ele);
              insertAtEnd(head, ele);
              display(head);
              
              break;
              
                  }
          case 4: { display(head);
                    
                    break;
                  }   
		  case 5: { exit(0);
                    
                  } 
		  default: 
		  {
		  	printf("\n Invalid choice -> Enter a valid choice from menu \n");
			break;
		  }   
        }        
  } 
    
 return 0;
}



   
