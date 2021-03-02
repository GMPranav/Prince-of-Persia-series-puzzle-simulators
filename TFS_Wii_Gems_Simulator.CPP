#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
using namespace std;
int main()
{
 int c1[10],c2[10];
 int y,g,o,p;
 int mlc=0;
 y=0;
 g=0;
 o=0;
 p=0;
 c1[1]=1;
 c1[2]=2;
 c1[3]=3;
 c1[4]=1;
 c1[5]=5;
 c1[6]=3;
 c1[7]=4;
 c1[8]=4;
 c2[1]=2;
 c2[2]=1;
 c2[3]=0;
 c2[4]=4;
 c2[5]=3;
 c2[6]=1;
 c2[7]=2;
 c2[8]=3;
 int temp;
 char move[3];
 char movelist[200];
 do
 {
 system("cls");
 cout<<"TFS WII GEMS PUZZLE SIMULATOR:\n";
 cout<<"\nMove list: LA, LC, RA, RC. Type re to reset, ex to exit";
 cout<<"\nCurrent position: "<<c1[1]<<" "<<c2[1]<<" "<<c1[5]<<" "<<c2[5];
 cout<<"\nInput your choice (not case sensitive): ";
 cin>>move;
 if(strcmpi(move,"LA")==0)
 {
  temp = c1[8];
  c1[8] = c1[1];
  c1[1] = c1[2];
  c1[2] = c1[3];
  c1[3] = c1[4];
  c1[4] = c1[5];
  c1[5] = c1[6];
  c1[6] = c1[7];
  c1[7] = temp;
  c2[2] = c1[4];
  c2[8] = c1[6];
  movelist[mlc++]='L';
  movelist[mlc++]='A';
  movelist[mlc++]=' ';
 }
 if(strcmpi(move,"RA")==0)
 {
  temp = c2[8];
  c2[8] = c2[1];
  c2[1] = c2[2];
  c2[2] = c2[3];
  c2[3] = c2[4];
  c2[4] = c2[5];
  c2[5] = c2[6];
  c2[6] = c2[7];
  c2[7] = temp;
  c1[4] = c2[2];
  c1[6] = c2[8];
  movelist[mlc++]='R';
  movelist[mlc++]='A';
  movelist[mlc++]=' ';
 }
 if(strcmpi(move,"LC")==0)
 {
  temp = c1[8];
  c1[8] = c1[7];
  c1[7] = c1[6];
  c1[6] = c1[5];
  c1[5] = c1[4];
  c1[4] = c1[3];
  c1[3] = c1[2];
  c1[2] = c1[1];
  c1[1] = temp;
  c2[2] = c1[4];
  c2[8] = c1[6];
  movelist[mlc++]='L';
  movelist[mlc++]='C';
  movelist[mlc++]=' ';
 }
 if(strcmpi(move,"RC")==0)
 {
  temp = c2[8];
  c2[8] = c2[7];
  c2[7] = c2[6];
  c2[6] = c2[5];
  c2[5] = c2[4];
  c2[4] = c2[3];
  c2[3] = c2[2];
  c2[2] = c2[1];
  c2[1] = temp;
  c1[4] = c2[2];
  c1[6] = c2[8];
  movelist[mlc++]='R';
  movelist[mlc++]='C';
  movelist[mlc++]=' ';
 }
 if(strcmpi(move,"re")==0)
 {
  c1[1]=1;
  c1[2]=2;
  c1[3]=3;
  c1[4]=1;
  c1[5]=5;
  c1[6]=3;
  c1[7]=4;
  c1[8]=4;
  c2[1]=2;
  c2[2]=1;
  c2[3]=0;
  c2[4]=4;
  c2[5]=3;
  c2[6]=1;
  c2[7]=2;
  c2[8]=3;
  mlc=0;
  strcpy(movelist,"");
 }
 if((c1[1]==1||c1[1]==5)&&(c1[5]==1||c1[5]==5)&&(c2[1]==1||c2[1]==5)&&(c2[5]==1||c2[5]==5))
  {y=1;cout<<"\nYellow solved!";getch();}
 if((c1[1]==2||c1[1]==5)&&(c1[5]==2||c1[5]==5)&&(c2[1]==2||c2[1]==5)&&(c2[5]==2||c2[5]==5))
  {g=1;cout<<"\nGreen solved!";getch();}
 if((c1[1]==3||c1[1]==5)&&(c1[5]==3||c1[5]==5)&&(c2[1]==3||c2[1]==5)&&(c2[5]==3||c2[5]==5))
  {o=1;cout<<"\nOrange solved!";getch();}
 if((c1[1]==4||c1[1]==5)&&(c1[5]==4||c1[5]==5)&&(c2[1]==4||c2[1]==5)&&(c2[5]==4||c2[5]==5))
  {p=1;cout<<"\nPurple solved!";getch();}
 if(y==1&&g==1&&o==1&&p==1)
 {cout<<"\n\nCongrats! You have solved the puzzle!\nMove list: "<<movelist; getch(); strcpy(move,"ex");}
 }
 while(strcmpi(move,"ex")!=0);
 return 0;
 }