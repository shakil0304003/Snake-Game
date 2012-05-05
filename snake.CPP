#include<stdio.h>
#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

class sakil
{ private:
  long int x[200],y[200],x1[200],y1[200],b,g,g1,h,h1,i,m,te[4],go;
  char a1;
  public:
  long int a;
  sakil()
  {x[0]=10;y[0]=10;x1[0]=50;y1[0]=50;a=1;m=0;a1='f';
  g=200;h=200;g1=210;h1=210;i=0;}
  void show()
  {for(i=0;i<a;i++)
  {setcolor(GREEN);
   rectangle(x[i],y[i],x1[i],y1[i]);
   setfillstyle(SLASH_FILL,GREEN);
   floodfill(x[i]+1,y[i]+1,GREEN);
   }
   setcolor(RED);
   rectangle(g,h,g1,h1);
   setfillstyle(LINE_FILL,RED);
   floodfill(g+1,h+1,RED);

   }
  void get(char s)
  {if(a>1)
  { if((a1=='f'&&s=='s')||(a1=='F'&&s=='S'))
    s='f';
    if((a1=='s'&&s=='f')||a1=='S'&&s=='F')
    s='s';
    if((a1=='e'&&s=='d')||(a1=='E'&&s=='D'))
    s='e';
    if((a1=='d'&&s=='e')||a1=='D'&&s=='e')
    s='d';
      }
   if(s=='s'||s=='f'||s=='e'||s=='d'||s=='S'||s=='F'||s=='E'||s=='D')
   a1=s;
  te[0]=x[a-1];te[1]=x1[a-1];te[2]=y[a-1];te[3]=y1[a-1];
  for(i=a-1;i>=1;i--)
  {
  x[i]=x[i-1];
  x1[i]=x1[i-1];
  y[i]=y[i-1];
  y1[i]=y1[i-1];
  }
   switch(a1)
  { case 'F':
    case 'f':
      x[0]=x[0]+40;
      x1[0]=x1[0]+40;
      if(x1[0]>600)
      {x1[0]=x1[0]-600;x[0]=x[0]-600; }
      break;
   case 'S':
   case 's':
	    x[0]=x[0]-40;
	    x1[0]=x1[0]-40;
	    if(x[0]<0)
	    {x[0]=x[0]+600;x1[0]=x1[0]+600;}
	    break;
   case 'E':
   case 'e':y[0]=y[0]-40;
	    y1[0]=y1[0]-40;
	    if(y[0]<0)
	    {y[0]=y[0]+600;y1[0]=y1[0]+600;}
	    break;
   case 'D':
   case 'd':y[0]=y[0]+40;
	    y1[0]=y1[0]+40;
	    if(y1[0]>500)
	    {y[0]=y[0]-600;y1[0]=y1[0]-600;}
	    break;	     }
     }
void cal()
{
   if((x[0]<=g&&g<=x1[0])||(x[0]<=g1&&g1<=x1[0]))
   if((y[0]<=h&&h<=y1[0])||(y[0]<=h1&&h1<=y1[0]))
   { inc();
     play(1);
     int l=rand()%200;  l=l+100;
     if(l%2!=0)
     l=-l;
     if(l<3)
     l=-l;
     g=g+l;g1=g1+l;h=h+l;h1=h1+l;
     if(g1>450||h1>450)
     {g=g-300;g1=g1-300;h=h-300;h1=h1-300;}}
   }
void inc()
{ a=a+1;
  x[a-1]=te[0];
  x1[a-1]=te[1];
  y[a-1]=te[2];
  y1[a-1]=te[3];

}
int wrong()
{go=0;
for(i=2;i<a;i++)
if((x[0]==x[i])&&(x1[i]==x1[0]))
if((y[0]==y[i])&&(y1[i]==y1[0]))
{go=4;}
return(go); }
void result()
{ printf("\t\t\tYOUR SCORE : %ld.\n",a*50);            }
void play(int sa)
{float NaturalFreq[7]={130.81,146.83,164.81,174.61,196,220,246.94};
int n,i;
switch(sa)
{case 1:sound(NaturalFreq[6]*6);
	delay(60);
	nosound();
	break;
case 2:for(i=0;i<15;i++)
      {n=random(7);
       sound(NaturalFreq[n]*4);
       delay(80); }
       nosound();
       break;
case 3:for(i=4;i>=0;i--)
       {sound(NaturalFreq[i]*4);
       delay(10);  }
       nosound();
       break;
 }
}
  };
void main()
{  clrscr();
   int i,cl,mn,ran=500,la=1;
   char s;

 while(1)
{xx:
sakil sa;
int d,m;
d=DETECT;
initgraph(&d,&m,"e:\\tc\\bgi");
printf("\n\n\n\n\n\t\t\tTHIS GAME IS MADE BY SAKIL.\n");
printf("\tYOU PRESS S FOR LEFT F FOR RIGHT E FOR FORNT AND D FOR BACK TO PLAY.\n");
printf("\t\t\tTHIS IS LEAVE %d.\n",la);
printf("\t\t\tPRESS ENTER TO CONTINUE....");
 getch();
 s='f';
 while(1)
 {if(!kbhit())
 { }
 else
 {s=getch();
 if(s-48==1)
 break;
 }
  cleardevice();
  sa.get(s);
  sa.cal();
  sa.show();
  i=sa.wrong();
  if(i==4)
  {printf("\n\n\n\n\n\t\t\tYOU FAILED!\n");
  sa.play(2);
  sa.result();
  break;}
  if(sa.a>=40)
  {printf("\n\n\n\n\n\t\t\tYOU WON THE LEAVE.\n");
  sa.play(3);
  sa.result();
  if(la==5)
  {printf("\t\t\tYOU ARE THE BOSS.\n\t\t\tYOU WON THE GAME COMPLECTLY.\n");
  goto xy;}
  printf("\tIF YOU WANT TO PLAY NEXT LEAVE PRESS 1 AND 2 FOR EXIT THE GAME:");
  cin>>mn;
  if(mn==1)
  {ran=ran-100; la++;
  closegraph(); goto xx;}
  else
  goto xy;}
  delay(ran);}
  getch();
  xy:
  cout<<"\tIF YOU WANT TO EXIT THE GAME PRESS 1 AND 2 FOR CONTINUE:";
  cin>>cl;
  if(cl==1)
  break;
  ran=500;la=1;}
 closegraph();
}