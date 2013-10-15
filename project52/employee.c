/*  employee details   */           
#include<stdio.h>
#include<conio.h>
struct emp
{
 int empno;
 char ename[10];
 int esal;
} ;
main()
{
    struct emp e[10];
    int n,i;
    //clrscr();
    printf("\n how many records you want to insert\n");
    scanf("%d",&n);
    printf("use space or enter to insert details\n");
    printf("\n enter empno ename esal ");
    for(i=0;i<n;i++)
    scanf("%d%s%d",&e[i].empno,e[i].ename,&e[i].esal);
     printf("\n entered records are\n");
     printf("\nempno\tempname\tempsal\n");
    for(i=0;i<n;i++)
    printf("\n %d\t %s\t %d",e[i].empno,e[i].ename,e[i].esal);
    getch();
}
