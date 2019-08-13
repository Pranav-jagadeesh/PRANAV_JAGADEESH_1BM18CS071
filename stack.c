#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 3
int item[MAX_SIZE];
int top=-1;
 void push(int x)
 {
  if(isfull()==1)
  printf("error:stack is full");
  else
  {
   printf("enter number");
   scanf("%d",&x);
   top=top+1;
   item[top]=x;
  }
 }
 void pop()
 {
  int x;
  if(isempty()==1)
  printf("error:stack is empty");
  else
  { 
   x=item[top];
   top=top-1;
   printf("%d is removed",x);
  }
 }
int isfull()
 {
  if(top==MAX_SIZE)
  return 1;
  else return 0;
 }
 int isempty()
 {
  if(top==-1)
  return 1;
  else return 0;
 }
 void print()
 {
  int i;
  printf("stack:");
  for(i=0;i<=top;i++) 
  printf("%d ",item[i]);
  printf("\n");
 }
 void main()
 {
  int choice,item;
  printf("enter choice 1.push 2.pop 3.print stack 4.exit");
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

default:
break;
  //push(10);
 // print();
  //push(5);
  //print();
  //push(2);
 // print();
 // pop();
 // print();
  //pop();
 // print();
  //pop();
  //print();
 }
}
