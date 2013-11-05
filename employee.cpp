#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 50

int day[]={31,28,31,30,31,30,31,31,30,31,30,31},dd=0,mm=0,yy=0,check[MAX],total;
char *month[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"},today_date[]=__DATE__,mn[4];

struct emp
{
       char ename[100];
       unsigned int eno;
       unsigned long int esal;
       char edes[100];
       char edep[100];
       unsigned int d,m,y;
}e[MAX];

int find_age(char *name,int d,int m,int y,char s)
{
     int d1=0,m1=0,y1=0;
     y1=(yy>y?(mm>m?yy-y:(mm==m?(dd>=d?yy-y:yy-y-1):yy-y-1)):0);
     if(s=='y' || s=='Y')
     return y1; 
     m1=(yy>y?(mm>m?(dd>=d?mm-m:mm-m-1):(mm==m?(dd>=d?0:11):(dd>=d?mm+12-m:mm+11-m))):(mm>m?(dd>=d?mm-m:mm-m-1):0));
     d1=(yy>y?(mm>m?(dd>=d?dd-d:dd-d+day[m-1]):(mm==m?(dd>=d?dd-d:day[m-2]-d+dd):(dd>=d?dd-d:dd-d+day[m-1]))):(mm>m?(dd>=d?dd-d:dd-d+day[m-1]):dd-d));
     printf("\nAge of %s : %d Year %d Month %d days\n\n",name,y1,m1,d1);
     return 0;
}

unsigned int right_entry()
{
      unsigned long int p=0,a,i=0;
      while((a=getch())!=13 || p==0)
      {
          if(a>47 && a<58)
          {
               if(i<9)
               {
                   putch(a);
                   p=p*10+a-48;
                   i++;
               }
          }
          if(a=='\b' && i>0)
          {
              printf("\b \b");
              p/=10;
              i--;
          }
     }     
     return p;
}

void bubble_sort(struct emp array[], int size)
{
	struct emp temp;
	int t;
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
		{
			if((strcmp(array[i].ename,array[j].ename) < 0)||(strcmp(array[i].ename, array[j].ename)==0 && array[i].esal>array[j].esal))
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				t=check[i];
				check[i]=check[j];
				check[j]=t;
			}
        }
}

void fullage()
{
     int a,j;
     printf("\nEnter Employee No of Employee to find Full Age : ");
     a=right_entry()%10000;
     for(j=0;j<=total;j++)
     if(a==e[j].eno)
     {
         find_age(e[j].ename,e[j].d,e[j].m,e[j].y,'n');
         break;
     }
     if(j>total)
     printf("\n\nSorry Employee No %d not Found in DataBase.",a);
}

void deleted()
{
     int i,cn;
     printf("\nEnter Employee Number to whom you want to delete : ");
     cn=right_entry()%10000;
     for(i=0;i<=total;i++)
          if(cn==e[i].eno)
          {
              printf("\nDetail of Employee Number %d is being deleted...\n",cn);
              printf("\nDetail of Employee Number %d is Successfully deleted...\n",cn,getch());
              break;
          }
     if(i>total)
             printf("\nEmployee number not Found");
     if(total>-1 && i<=total)
     {
         for(int j=i;j<total;j++)
             e[j]=e[j+1];
         total--;
     }
}


void print_all(int k)
{
      bubble_sort(e,k);
      printf("\n\n\n\t\t\t\tHARISH SHARMA\n\t\t\t      ROLL NO: - 205112052\n--------------------------------------------------------------------------------\nSN. NAME_of_EMP    EMP_NO  SALARY      DESIGN.   DEPART     Date Of Birth  AGE\n--------------------------------------------------------------------------------\n");
      if(k!=0)
      for(int j=0;j<k;j++)
          printf("%2d. %-15s %-5u  %-11u %-10s %-10s %3u-%s-%-4u  %3d\n",j+1,e[j].ename,e[j].eno,e[j].esal,e[j].edes,e[j].edep,e[j].d,month[e[j].m-1],e[j].y,find_age(e[j].ename,e[j].d,e[j].m,e[j].y,'y'));
      else
      printf("\t\t\tEmployee Detail is not here\n");
      printf("--------------------------------------------------------------------------------\n");
}


struct emp insert(int i)
{                
      struct emp e;
      printf("\n\nEnter Detail of %d employee :\nEnter NAME :  ",i+1);
      gets(e.ename);
      AGAIN_ENO:
      printf("Enter EMPLOYEE NO (4-digit) :  ");
      e.eno=(right_entry())%10000;
      if(e.eno==0)e.eno=10000;
      check[i]=e.eno;
      for(int j=0;j<i;j++)
          if(e.eno==check[j])
          {
              printf("\nEmployee no should be different...\n");
              goto AGAIN_ENO;
          }
      printf("\nEnter SALARY :  ");
      e.esal=right_entry();
      printf("\nEnter DESIGNATION :  ");
      gets(e.edes);
      printf("Enter DEPARTMENT :  ");
      gets(e.edep);
      AGAIN_DATE:
      printf("Enter DOB...\nDATE : ");
      e.d=right_entry();
      printf("\nMONTH : ");
      e.m=right_entry();
      printf("\nYEAR : ");
      e.y=right_entry();
      if((e.d>0 && e.m>0 && e.y>=1930 && e.m<13 && e.y<=yy-20 && (e.d<=day[e.m-1] || (e.m==2 && e.d<=29 && e.y%4==0 && e.y%400!=0))) && (e.y<yy-20 || (e.y==yy-20 && (e.m<mm || (e.m==mm && e.d<dd)))))
      {
            printf("\n\tRecord Saved\n");
            return e;
      }
      else
      {printf("\nWrong date Enter again\nDate should be between 1/1/1930 and %d/%d/%d\n",dd,mm,yy-20);
      goto AGAIN_DATE;
      }
}

main()
{
      int i,j;
    // printf("%s\n\n",today_date);
      //printf("%d\n",strlen(today_date));
      for(i=0;i<strlen(today_date);i++)
      {
              if(i<3)
                  mn[i]=today_date[i];
              else if(i==3)
                  mn[i]='\0';
              else if(i>3 && i<6 && today_date[i]!=' ')
                  dd=dd*10+today_date[i]-48;
              else if(i>6)
                  yy=yy*10+today_date[i]-48;
      }
      for(i=0;i<12;i++)
      if(mn==month[i])
      break;
      mm=i-1;
      for(i=0;i<MAX;i++)
      check[i]=0;
      printf("Program that maintains following details of an Employees : \nName, Employee No, Designation, Department, DOB, and Salary.\nAlso sort them \n  in ASCENDING order of NAME as a PRIMARY KEY and \n  in DESCENDING order of SALARY as a SECONDARY KEY.\nand also Find the age of Employee using DOB...\n\nPress Any Key...\n");
      getch();
      system("cls");
      char c;
      total=-1;
      do
      {
          c=' ';
          printf("\n----------------------------------------------\n*******************  MENU  *******************\n----------------------------------------------\n -> (N/n) Enter New Employee Detail\n -> (D/d) Delete Already Exist Employee Detail\n -> (S/s) Show Details of All Employee \n -> (F/f) Find Full age of Employee\n -> (X/x) Exit\n----------------------------------------------\n");
          do
          {
             printf("\n  Enter Your Choice : ");
             c=tolower(getche());
          }while((strchr("xsfdn",c))==0);
          printf("\n  Your Choice is : %c\n",c);
          switch(c)
          {
                   case 'n':                  
                        total++;
                        e[total]=insert(total);
                        break;
                   case 'd':
                        deleted();
                        break;
                   case 's':
                        print_all(total+1);
                        break;
                   case 'f':
                        fullage();
          }
      getch();
      }while(c!='x');
      printf("\n\n\t\t\t\t-:Thank You:-\n");
      getch();
}
