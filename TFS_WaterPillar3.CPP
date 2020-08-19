#include<iostream.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int cw(int piece)
{
 if(piece==4)
 return(1);
 else
 return(++piece);
}
int acw(int piece)
{
 if(piece==1)
 return(4);
 else
 return(--piece);
}
int main()
{
 int l,m,h,j1,j2;
 l=1;m=4;h=2;j1=4;j2=1;
 char move[3];
 do
 {
 system("cls");
 cout<<"TFS PUZZLE SIMULATOR:\n";
 cout<<"\nCurrent positions are:";
 cout<<"Lower Piece: "<<l<<endl;
 cout<<"Middle Piece: "<<m<<endl; 
 cout<<"Upper Piece: "<<h<<endl;
 cout<<"\nMove list: FA, FC, NA, NC. Type re to reset, ex to exit";
 cout<<"\nInput your choice (not case sensitive): ";
 cin>>move;
 if(strcmpi(move,"NC")==0)
 {
  l=cw(l);
  m=cw(m);
  h=cw(h);
  j1=cw(j1);
  j2=cw(j2);
 }
 if(strcmpi(move,"NA")==0)
 {
  l=acw(l);
  m=acw(m);
  h=acw(h);
  j1=acw(j1);
  j2=acw(j2);
 }
 if(strcmpi(move,"FC")==0)
 {
  if(h!=4&&j1!=4)
  {
   h=cw(h);
   j1=cw(j1);
  }
  if(m!=4&&j2!=4)
  {
   m=cw(m);
   j2=cw(j2);
  }
  if(l!=4)
   l=cw(l);
 }
 if(strcmpi(move,"FA")==0)
 {
  if(h!=1 && j1!=1)
  {
   h=acw(h);
   j1=acw(j1);
  }
  if(m!=1 && j2!=1)
  {
   m=acw(m);
   j2=acw(j2);
  }
  if(l!=1)
   l=acw(l);
 }
 if(strcmpi(move,"re")==0)
 {l=1;m=4;h=2;j1=4;j2=1;}
 }while(strcmpi(move,"ex")!=0);
return 0;
}
