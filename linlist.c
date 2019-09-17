#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
  
  void display(struct node *head)
  {
   struct node *temp=head;
   printf("\nlist elements are:\n");
   while(temp!=NULL)
   {
    printf("%d --->",temp->data);
    temp=temp->next;
   }
  }
  
  void insertAtFront(struct node* *headRef,int value)
  {
   struct node *head=*headRef;
   struct node *newNode;
   newNode=malloc(sizeof(struct node));
   newNode->data=value;
   newNode->next=head;
   head=newNode;
   *headRef=head;
  } 
  
  void insertAtEnd(struct node* head,int value)
  {
   struct node *newNode;
   newNode=malloc(sizeof(struct node));
   newNode->data=value; 
   newNode->next=NULL;
   struct node *temp=head;
   while(temp->next!=NULL)
   {
    temp=temp->next;
   }
   temp->next=newNode;
  }
  
   int main()
   {
    int ele;
    int choice;
    int position;
    
    struct node *head;
    struct node *one=NULL;
    struct node *two=NULL;
    struct node *three=NULL;
    
    one=malloc(sizeof(struct node));
    two=malloc(sizeof(struct node));
    three=malloc(sizeof(struct node));

    one->data=1;
    two->data=2;
    three->data=3;
    
    one->next=two;
    two->next=three;
    three->next=NULL;
    
    head=one;
    display(head);
    while(1)
    {
    printf("\n1.front 2.end 3.display 4.exit");
    printf("\nenter choice");
    scanf("%d",&choice);
    
    switch(choice)
   {
    case 1:{printf("\nenter element:");
           scanf("%d",&ele);
           insertAtFront(&head,ele);
           display(head);
           break;}
    case 2:{printf("\nenter element:");
           scanf("%d",&ele);
           insertAtEnd(head,ele);
           display(head);
           break;}
   case 3:{display(head);
          break;}
   case 4:break;
   default:{ printf(":invalid choice:");break;}
 }
 }
return 0;
}


   
