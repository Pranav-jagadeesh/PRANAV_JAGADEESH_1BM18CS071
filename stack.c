#include<stdio.h>
#include<process.h>
#define MAX_SIZE 3
int item[MAX_SIZE];
int top=-1;
// Function to add elements into stack
 void push(int x)
 {
  if(top==MAX_SIZE-1)
  printf("Error:%d cant be inserted into stack as stack is full\n",x);
  else
  {
   top=top+1;
   item[top]=x;
  }
 }
// Function to remove elements into stack with LIFO Technique
 void pop()
 {
  int x;
  if(top==-1)
  printf("error:stack is empty\n");
  else
   { 
    x=item[top];
    top=top-1;
    printf("%d is removed\n",x);
   }
 }
// Function to print all the elements in stack
 void print()
 {
  int i;
  if(top==-1)
  {
  	printf("Stack is empty-nothing to print\n");
  }
  else
  {
  printf("stack:");
  for(i=0;i<=top;i++) 
  printf("%d ",item[i]);
  printf("\n");
  }
 }
 int main()
 { 
  int choice,item;
  // Infinite loop to take multiple choices from user, untill he gives choice as 4
  while(1)
  {  
   printf("enter choice 1.push 2.pop 3.print stack 4.exit\n");
   scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter the item to be pushed\n");
scanf("%d",&item);
push(item);
break;
  
case 2: pop();
break;

case 3: print();
break;

case 4: exit(0);

default:
printf("Invalid choice - Enter correct choice\n");
 }
}
 return 0;
}
