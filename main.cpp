#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
int a[25][25],i,j,k; char m1;
int e_count=500;int sprint_count=4;
int ok=1; int live_count_e=0;
int win=1;
int start_pi=0;
int start_pj=0;
int clear_e_c=400;
int b_count_p=4;
int b_count_2=10;
int starter=1;
int d_count=300;
int timer=1;
int boss_count=0;
int m_e_count=200;
int slam_ok=10;
int l_count=350;
int l_s_count=300;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
typedef struct // entitatea propriuzisa, cu viata, pozitie, contor de miscare si tras
{int id; // 1 player, 2 enemy ,  3 bullet, 4 enviorment, 5 player 2, 6 debris, 7 boss

 int hp; //health points
 int pozi; // horizontal pozition
 int pozj;// vertical position
 int dir; //direction (heading of a bullit) && feature for special a special entity.
 } entity;
 entity e[1000];

void instruction()
{system("cls");
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 4);
 std::cout<<"\n\n   MARKADE\n=============\n";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
 std::cout<<"\nWelcome, this is the informational panel;";
std::cout<<"\nThe purpose of the game is simple; eliminate all enemies;";
std::cout<<"\n\nLegend:\n\n";
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 10);std::cout<<"X";
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);std::cout<<" - player(1)\n";
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 9);std::cout<<"O";
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);std::cout<<" - enemy\n";
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 4);std::cout<<"< ^ > v";
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);std::cout<<" - bullet\n";
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 5);std::cout<<"| _ | _";
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);std::cout<<" - shield\n";
   std::cout<<"\n\n";
std::cout<<"TO MOVE, USE: w a s d";
std::cout<<"\nTO SHOOT, USE: 1 2 3 4";
std::cout<<"\nTO PLACE A SHIELD, PRESS B AND SELECT ITS COORDINATES WITH: 1 2 3 4";
std::cout<<"\n\n      ";
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 4);
std::cout<<"^          2";
std::cout<<"\n\n   <";
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 10);
std::cout<<"  X  ";
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 4);
std::cout<<">    1  ";SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 10);
std::cout<<"X  ";SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 4);
std::cout<<"3";
std::cout<<"\n\n      V          4";
getch();
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
gotoxy(100,100);
}

 void reset_joc()  // initiaza harta cu 0-uri
{for(i=1;i<=20;i++)
  {for(j=1;j<=20;j++)
    {a[i][j]=0;}}
  for(i=1;i<=20;i++)
    a[i][0]=4;
  for(j=1;j<=20;j++)
    a[0][j]=4;
  for(i=1;i<=1000;i++)
    {e[i].id=0;
    e[i].pozi=0;
   e[i].pozj=0;
   e[i].dir=0;}
   e_count=50;
   m_e_count=200;
   sprint_count=4;
  }


void afisare_joc() // afiseaza "harta"
{char w;w=254;std::cout<<"------------------------------------------\n";
for(i=1;i<=20;i++)
{std::cout<<"|";
  {for(j=1;j<=20;j++)
    {if(a[i][j]==0)
        std::cout<<" ";
        std::cout<<" ";
     if(a[i][j]==2)
     {SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 9);
      std::cout<<"O";
     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
     if(a[i][j]==1)
      {SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 10);
       std::cout<<"X";
       SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
    if(a[i][j]==3)
       {for(k=1;k<=1000;k++)
          if(e[k].pozi==i&&e[k].pozj==j)
          switch(e[k].dir){
    case 1:
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 4);
        std::cout<<"<";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
    break;
    case 2 :
         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 4);
        std::cout<<"^";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
    break;
    case 3 :
         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 4);
        std::cout<<">";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
    break;
    case 4 :
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 4);
        std::cout<<"v";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
        }if(a[i][j]==4)
       {for(k=1;k<=1000;k++)
          if(e[k].pozi==i&&e[k].pozj==j)
          switch(e[k].dir){
    case 1:
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 5);
        std::cout<<"|";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
    break;
    case 2 :
         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 5);
        std::cout<<"_";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
    break;
    case 3 :
         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 5);
        std::cout<<"|";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
    break;
    case 4 :
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 5);
        std::cout<<"_";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
        }
    if(a[i][j]==5)
     {SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 14);
       std::cout<<"X";
       SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
    if(a[i][j]==6)
     std::cout<<w;
    if(a[i][j]==7)
     {SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 9);
     std::cout<<w;
     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
     if(a[i][j]==8)
        {if(live_count_e%2==1)
            std::cout<<" ";
        if(live_count_e%2==0)
        {SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 5);
     w=248;
     std::cout<<w;
     w=254;
     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
     }
     if(a[i][j]==9)
       {for(k=1;k<=1000;k++)
          if(e[k].pozi==i&&e[k].pozj==j)
          switch(e[k].dir){
    case 1:
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 3);
        std::cout<<"<";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
    break;
    case 2 :
         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 3);
        std::cout<<"^";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
    break;
    case 3 :
         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 3);
        std::cout<<">";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
    break;
    case 4 :
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),3);
        std::cout<<"v";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}}}
    std::cout<<"|\n";}
    }std::cout<<"------------------------------------------\n";
  }

void debris(int &d_count)
{for(i=1;i<=20;i++)
 for(j=1;j<=20;j++)
    if(a[i][j]==0)
    {
      if((rand()%40)%25==0)
      {a[i][j]=6;
       e[d_count].hp=1;
       e[d_count].pozi=i;
       e[d_count].pozj=j;
       e[d_count].id=6;
       d_count++;

      }
    }

}

void stats(int k)
{gotoxy(45,2);

 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 5);
 std::cout<<"SCUTURI:";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
    for(i=1;i<=b_count_p;i++)
    {SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 5);
       std::cout<<"|";
       SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}

   gotoxy(45,3);
  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 4);
 std::cout<<"VIATA:";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
  for(i=1;i<=e[k].hp;i++)
  {SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 4);
   std::cout<<"|";}
   std::cout<<"      ";
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
  gotoxy(42,4);
    std::cout<<"   SARITURA: ";
    if(sprint_count>=100)
        std::cout<<"ACTIVA  ";
    if(sprint_count<100)
        std::cout<<"INACTIVA";
gotoxy(42,5);
std::cout<<"       ";
  gotoxy(45,20);
    if(e[2].id==7)
    {SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout<<"BOSS HP:";
    std::cout<<e[2].hp;
    std::cout<<"      ";
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
}

void init_player(int &a,int &b) // initiaza jucatorul
{e[1].hp=1;
 srand(time());
 while(a<1||a>20)
    a=rand()%18;
 while(b<1||b>20)
    b=rand()%18;
 e[1].pozi=a;
 e[1].pozj=b;
 e[1].id=1;

}

void init_p2(int k)
{int c=start_pi;int d=start_pj;
 e[k].hp=1;
 while(start_pi==c)
    c=rand()%18+1;
 while(start_pj==d)
 d=rand()%18+1;
 e[k].pozi=c;
 e[k].pozj=d;
 e[k].id=5;}

void scan_pos() // scaneaza pozitia fiecarei entitati din joc
{int k;
 for(k=1;k<=1000;k++)
   {for(i=1;i<=20;i++)
    {
     for(j=1;j<=20;j++)
      {if(i==e[k].pozi&&j==e[k].pozj&&e[k].id==1)
         a[i][j]=1;
        if(i==e[k].pozi&&j==e[k].pozj&&e[k].id==2)
         a[i][j]=2;
         if(i==e[k].pozi&&j==e[k].pozj&&e[k].id==3)
         a[i][j]=3;
         if(i==e[k].pozi&&j==e[k].pozj&&e[k].id==4)
         a[i][j]=4;
         if(i==e[k].pozi&&j==e[k].pozj&&e[k].id==5)
         a[i][j]=5;
         if(i==e[k].pozi&&j==e[k].pozj&&e[k].id==6)
         a[i][j]=6;
          if(i==e[k].pozi&&j==e[k].pozj&&e[k].id==7)
         a[i][j]=7;
          if(i==e[k].pozi&&j==e[k].pozj&&e[k].id==8)
         a[i][j]=8;
          if(i==e[k].pozi&&j==e[k].pozj&&e[k].id==9)
         a[i][j]=9;
}}}
}


void init_ai(int k)
{int c=start_pi;int d=start_pj;
 e[k].hp=10;
 while(start_pi==c)
    c=rand()%18+1;
 while(start_pj==d)
 d=rand()%18+1;
 e[k].pozi=c;
 e[k].pozj=d;
 e[k].id=7;
}

void init_mob(int k,int c,int d)
{if(a[c][d]>=0&&a[c][d]==0)
 {e[k].hp=1;
  while(start_pi==c)
    c=rand()%18+1;
 while(start_pj==d)
 d=rand()%18+1;
 e[k].pozi=c;
 e[k].pozj=d;
 e[k].id=2;}
}

void move_e(char m, int i)
{
a[e[i].pozi][e[i].pozj]=0;

  if(m=='a'&&e[i].pozj-1>0)
   {if(a[e[i].pozi][e[i].pozj-1]==0)
     {e[i].pozj-=1;a[e[i].pozi][e[i].pozj]=e[i].id;}
   else
   if(a[e[i].pozi][e[i].pozj-1]==3)
   {
    e[i].hp--;
    e[i].pozj-=1;
    a[e[i].pozi][e[i].pozj]=e[i].id;}}
     e[i].pozj++;a[e[i].pozi][e[i].pozj]=e[i].id;}}
  if(m=='s'&&e[i].pozi+1<=20)
    {if(a[e[i].pozi+1][e[i].pozj]==0)
        {
         e[i].pozi++;a[e[i].pozi][e[i].pozj]=e[i].id;}
    else
        if(a[e[i].pozi+1][e[i].pozj]==3)
        {
         e[i].hp--;
        e[i].pozi++;a[e[i].pozi][e[i].pozj]=e[i].id;}} // misca playerul. are nevoie de un if pentru situatia in care acesta este blocat

}

void sprint_e(char m, int i)
{
a[e[i].pozi][e[i].pozj]=0;

  if(m=='a')
   {if(a[e[i].pozi][e[i].pozj-2]==0)
     {e[i].pozj-=2;a[e[i].pozi][e[i].pozj]=e[i].id;}
   else
   if(a[e[i].pozi][e[i].pozj-2]==3)
   {
    e[i].hp--;
    e[i].pozj-=2;
    a[e[i].pozi][e[i].pozj]=e[i].id;}}

 if(m=='w')
   {if(a[e[i].pozi-2][e[i].pozj]==0)
        {
        e[i].pozi-=2;a[e[i].pozi][e[i].pozj]=e[i].id;}
    else
        if(a[e[i].pozi-2][e[i].pozj]==3)
    {
     e[i].hp--;
     e[i].pozi-=2;a[e[i].pozi][e[i].pozj]=e[i].id;}}
  if(m=='d')
    {if(a[e[i].pozi][e[i].pozj+2]==0)
       {
        e[i].pozj++;e[i].pozj++;a[e[i].pozi][e[i].pozj]=e[i].id;}
    else
       if(a[e[i].pozi][e[i].pozj+2]==3)
    {
     e[i].hp--;
     e[i].pozj++;e[i].pozj++;a[e[i].pozi][e[i].pozj]=e[i].id;}}
  if(m=='s')
    {if(a[e[i].pozi+2][e[i].pozj]==0)
        {
         e[i].pozi++;e[i].pozi++;a[e[i].pozi][e[i].pozj]=e[i].id;}
    else
        if(a[e[i].pozi+2][e[i].pozj]==3)
        {
         e[i].hp--;
        e[i].pozi++;e[i].pozi++;a[e[i].pozi][e[i].pozj]=e[i].id;}} // misca playerul. are nevoie de un if pentru situatia in care acesta este blocat

}

void shoot_p(char m,int n,int &e_count, int k) // n = numarul entitatii care trage
{ if(m=='1'&&a[e[n].pozi][e[n].pozj-1]==0||m=='j'&&a[e[n].pozi][e[n].pozj-1]==0) // stanga
        {e[e_count].hp=10000;
         e[e_count].id=k;
         e[e_count].dir=1;
         e[e_count].pozi=e[n].pozi;
         e[e_count].pozj=e[n].pozj-1;

         }



    if(m=='2'&&a[e[n].pozi-1][e[n].pozj]==0||m=='i'&&a[e[n].pozi-1][e[n].pozj]==0) // sus
        {e[e_count].hp=10000;
         e[e_count].id=k;
         e[e_count].dir=2;
         e[e_count].pozi=e[n].pozi-1;
         e[e_count].pozj=e[n].pozj;

         }

     if(m=='3'&&a[e[n].pozi][e[n].pozj+1]==0||m=='l'&&a[e[n].pozi][e[n].pozj+1]==0) //dreapta
        {e[e_count].hp=10000;
         e[e_count].id=k;
         e[e_count].dir=3;
         e[e_count].pozi=e[n].pozi;
         e[e_count].pozj=e[n].pozj+1;

         }

     if(m=='4'&&a[e[n].pozi+1][e[n].pozj]==0||m=='k'&&a[e[n].pozi+1][e[n].pozj]==0) //jos
        {e[e_count].hp=10000;
         e[e_count].id=k;
         e[e_count].dir=4;
         e[e_count].pozi=e[n].pozi+1;
         e[e_count].pozj=e[n].pozj;

        }
    }

void laser()
{for(i=300;i<=350;i++)
    if(e[i].id==8)
    {e[i].dir++;
    if(e[i].dir>=15)
    {int di,dj; //algoritm taken from shooting subprogram
di=e[i].pozi-e[1].pozi;
dj=e[i].pozj-e[1].pozj;
if(di<0)
di=-di;
if(dj<0)
dj=-dj;
if(di<dj)
{if(e[i].pozi<e[1].pozi)
    {
     shoot_p('4',i,l_count,9);} // spawns lasor entity
   if(e[i].pozi>e[1].pozi)
     { shoot_p('2',i,l_count,9);}}
if(dj<di)
 {if(e[i].pozj<e[1].pozj)
    { shoot_p('3',i,l_count,9);}
   if(e[i].pozj>e[1].pozj)
     { shoot_p('1',i,l_count,9);}}
 if(dj==di)
 {int random_move;
  srand(time(NULL));
  random_move=rand()%10;
  if(random_move%4==1)
    { shoot_p('2',i,l_count,9);}
  if(random_move%4==2)
    { shoot_p('1',i,l_count,9);}
  if(random_move%4==3)
    { shoot_p('4',i,l_count,9);}
  if(random_move%4==0)
    { shoot_p('3',i,l_count,9);}

 }
  e[i].hp=0;
  e[i].dir=0;
  e[i].pozi=0;
  e[i].pozj=0;
  e[i].id=0;
    }}

  for(i=350;i<=400;i++)
    {if(a[e[k].pozi][e[k].pozj]==a[i][j]&&e[i].id!=9) // deletes representations of the lasor entity
    a[i][j]=0;
    if(e[i].id==9)
     {

if(e[i].dir==1)
{for(k=1;k<=1000;k++)
for(j=e[i].pozj-1;j>=e[i].pozj-4;j--)
if (e[k].pozi==e[i].pozi && e[k].pozj==j)
e[k].hp=e[k].dir=e[k].pozi=e[k].pozj=e[k].id=0; //kills any entity hit by the laser
e[i].pozj-=4; // moves entity to the 4th location away from its original position
for(k=e[i].pozj;k>=e[i].pozj-4;k--)  // replicates entity 4 tiles
 a[e[i].pozi][k]=9;}

if(e[i].dir==2)
{for(k=1;k<=1000;k++)
for(j=e[i].pozi-1;j>=e[i].pozi-4;j--)
if(e[k].pozi==i&&e[k].pozj==e[i].pozj)
e[k].hp=e[k].dir=e[k].pozi=e[k].pozj=e[k].id=0;
e[i].pozi-=4;
for(k=e[i].pozi;k>=e[i].pozi-4;k--)
 a[k][e[i].pozj]=9;}

if(e[i].dir==3)
{for(k=1;k<=1000;k++)
for(j=e[i].pozj+1;j<=e[i].pozj+4;j++)
if(e[k].pozi==e[i].pozi&&e[k].pozj==j)
e[k].hp=e[k].dir=e[k].pozi=e[k].pozj=e[k].id=0;
e[i].pozj+=4;
for(k=e[i].pozj;k<=e[i].pozj+4;k++)
 a[e[i].pozi][k]=9;}

if(e[i].dir==4)
{for(k=1;k<=1000;k++)
for(j=e[i].pozi+1;j<=e[i].pozi+4;j++)
if(e[k].pozi==i&&e[k].pozj==e[i].pozj)
e[k].hp=e[k].dir=e[k].pozi=e[k].pozj=e[k].id=0;
e[i].pozi+=4;
for(k=e[i].pozi;k<=4+e[i].pozi;k++)
 a[k][e[i].pozj]=9;}
      }

}

}

void bullet()
{for(i=1;i<=1000;i++)
  if(e[i].id==3)
{switch (e[i].dir){
  case 1:
  if(e[i].pozj==1)
  {a[e[i].pozi][e[i].pozj]=0;
   e[i].id=0;
   e[i].pozi=0;
   e[i].pozj=0;
   e[i].dir=0;
  }else
 {a[e[i].pozi][e[i].pozj]=0;
  e[i].pozj--;
  }
  break;
  case 2:
  if(e[i].pozi==1)
  {a[e[i].pozi][e[i].pozj]=0;
   e[i].id=0;
   e[i].pozi=0;
   e[i].pozj=0;
   e[i].dir=0;
  }else
  {a[e[i].pozi][e[i].pozj]=0;
  e[i].pozi--;}
  break;
  case 3:
  if(e[i].pozj==20)
  {a[e[i].pozi][e[i].pozj]=0;
   e[i].id=0;
   e[i].pozi=0;
   e[i].pozj=0;
   e[i].dir=0;
  }else
 {a[e[i].pozi][e[i].pozj]=0;
  e[i].pozj++;}
  break;

  case 4:
  if(e[i].pozi==20)
  {a[e[i].pozi][e[i].pozj]=0;
   e[i].id=0;
   e[i].pozi=0;
   e[i].pozj=0;
   e[i].dir=0;
  }else
 {a[e[i].pozi][e[i].pozj]=0;
  e[i].pozi++;}
  break;
  }}}


void p_death(int &k)
{
 if(e[1].hp==0)
 {std::cout<<"YOU LOST, KIND SIR/LADY\n";
 Sleep(5000);getch();
 k=0;}
}

void e_death(int &k)
{
 if(e[2].hp==0)
 {std::cout<<"YOU WON, KIND SIR/LADY\n";
 Sleep(5000);getch();
 k=0;}
}

void death()
{p_death(win);
  for(i=2;i<=1000;i++)
  if(e[i].hp==0&&e[i].id!=3)
  {a[e[i].pozi][e[i].pozj]=0;
   e[i].id=0;
   e[i].pozi=0;
   e[i].pozj=0;
   e[i].dir=0;}
 e_death(win);
}

void dmg()
{for(i=1;i<=1000;i++)
  for(j=1;j<=1000;j++)
   if(e[i].pozi==e[j].pozi&&e[i].pozj==e[j].pozj&&i!=j)
    {if(e[i].id==3&&e[j].id==3)
       {e[j].hp--;
       e[i].id=0;
       e[i].pozi=0;
       e[i].pozj=0;
       e[i].dir=0;
       a[e[i].pozi][e[j].pozj]=0;
       e[i].hp--;
       e[j].id=0;
       e[j].pozi=0;
       e[j].pozj=0;
       e[j].dir=0;
       a[e[i].pozi][e[j].pozj]=0;}
       if(e[i].id==3)
      {e[j].hp--;
       e[i].id=0;
       e[i].pozi=0;
       e[i].pozj=0;
       e[i].dir=0;
       a[e[i].pozi][e[j].pozj]=0;
       }
      if(e[j].id==3)
      {e[i].hp--;
       e[j].id=0;
       e[j].pozi=0;
       e[j].pozj=0;
       e[j].dir=0;
       a[e[i].pozi][e[j].pozj]=0;
}}}

void boss_eat()
{for(i=1;i<=1000;i++)
{if(e[i].id==7)
  {if(a[e[i].pozi-1][e[i].pozj]==2)
     for(j=1;j<=1000;j++)
        if(e[j].pozi==e[i].pozi-1&&e[j].pozj==e[i].pozj)
        {a[e[j].pozi][e[j].pozj]=0;
        e[j].id=0;
         e[j].pozi=0;
         e[j].pozj=0;
         e[j].dir=0;
         e[i].hp++;}
    if(a[e[i].pozi-1][e[i].pozj-1]==2)
      for(j=1;j<=1000;j++)
        if(e[j].pozi==e[i].pozi-1&&e[j].pozj==e[i].pozj-1)
        {a[e[j].pozi][e[j].pozj]=0;
        e[j].id=0;
         e[j].pozi=0;
         e[j].pozj=0;
         e[j].dir=0;
         e[i].hp++;}
     if(a[e[i].pozi][e[i].pozj-1]==2)
        for(j=1;j<=1000;j++)
        if(e[j].pozi==e[i].pozi&&e[j].pozj==e[i].pozj-1)
        {a[e[j].pozi][e[j].pozj]=0;
        e[j].id=0;
         e[j].pozi=0;
         e[j].pozj=0;
         e[j].dir=0;
         e[i].hp++;}
     if(a[e[i].pozi+1][e[i].pozj-1]==2)
     for(j=1;j<=1000;j++)
        if(e[j].pozi==e[i].pozi+1&&e[j].pozj==e[i].pozj-1)
        {a[e[j].pozi][e[j].pozj]=0;
        e[j].id=0;
         e[j].pozi=0;
         e[j].pozj=0;
         e[j].dir=0;
         e[i].hp++;}
     if(a[e[i].pozi+1][e[i].pozj]==2)
        for(j=1;j<=1000;j++)
        if(e[j].pozi==e[i].pozi+1&&e[j].pozj==e[i].pozj)
        {a[e[j].pozi][e[j].pozj]=0;
        e[j].id=0;
         e[j].pozi=0;
         e[j].pozj=0;
         e[j].dir=0;
         e[i].hp++;}
    if(a[e[i].pozi+1][e[i].pozj+1]==2)
       for(j=1;j<=1000;j++)
        if(e[j].pozi==e[i].pozi+1&&e[j].pozj==e[i].pozj+1)
        {a[e[j].pozi][e[j].pozj]=0;
        e[j].id=0;
         e[j].pozi=0;
         e[j].pozj=0;
         e[j].dir=0;
         e[i].hp++;}
    if(a[e[i].pozi][e[i].pozj+1]==2)
       for(j=1;j<=1000;j++)
        if(e[j].pozi==e[i].pozi&&e[j].pozj==e[i].pozj+1)
        {a[e[j].pozi][e[j].pozj]=0;
        e[j].id=0;
         e[j].pozi=0;
         e[j].pozj=0;
         e[j].dir=0;
         e[i].hp++;}
    if(a[e[i].pozi-1][e[i].pozj+1]==2)
        for(j=1;j<=1000;j++)
        if(e[j].pozi==e[i].pozi-1&&e[j].pozj==e[i].pozj+1)
        {a[e[j].pozi][e[j].pozj]=0;
        e[j].id=0;
         e[j].pozi=0;
         e[j].pozj=0;
         e[j].dir=0;
         e[i].hp++;}
    }
}
}

void boss_slam()
{int vs[1000];
 for(i=1;i<=1000;i++)
    if(i!=2)
    vs[i]=1;
 for(i=1;i<=1000;i++)
    for(j=1;j<=1000;j++)
     if(vs[j]==1)
    {if(e[j].pozi<e[2].pozi&&e[j].pozi>1)
        move_e('w',j);
      if(e[j].pozi>e[2].pozi&&e[j].pozi<20)
        move_e('s',j);
     if(e[j].pozj<e[2].pozj&&e[j].pozj>1)
        move_e('a',j);
     if(e[j].pozj>e[2].pozj&&e[j].pozj<20)
        move_e('d',j);
        vs[j]--;std::cout<<" ";
      }
}

void ai(int i,int &e_count) // eroare la dodge
{ int ok_e_move=1;// VERIFICARE DE MISCARE PENTRU A IMPIEDICA TWO-STEP
if(a[e[i].pozi-1][e[i].pozj]==3)
   {move_e('s',i);}
   else
    if(a[e[i].pozi-1][e[i].pozj-1]==3||a[e[i].pozi][e[i].pozj-1]==3)
    {move_e('d',i);}
   else
    if(a[e[i].pozi+1][e[i].pozj-1]==3||a[e[i].pozi+1][e[i].pozj]==3||a[e[i].pozi+1][e[i].pozj+1]==3)
    {move_e('w',i);}
   else
    if(a[e[i].pozi][e[i].pozj+1]==3||a[e[i].pozi-1][e[i].pozj+1]==3)
     {move_e('a',i);}
   else
    {
 if(e[i].pozi-e[1].pozi>8||e[i].pozi-e[1].pozi<-8||e[1].pozj-e[i].pozj>8||(e[1].pozj-e[i].pozj<-8&&ok_e_move!=0))
 {char m2;

 if((e[i].pozi<e[1].pozi&&e[1].pozi-e[i].pozi>e[1].pozj-e[i].pozj&&ok_e_move==1)||(e[i].pozi<e[1].pozi&&e[1].pozi-e[i].pozi>e[i].pozj-e[1].pozj&&ok_e_move==1))
   {ok_e_move--;
   move_e('s',i);}
 if((e[i].pozi>e[1].pozi&&e[i].pozi-e[1].pozi>e[i].pozj-e[1].pozj&&ok_e_move==1)||(e[i].pozi>e[1].pozi&&e[i].pozi-e[1].pozi>e[1].pozj-e[i].pozj&&ok_e_move==1))
   {ok_e_move--;
    move_e('w',i);}
 if((e[i].pozj<e[1].pozj&&e[1].pozj-e[i].pozj>e[i].pozi-e[1].pozi&&ok_e_move==1)||(e[i].pozj<e[1].pozj&&e[1].pozj-e[i].pozj>e[1].pozi-e[i].pozi&&ok_e_move==1))
   {ok_e_move--;
    move_e('d',i);}
 if((e[i].pozj>e[1].pozj&&e[i].pozj-e[1].pozj>e[i].pozi-e[1].pozi&&ok_e_move==1)||(e[i].pozj>e[1].pozj&&e[i].pozj-e[1].pozj>e[i].pozi-e[1].pozi&&ok_e_move==1))
   {ok_e_move--;
    move_e('a',i);}
 if(e[i].pozi-e[1].pozi==e[i].pozj-e[1].pozj&&ok_e_move==1)
    {ok_e_move--;
     srand(time(NULL));
     if((rand()%4)==1)
     m2='w';
     if((rand()%4)==2)
     m2='a';
     if((rand()%4)==3)
     m2='s';
     if((rand()%4)==4)
     m2='d';
     move_e(m2,i);}}
     else
        {if(e[i].pozi==e[1].pozi&&ok_e_move==1)
   {ok_e_move--;
    if(e[i].pozj>e[1].pozj)
     {m1='1';
     shoot_p(m1,i,e_count,3);
     e_count++;
     }
     if(e[i].pozj<e[1].pozj)
     {m1='3';
     shoot_p(m1,i,e_count,3);
     e_count++;
     }}
 if(e[i].pozj==e[1].pozj&&ok_e_move==1)
    {ok_e_move--;
     if(e[i].pozi>e[1].pozi)
       {m1='2';
       shoot_p(m1,i,e_count,3);
       e_count++;
     }
     if(e[i].pozi<e[1].pozi)
     {m1='4';
      shoot_p(m1,i,e_count,3);
      e_count++;
      }}

int di,dj;
di=e[i].pozi-e[1].pozi;
dj=e[i].pozj-e[1].pozj;
if(di<0)
di=-di;
if(dj<0)
dj=-dj;
if(di<dj)
{if(e[i].pozi<e[1].pozi&&ok_e_move!=0)
    {ok_e_move--;
     move_e('s',i);}
   if(e[i].pozi>e[1].pozi&&ok_e_move!=0)
     {ok_e_move--;move_e('w',i);}}
if(dj<di)
 {if(e[i].pozj<e[1].pozj&&ok_e_move!=0)
    {ok_e_move--;move_e('d',i);}
   if(e[i].pozj>e[1].pozj&&ok_e_move!=0)
     {ok_e_move--;move_e('a',i);}}
 if(dj==di)
 {int random_move;
  srand(time(NULL));
  random_move=rand()%10;
  if(random_move%4==1&&ok_e_move!=0)
    {ok_e_move--;move_e('w',i);}
  if(random_move%4==2&&ok_e_move!=0)
    {ok_e_move--;move_e('a',i);}
  if(random_move%4==3&&ok_e_move!=0)
    {ok_e_move--;move_e('w',i);}
  if(random_move%4==0&&ok_e_move!=0)
    {ok_e_move--;move_e('a',i);}
 }
}}}

void clear_e(int &clear_e_count,int &e_count)
{for(i=1;i<=1000;i++)
if(e[i].id==3&&e[i].pozi<1&&e[i].pozi>20&&e[i].pozj<1&&e[i].pozj>20)
    {e[i].id=0;
    e[i].hp=0;
    e[i].pozi=0;
    e[i].pozj=0;
    e[i].pozi=0;
    e[i].dir=0;}
clear_e_count--;
if(clear_e_count%60==0)
    {l_count==350;
    l_s_count==300;}
if(clear_e_count==0)
    {e_count=500;
     clear_e_count=400;}
}

void barricade(char m,int n,int &e_count,int &b_count_p)
{if(b_count_p>0)
 m=getch();
 {if(m=='1'&&a[e[n].pozi][e[n].pozj-1]==0) // stanga
        {e[e_count].hp=3;
         e[e_count].id=4;
         e[e_count].dir=1;
         e[e_count].pozi=e[n].pozi;
         e[e_count].pozj=e[n].pozj-1;
         a[e[e_count].pozi][e[e_count].pozj]=4;
         }



    if(m=='2'&&a[e[n].pozi-1][e[n].pozj]==0) // sus
        {e[e_count].hp=3;
         e[e_count].id=4;
         e[e_count].dir=2;
         e[e_count].pozi=e[n].pozi-1;
         e[e_count].pozj=e[n].pozj;
         a[e[e_count].pozi][e[e_count].pozj]=4;}

     if(m=='3'&&a[e[n].pozi][e[n].pozj+1]==0) //dreapta
        {e[e_count].hp=3;
         e[e_count].id=4;
         e[e_count].dir=3;
         e[e_count].pozi=e[n].pozi;
         e[e_count].pozj=e[n].pozj+1;
         a[e[e_count].pozi][e[e_count].pozj]=4;}

     if(m=='4'&&a[e[n].pozi+1][e[n].pozj]==0) //jos
        {e[e_count].hp=3;
         e[e_count].id=4;
         e[e_count].dir=4;
         e[e_count].pozi=e[n].pozi+1;
         e[e_count].pozj=e[n].pozj;
        a[e[e_count].pozi][e[e_count].pozj]=4;}
b_count_p--;}}


void boss(int &boss_count,int &m_e_count)
{int boss_c=0,boss_d=0;

 for(i=1;i<=1000;i++)
   if(e[i].id==7)
    {if(boss_count%6==0)
     {while(boss_c<=0||boss_c>20)
         {
           boss_c=rand()%(e[i].pozi+5)+(e[i].pozi-5);}
      while(boss_d<=0||boss_d>20)
        {
         boss_d=rand()%(e[i].pozj+5)+(e[i].pozj-5);}
         init_mob(m_e_count,boss_c,boss_d);
          m_e_count++;}}
           boss_count++;
}

void reset_e()
{for(i=1;i<=1000;i++)
 {e[i].hp=0;
       e[i].id=0;
       e[i].pozi=0;
       e[i].pozj=0;
       e[i].dir=0;}

}

void shield_indicator()
{ if(a[e[1].pozi-1][e[1].pozj]==0)
      {gotoxy(2*e[1].pozj,(e[1].pozi)-1);
       SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 5);
       std::cout<<"2";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
        if(a[e[1].pozi][e[1].pozj-1]==0)
      {gotoxy((2*e[1].pozj)-1,e[1].pozi);
       SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 5);
       std::cout<<"1";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
       if(a[e[1].pozi][e[1].pozj+1]==0)
      {gotoxy((2*e[1].pozj)+1,e[1].pozi);
       SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 5);
       std::cout<<"3";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
        if(a[e[1].pozi+1][e[1].pozj]==0)
      {gotoxy(2*e[1].pozj,(e[1].pozi)+1);
       SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 5);
       std::cout<<"4";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
}

void sprint_indicator()
{
    if(a[e[1].pozi-2][e[1].pozj]==0)
      {gotoxy(2*e[1].pozj,(e[1].pozi)-2);
       SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 14);
       std::cout<<"w";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
        if(a[e[1].pozi][e[1].pozj-2]==0)
      {gotoxy((2*e[1].pozj)-2,e[1].pozi);
       SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 14);
       std::cout<<"a";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
       if(a[e[1].pozi][e[1].pozj+2]==0)
      {gotoxy((2*e[1].pozj)+2,e[1].pozi);
       SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 14);
       std::cout<<"d";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
        if(a[e[1].pozi+2][e[1].pozj]==0)
      {gotoxy(2*e[1].pozj,(e[1].pozi)+2);
       SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 14);
       std::cout<<"s";
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);}
       if(sprint_count>=4)
      {sprint_count=0;
       m1=getch();
        sprint_e(m1,1);}
}

void ssa()
{gotoxy(0,0);
 scan_pos();
 afisare_joc();
 gotoxy(1000,1000);
}

int turn(int &live_count_e)
{
ssa();


stats(1);
if(kbhit())
{m1=getch();
move_e(m1,1);
shoot_p(m1,1,e_count,3);
if(m1=='1'||m1=='2'||m1=='3'||m1=='4'||m1=='j'||m1=='i'||m1=='l'||m1=='k')
    e_count++;
if(m1=='b')
    {shield_indicator();
    barricade(m1,1,b_count_2,b_count_p);
     b_count_2++;

    }
if(m1==' '&&sprint_count>=100)
    {sprint_indicator();}
ssa();}



{if(e[2].hp<=7)
 if(slam_ok>=20)
  {boss_slam();
  slam_ok=0;}
if(live_count_e%4==0)
ai(2,e_count);

if(live_count_e%4==0)
{for(i=2;i<=1000;i++)
  if(e[i].id==2)
     {ai(i,e_count);}
boss(boss_count,m_e_count);
boss_eat();}

ssa();
if(live_count_e%1==0)
bullet();

dmg();
death();
ssa();
clear_e(clear_e_c,e_count);
if(!win)
    return 0;
sprint_count++;
slam_ok++;
live_count_e++;
}

}

void session()
{init_player(start_pi,start_pj);
 init_ai(2);
 debris(d_count);
 win=1;
 e[1].hp=3;
 e[350].id=9;
e[350].pozi=10;
e[350].pozj=10;
a[10][10]=9;
e[350].dir=1;
while(win!=0)
   turn(live_count_e);
}

void death_p1(int &k)
{
 if(e[1].hp==0)
 {std::cout<<"PLAYER 2 WON\n";
 getch();
 k=0;}
}

void death_p2(int &k)
{
 if(e[2].hp==0)
 {std::cout<<"PLAYER 1 WON\n";

 getch();
 k=0;}
}

void stats_pvp()
{   gotoxy(45,3);
  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 2);
 std::cout<<"PLAYER 1 HP:";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
  for(i=1;i<=e[1].hp;i++)
  {SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 2);
   std::cout<<"|";}
   std::cout<<"      ";
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy(42,4);
    std::cout<<"               ";
      gotoxy(45,10 );
  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 6);
 std::cout<<"PLAYER 2 HP:";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
  for(i=1;i<=e[2].hp;i++)
  {SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 6);
   std::cout<<"|";}
   std::cout<<"      ";
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int turn_pvp(int &live_count_e)
{ssa();
stats_pvp();
if(kbhit())
{m1=getch();
move_e(m1,1);
shoot_p(m1,1,e_count,3);
if(m1=='1'||m1=='2'||m1=='3'||m1=='4')
    e_count++;
if(m1=='j')
 move_e('a',2);
if(m1=='i')
 move_e('w',2);
if(m1=='l')
 move_e('d',2);
if(m1=='k')
 move_e('s',2);
if(m1=='7')
{shoot_p('1',2,e_count,3);
    e_count++;}
if(m1=='8')
{shoot_p('2',2,e_count,3);
    e_count++;}
if(m1=='9')
{shoot_p('3',2,e_count,3);
    e_count++;}
if(m1=='0')
{shoot_p('4',2,e_count,3);
    e_count++;}
}ssa();
if(live_count_e%1==0)
bullet();
dmg();

death_p1(win);
death_p2(win);
for(i=2;i<=1000;i++)
  if(e[i].hp==0&&e[i].id!=3)
  {a[e[i].pozi][e[i].pozj]=0;
   e[i].id=0;
   e[i].pozi=0;
   e[i].pozj=0;
   e[i].dir=0;}
ssa();
clear_e(clear_e_c,e_count);
if(!win)
    return 0;
live_count_e++;
}

int score_death(int &win)
{bool dead=1;
 for(i=1;i<=1000;i++)
    if(e[i].id==2)
      dead=0;
 if(dead)
    {std::cout<<"YOU WON";
    win=0;
    getch();}
}

int turn_score_attack(int &live_count_e,int &m_e_count,int &score)
{ssa();


stats(1);
if(kbhit())
{m1=getch();
move_e(m1,1);
shoot_p(m1,1,e_count,3);
if(m1=='1'||m1=='2'||m1=='3'||m1=='4'||m1=='j'||m1=='i'||m1=='l'||m1=='k')
    e_count++;
if(m1=='b')
    {shield_indicator();
    barricade(m1,1,b_count_2,b_count_p);
     b_count_2++;
    }
if(m1==' '&&sprint_count>=100)
    {sprint_indicator();}
ssa();}
if(score%50==0 )
for(i=1;i<=score/50;i++)
  {init_mob(m_e_count,rand()%18+1,rand()%18+1);
   m_e_count++;}

if(live_count_e%4==0)
{for(i=2;i<=1000;i++)
  if(e[i].id==2)
     ai(i,e_count);}
ssa();
if(live_count_e%1==0)
bullet();
dmg();
p_death(win);
for(i=2;i<=1000;i++)
  if(e[i].hp==0&&e[i].id!=3)
  {a[e[i].pozi][e[i].pozj]=0;
   e[i].id=0;
   e[i].pozi=0;
   e[i].pozj=0;
   e[i].dir=0;}
ssa();
clear_e(clear_e_c,e_count);
if(!win)
    return 0;
sprint_count++;
score++;
live_count_e++;
gotoxy(45,10);
std::cout<<"SCORE = ";std::cout<<score;
}

void score_attack()
{init_player(start_pi,start_pj);
e[1].hp=3;
 live_count_e=0;
 debris(d_count);
 win=1;
 init_mob(499,5,5);
 int score=0;
 b_count_p=4;
 while(win!=0)
    turn_score_attack(live_count_e,m_e_count,score);

}

void pvp()
{init_player(start_pi,start_pj);
 init_p2(2);
 e[1].hp=3;
 e[2].hp=3;
 debris(d_count);
 win=1;
 live_count_e=0;
while(win!=0)
   turn_pvp(live_count_e);
}

void menu2(int starter)
{char g; if(starter==1)
    std::cout<<"==>";
 else
    std::cout<<"   ";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 10);
 std::cout<<"PLAYER";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
 std::cout<<" VS. ";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 9);
 std::cout<<"COMPUTER";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
if(starter==1)
    std::cout<<"<==\n";
 else
    std::cout<<"   \n";
  if(starter==2)
    std::cout<<"==>";
 else
    std::cout<<"   ";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 10);
 std::cout<<"PLAYER";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
 std::cout<<" VS. ";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 14);
 std::cout<<"PLAYER";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
 if(starter==2)
    std::cout<<"<==";
 else
    std::cout<<"   \n";
    if(starter==3)
    std::cout<<"==>";
 else
    std::cout<<"   ";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 207);
 std::cout<<"SCORE ATTACK";
  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);

 if(starter==3)
    std::cout<<"<== \n";
 else
    std::cout<<"   \n";
if(starter==4)
    std::cout<<"==>";
 else
    std::cout<<"   ";
 std::cout<<"BACK TO MENU";
 if(starter==4)
    std::cout<<"<== \n";
 else
    std::cout<<"   \n";
std::cout<<"\n SELECT YOUR OPTION WITH W(up) S(down) AND SPACE";
 while(1)
 {
 g=getch();if(g==32&&starter==1)
{reset_e();
 reset_joc();
 session();}
if(g==32&&starter==2)
   {reset_e();
 reset_joc();
 pvp();}
if(g==32&&starter==3)
    {reset_e();
     reset_joc();
     score_attack();
     }
if(g==32&&starter==4)
{break;
}
    if(g=='s')
    {starter++;}
if(g=='w')
    {starter--;}
    if(starter>4)
    starter=1;
if(starter<1)
    starter=1;
 system("cls");

if(starter==1)
    std::cout<<"==>";
 else
    std::cout<<"   ";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 10);
 std::cout<<"PLAYER";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
 std::cout<<" VS. ";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 9);
 std::cout<<"COMPUTER";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
if(starter==1)
    std::cout<<"<==\n";
 else
    std::cout<<"   \n";
  if(starter==2)
    std::cout<<"==>";
 else
    std::cout<<"   ";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 10);
 std::cout<<"PLAYER";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
 std::cout<<" VS. ";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 14);
 std::cout<<"PLAYER";
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
 if(starter==2)
    std::cout<<"<==\n";
 else
    std::cout<<"   \n";
    if(starter==3)
    std::cout<<"==>";
 else
    std::cout<<"   ";
  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 207);
 std::cout<<"SCORE ATTACK";
  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 7);
 if(starter==3)
    std::cout<<"<==\n";
 else
    std::cout<<"   \n";
    if(starter==4)
    std::cout<<"==>";
 else
    std::cout<<"   ";
 std::cout<<"BACK TO MENU";
 if(starter==4)
    std::cout<<"<== \n";
 else
    std::cout<<"   \n";
std::cout<<"\n SELECT YOUR OPTION WITH W(up) S(down) AND SPACE";




}}

void menu(int starter)
{char g; if(starter==1)
    std::cout<<"==>";
 else
    std::cout<<"   ";
 std::cout<<"START GAME";
if(starter==1)
    std::cout<<"<==\n";
 else
    std::cout<<"   \n";
  if(starter==2)
    std::cout<<"==>";
 else
    std::cout<<"   ";
 std::cout<<"SHOW INSTRUCTIONS";
 if(starter==2)
    std::cout<<"<==";
 else
    std::cout<<"   \n";
    if(starter==3)
    std::cout<<"==>";
 else
    std::cout<<"   ";
 std::cout<<"QUIT GAME";
 if(starter==3)
    std::cout<<"<== \n";
 else
    std::cout<<"   \n";
std::cout<<"\n SELECT YOUR OPTION WITH W(up) S(down) AND SPACE";
 while(1)
 {
 g=getch();if(g==32&&starter==1)
{system("cls");
 menu2(1);}
if(g==32&&starter==2)
    instruction();
if(g==32&&starter==3)
    break;
    if(g=='s')
    {starter++;}
if(g=='w')
    {starter--;}
if(starter>3)
    starter=1;
if(starter<1)
    starter=3;
 system("cls");

if(starter==1)
    std::cout<<"==>";
 else
    std::cout<<"   ";
 std::cout<<"START GAME";
if(starter==1)
    std::cout<<"<==\n";
 else
    std::cout<<"   \n";
  if(starter==2)
    std::cout<<"==>";
 else
    std::cout<<"   ";
 std::cout<<"SHOW INSTRUCTIONS";
 if(starter==2)
    std::cout<<"<==\n";
 else
    std::cout<<"   \n";
    if(starter==3)
    std::cout<<"==>";
 else
    std::cout<<"   ";
 std::cout<<"QUIT GAME";
 if(starter==3)
    std::cout<<"<==\n";
 else
    std::cout<<"   \n";
std::cout<<"\n SELECT YOUR OPTION WITH W(up) S(down) AND SPACE";




}}

int main()
{ reset_joc();

 menu(starter);

  return 0;}

