/*  PRANAV_JAGADEESH_1BM18CS071 */


#include <stdio.h>
#include <stdlib.h>

struct DLL
{
    int info;
    struct DLL *p, *n;
 };
typedef struct DLL *node;

node header=NULL;

node getnode();
void ins();
void insl();
void del();
void disp();

int main()
{
     int ch;
     while(1)
     {
             printf("\nChoices:");
             printf("\n\t1-Insert");
             printf("\n\t2-Insert left");
             printf("\n\t3-Delete node");
             printf("\n\t4-Display");
             printf("\n\t5-Exit");
             printf("\nEnter your choice: ");
             scanf("%d",&ch);
             switch(ch)
             {
                     case 1: ins();
                             break;
                     case 2: insl();
                             break;
                     case 3: del();
                             break;
                     case 4: disp();
                             break;
                     default:return 0;
             }
     }
}

node getnode()
{
     node x;
     x=(node) malloc(sizeof(struct DLL));
     return x;
}

void ins()
{
     node temp;
     int x;
     temp=getnode();
     printf("\nEnter the element to be inserted: ");
     scanf("%d",&x);
     temp->info=x;
     temp->p=NULL;
     temp->n=NULL;
     if(header==NULL)
             header=temp;
     else
     {
             temp->n=header;
             header->p=temp;
             header=temp;
     }
}

// function insl performs insertion to the left of the left of the node.
void insl()
{
     node temp,ele;
     int x, y;
     if(header==NULL)
     {
             printf("\nEmpty list\n");
             return;
     } 
     printf("\nEnter the element to be inserted: ");
     scanf("%d",&y);
     printf("\nTo left of which element should %d be inserted? Enter: ",y);
     scanf("%d",&x);
     temp=getnode();
     ele=header;
     temp->info=y;
     temp->p=NULL;
     temp->n=NULL;
     // Inserting at first node
     if(header->info==x)
     {
             temp->n=header;
             header->p=temp;
             header=temp;
     } 
     else
     {
             while(ele!=NULL)
             {
                     if(ele->info==x)
                             break;
                     ele=ele->n;
             }
             if(ele!=NULL)
             {
                     temp->p=ele->p;
                     (ele->p)->n=temp;
                     temp->n=ele;
                     ele->p=temp;
             } 
             else
                     printf("\nNo element found");

     }
}

// del function is used to delete the node
void del()
{
     node temp;
     int x;
     temp=header;
     if(header==NULL)
     {
             printf("\nNo element deleted.\n");
             return;
     } 
     printf("Enter the node to be deleted: ");
     scanf("%d",&x);
     // Delete the first node
     if(header->info==x)
     {
             temp=header;
             header=header->n;
             header->p=NULL;
             free(temp);
     } 
     // Deleting middle node
     else
     {
             while(temp!=NULL)
             {
                     if(temp->info==x)
                             break;
                     temp=temp->n;
             }
             if(temp!=NULL)
             {
                     if(temp->n!=NULL)
                     {
                             (temp->n)->p=temp->p;
                             (temp->p)->n=temp->n;
                             free(temp);
                     }
                     //Delete last node
                     else
                     {
                             (temp->p)->n=NULL;
                             free(temp);
                     }

             }
             else
             {
                     printf("Element not found");
             }
     }
}

// disp fuction displays the content of the list.
void disp()
{
     node temp;
     if(header==NULL)
             printf("DLL does not have any elements to display");
     else
     {
             for(temp=header;temp!=NULL;temp=temp->n)
                     printf("%d ",temp->info);
     } 
}
