
/*include header file*/

#include<stdio.h>
#include<stdlib.h>

/*--------
Note: When we are using turbo c,c++ IDE then include this header file.

#include<conio.h>

And getch() function can be used hold output screen.
---------*/


/*structure of linked list*/
struct Node{
  
  int data;// linked list data 
  struct Node*next;// pointer field
  
}*root;/*global linked list point*/

/* Function declaration section here */
void insert_ascending_order(int);
void show_data(struct Node*);

/* Help of this function assign newly created node at ascending 
  (depends on node data) order position.*/
void insert_ascending_order(int value){
  
  /*Create dynamic memory block using malloc function. */
  struct Node*temp ,*new_node=(struct Node*)malloc(sizeof(struct Node));
  
  /*Check new_node is null or not */
  if(new_node)
  {   
      /*assign user data value to new created node*/
    new_node->data=value;
  
    /*base condition if linked list pointer is NULL*/
    if(root==NULL)
    {
      /* initialize first node in root pointer*/
      root=new_node;
      new_node->next=NULL;
    }
    else
    { /*base condition root data value more then new inserted*/
      if(root->data>=value){
        /*add new created not at start of linked list*/
        new_node->next=root;
        /*root is pointed to this new created node*/
        root=new_node;
      }
      else{
        temp=root;

        /* find appropriate position to add new created node */
        while(temp->next!=NULL&&temp->next->data<value)
        {
          /*move on next pointer*/
          temp=temp->next;
          
        }
        if(temp->next==NULL){
          /*insert new element(node) in last position*/
          new_node->next=NULL;
          temp->next=new_node;
        }
        else{
          /*insert node in middle of linked list*/
          new_node->next=temp->next;
          temp->next=new_node;
        }
        
      }
    
    }
  }
  else
  {
    /*malloc function not create dynamic memory this case showing this message*/
    printf("\n Memory overflow try again..!");
  }
}


/* Help of this function showing all element of single linked list */
void show_data(struct Node*temp){
  if(temp==NULL){
    /*linked list are empty*/
    printf("Empty linked List\n");
  }
  else
  {
    /*When linked list are not empty*/
    printf("Linked list data is : ");
    while(temp)
    {
      /*print linked list data*/
      printf("%d  ",temp->data);

      /*move next memory block*/
      temp=temp->next;
    }
    
  }
}


int main(){
    int i,n,data;
  /* start program execution are here */
  
    printf("\nThis program sorts the elements in ascending order while inserting\n");
    printf("Enter number of nodes to be created:");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("\nEnter the data to be inserted in node %d:",(i+1));
        scanf("%d",&data);
        insert_ascending_order(data);
        show_data(root);
    }
    
    
   /*show_data functions showing result after inserted all newly created node*/
  printf("\nThe Final sorted list\n");
  show_data(root);
    
  
  /*end execution*/
}

    
