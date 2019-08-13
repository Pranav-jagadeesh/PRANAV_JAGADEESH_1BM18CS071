#include<stdio.h>
#include<conio.h>
struct student_marks
{
int dsm,mm,ds,coa,java,ld,cipe;
};
 struct student
 {
  char name[10];
  char usn[10];
  struct student_marks m;
 };
  int main()
  {
   struct student s;
   clrscr();
   printf("Enter name:");
   scanf("%s",s.name);
   printf("Enter usn:");
   scanf("%s",s.usn);
   printf("Enter DSM marks:");
   scanf("%d",&s.m.dsm);
   printf("Enter COA marks:");
   scanf("%d",&s.m.coa);
   printf("Enter DS marks:");
   scanf("%d",&s.m.ds);
   printf("Enter MM marks:");
   scanf("%d",&s.m.mm);
   printf("Enter JAVA marks:");
   scanf("%d",&s.m.java);
   printf("Enter LD marks:");
   scanf("%d",&s.m.ld);
   printf("Enter CIPE marks:");
   scanf("%d",&s.m.cipe);
   printf("\nstudent name:%s",s.name);
   printf("\nusn:%s",s.usn);
   printf("\nDetails of 3rd Sem Marks:\nDSM:%d\nCOA:%d\nDS:%d\nMM:%d\nJAVA:%d\nLD:%d\nCIPE:%d",
	   s.m.dsm,s.m.coa,s.m.ds,s.m.mm,s.m.java,s.m.ld,s.m.cipe);
   getch();
   return 0;
}

