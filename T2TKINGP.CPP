#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
char moves[100];
int k=0;
void rotpos(int p)
{
 if(p==1)
  cout<<"Front";
 if(p==2)
  cout<<"Its left";
 if(p==3)
  cout<<"Back";
 if(p==4)
  cout<<"Its right";
}
int fwd(int p)
{
 if(moves[k-3]!='B')
 {
  moves[k++]='F';
  moves[k++]='W';
  moves[k++]=' ';
 }
 else
 {
  moves[k--]='/0';
  moves[k--]='/0';
  moves[k--]='/0';
 }
 return(++p);
}
int bwd(int p)
{
 if(moves[k-3]!='F')
 {
  moves[k++]='B';
  moves[k++]='W';
  moves[k++]=' ';
 }
 else
 {
  moves[k--]='/0';
  moves[k--]='/0';
  moves[k--]='/0';
 }
 return(--p);
}
int cwise(int p)
{
 if(moves[k-3]!='A')
 {
  moves[k++]='C';
  moves[k++]='W';
  moves[k++]=' ';
 }
 else
 {
  moves[k--]='/0';
  moves[k--]='/0';
  moves[k--]='/0';
 }
 if(p==1)
  return(4);
 else
  return(--p);
}
int awise(int p)
{
 if(moves[k-3]!='C')
 {
  moves[k++]='A';
  moves[k++]='W';
  moves[k++]=' ';
 }
 else
 {
  moves[k--]='/0';
  moves[k--]='/0';
  moves[k--]='/0';
 }
 if(p==4)
  return(1);
 else
  return(++p);
}
int main()
{
int tp,rp,k;
char ch[3];
tp=1;rp=1,k=0;
do
{
 system("cls");
 cout<<"T2T King Statue Puzzle Simulator:\n\n";
 cout<<"Tranlational position: "<<tp<<endl;
 cout<<"Rotational position: ";
 rotpos(rp);
 cout<<endl<<endl;
 cout<<"Legend (not case sensitive):\nCW = Clockwise\nAW = Anticlockwise\nFW = Forward\nBW = Backward\nEX = Exit\n\n";
 cout<<"Input your choice: ";
 cin>>ch;
 if(strcmpi(ch,"fw")==0)
 {
  if(tp==1)
  {
   tp=fwd(tp);
   goto over;
  }
  if(tp==2)
  {
   if(rp==1||rp==4)
    goto over;
   else
   {
    tp=fwd(tp);
    goto over;
   }
  }
  if(tp==3)
  {
   tp=fwd(tp);
   goto over;
  }
  if(tp==4)
  {
   if(rp==4)
   {
    tp=fwd(tp);
    goto over;
   }
   else
    goto over;
  }
  if(tp==5)
  {
   if(rp==1)
    goto win;
   else
   {
    tp=fwd(tp);
    goto over;
   }
  }
 }
 if(strcmpi(ch,"bw")==0)
 {
  if(tp==2)
  {
   if(rp==1||rp==2)
   {
    tp=bwd(tp);
    goto over;
   }
   else
    goto over;
  }
  if(tp==3)
  {
   if(rp==3)
   {
    tp=bwd(tp);
    goto over;
   }
   else
    goto over;
  }
  if(tp==4)
  {
   if(rp!=4)
   {
    tp=bwd(tp);
    goto over;
   }
   else
    goto over;
  }
  if(tp==5)
  {
   if(rp==4)
   {
    tp=bwd(tp);
    goto over;
   }
   else
    goto over;
  }
  if(tp==6)
  {
   tp=bwd(tp);
   goto over;
  }
 }
 if(strcmpi(ch,"cw")==0)
 {
  if(tp==1)
  {
   if(rp==2)
   {
    rp=cwise(rp);
    goto over;
   }
   else
    goto over;
  }
  if(tp==2)
  {
   if(rp!=2)
   {
    rp=cwise(rp);
    goto over;
   }
   else
    goto over;
  }
  if(tp==3)
  {
   if(rp==2)
   {
    rp=cwise(rp);
    goto over;
   }
   else
    goto over;
  }
  if(tp==4)
  {
   if(rp==3||rp==1)
   {
    rp=cwise(rp);
    goto over;
   }
   else
    goto over;
  }
  if(tp==5)
  {
   if(rp==1||rp==4)
   {
    rp=cwise(rp);
    goto over;
   }
   else
    goto over;
  }
  if(tp==6)
  {
   if(rp==2||rp==4)
   {
    rp=cwise(rp);
    goto over;
   }
   else
    goto over;
  }
 }
 if(strcmpi(ch,"aw")==0)
 {
  if(tp==1)
  {
   if(rp==1)
   {
    rp=awise(rp);
    goto over;
   }
   else
    goto over;
  }
  if(tp==2)
  {
   if(rp!=1)
   {
    rp=awise(rp);
    goto over;
   }
   else
    goto over;
  }
  if(tp==3)
  {
   if(rp==1)
   {
    rp=awise(rp);
    goto over;
   }
   else
    goto over;
  }
  if(tp==4)
  {
   if(rp==2||rp==4)
   {
    rp=awise(rp);
    goto over;
   }
   else
    goto over;
  }
  if(tp==5)
  {
   if(rp==3||rp==4)
   {
    rp=awise(rp);
    goto over;
   }
   else
    goto over;
  }
  if(tp==6)
  {
   if(rp==1||rp==3)
   {
    rp=awise(rp);
    goto over;
   }
   else
    goto over;
  }
 }
 over:;
}while(strcmpi(ch,"ex")!=0);
 goto exit;
 win:
 cout<<"\n\nYou beat the puzzle!";
 cout<<"\nNice moves! "<<moves<<"FW";
 getch();
 exit:
 return(0);
}
