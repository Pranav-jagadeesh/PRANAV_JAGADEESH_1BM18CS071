#include<stdio.h>
#include<process.h>
#define AUDI_SIZE 3
struct student
{
    int roll;
    char name[50];
    char email[21];
}s;

struct student item[AUDI_SIZE];
int top=-1;
 void push()
 {
  if(top==AUDI_SIZE-1)
  printf("Error:cannot enter into auditorium as it is full\n");
  else
  {
  	printf("enter details of student\n");
    printf("Enter roll number: ");
    scanf("%d", &s.roll);
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter email: ");
    scanf("%s", &s.email);
   top=top+1;
   item[top]=s;
  }
 }
 void pop()
 {
  struct student s;
  if(top==-1)
  printf("error:auditorium is empty\n");
  else
  { 
   s=item[top];
   top=top-1;
   printf("%s has been removed from Auditorium\n",s.name);
  }
 }

 void print()
 {
  int i;
  if(top==-1)
  {
  	printf("auditorium is empty\n");
  }
  else
  {
  
  printf("students in auditorium are:");
  for(i=top;i>=0;i--) 
  {
    printf("\nRoll number: %d\n",item[i].roll);
    printf("Name: ");
    puts(item[i].name);
    printf("\nEmail: %s\n", item[i].email);
    printf("\n");
  }
 }
}
 // main method
 int main()
 {
 	int i;
  int choice,item;
  struct student s;
  while(1)
  {  
   printf("enter choice \n1.To Enter New Student into Audi \n2.To remove Student from Audi  \n3. Print Student in LIFO order \n4.Exit from Program \n");
   scanf("%d",&choice);
switch(choice)
{
case 1:
	push();
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
