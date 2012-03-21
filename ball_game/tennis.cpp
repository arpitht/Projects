#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>

REGS i,o;
SREGS s;
int oldy=30,y,bx=30,by=35,oldbx=30,oldby=35,d=1,c=1,score=0;

int initmouse(void)
// THIS FUNCTION ACTIVATES THE MOUSE
{
i.x.ax=0;
int86(0x33,&i,&o);
return(o.x.ax);
}

void showmouseptr(void)
// THIS FUNCTION DISPLAYS THE MOUSE
{
i.x.ax=1;
int86(0x33,&i,&o);
}

void hidemouseptr(void)
// THIS FUNCTION HIDES THE MOUSE
{
i.x.ax=2;
int86(0x33,&i,&o);
}

void restrictmouseptr(int x1,int y1,int x2,int y2)
// THIS FUNCTION RESTRICTS THE MOVEMENT OF MOUSE
{
i.x.ax=7;
i.x.cx=x1;
i.x.dx=x2;
int86(0x33,&i,&o);
i.x.ax=8;
i.x.cx=y1;
i.x.dx=y2;
int86(0x33,&i,&o);
}

void getmousepos(int *y)
// THIS FUNCTION FINDS THE MOUSE POSITION AND STATUS OF THE BUTTON
{
i.x.ax=3;
int86(0x33,&i,&o);
*y=o.x.dx;
}

void setmouseptr(int x,int y)
// THIS FUNCTION SETS MOUSE POINTER TO A PARTICULAR COORDINATE
{
i.x.ax=4;
i.x.cx=x;
i.x.dx=y;
int86(0x33,&i,&o);
}

void changecursor(void)
{
getmousepos(&y);
if(y!=oldy)
{
setfillstyle(1,0);
bar(610,oldy,620,oldy+60);
setfillstyle(1,3);
bar(610,y,620,y+60);
oldy=y;
}
}

void ball(void)
{
char s[3];
setcolor(0);
setfillstyle(1,0);
fillellipse(oldbx,oldby,11,11);
setcolor(2);
setfillstyle(11,14);
circle(bx,by,11);
fillellipse(bx,by,10,10);
oldbx=bx;
oldby=by;
if(bx==598){
if(by>=y-8&&by<=y+68)
{
score++;
for(int zx=600;zx<620;zx++)
{
for(int zy=10;zy<20;zy++)
putpixel(zx,zy,0);
}
setcolor(1);
itoa(score,s,10);
outtextxy(600,10,s);
c=-1;
}
else
{
score=0;
for(int zx=600;zx<620;zx++)
{
for(int zy=10;zy<20;zy++)
putpixel(zx,zy,0);
}
setcolor(1);
itoa(score,s,10);
outtextxy(600,10,s);
bx=30;
}
}
if(bx==30){c=1;}
if(by==469){d=-1;}
if(by==35){d=1;}
delay(5-(score)/3);
bx+=c;
by+=d;
}

void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
setcolor(14);
line(0,23,639,23);
initmouse();
setmouseptr(610,30);
restrictmouseptr(610,30,611,420);
do{
ball();
changecursor();
}while(!kbhit());
closegraph();
}
