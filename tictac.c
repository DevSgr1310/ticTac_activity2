#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

char ar[3][3];

int checkpos(int x,int y)      //Function To Check The Valid Position
{
  if((x>=0 && x<=2) && (y>=0 && y<=2))  //To Check No. Is Out Of Array
  {
   if(ar[x][y]!='-')   //To Check The Position Is Already Fill
    {
     cout<<"Invalid Posiotion...\n";
     return 0;
    }
   return 1;
  }
  cout<<"Invalid Position...\n";
  return 0;
}



int check(char c)   //To Check Player Wins Or Not
{
  int i,j,f=0;

  for(i=0;i<3;i++)       //All Row_Wise Condition
   if(ar[i][0]==c && ar[i][1]==c && ar[i][2]==c)
    return 1;

  for(i=0;i<3;i++)   //All Column_wise Condition
   if(ar[0][i]==c && ar[1][i]==c && ar[2][i]==c)
    return 1;

  for(i=0;i<3;i++)    //1st Diagonal
   if(ar[i][i]==c)
    f++;

  if(f==3)
   return 1;


  f=0;
  for(i=0,j=2;i<3;i++,j--)    //2nd Diagonal
   if(ar[i][j]==c)
    f++;

  if(f==3)
   return 1;


  return 0;
}


void show()     //Print The Matrix
{
 int i;
 cout<<"MATRIX:-\n";

 cout<<"   ";
 for(i=1;i<=3;i++)
 cout<<i<<" ";

 cout<<"\n";

 for(i=0;i<3;i++)
  {
   cout<<i+1<<"  ";
   for(int j=0;j<3;j++)
    cout<<ar[i][j]<<" ";

    cout<<"\n";
  }
}


void main()
{
  int i,j,x,y;
  char c;
  char p[2][30];

  clrscr();

  for(i=0;i<3;i++)
   for(j=0;j<3;j++)
   ar[i][j]='-';

   cout<<"START THE GAME:-\n";
   cout<<"Player 1 Symobol: X\n";
   cout<<"Player 2 Symobol: 0\n";
   cout<<"\nEnter The 1st Player Name: ";
   gets(p[0]);
   cout<<"Enter The 2nd Player Name: ";
   gets(p[1]);

   clrscr();
   show();

   i=0;
   while(i<9)    //Total Iteration Will Be 9
   {
     cout<<"\n\n"<<p[i%2]<<" Turn:-\n";
     cout<<"Enter The Position(x,y):\n";
     cin>>x>>y;
     x--;      //To Make Use In Array As Array Start's From 0
     y--;

     if(checkpos(x,y))   //Check Valid Position
     {
       if(i%2==0)
	ar[x][y]='X';
       else
	ar[x][y]='0';
     }
     else
     continue;    //To Re_enter The Position

     show();

     if(i%2==0)     //To Find Which Player Turn
     c='X';
     else
     c='0';

     if(check(c))
      {
       cout<<"\n\n"<<p[i%2]<<" WINS.......";
       getch();
       return;
      }

     i++;
   }

   cout<<"GAME TIE.....";
   getch();
}