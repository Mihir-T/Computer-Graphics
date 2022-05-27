#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
int main()
{
int gd=DETECT,gm,i;
initgraph(&gd,&gm," ");
int a,b;
a = getmaxx();
b = getmaxy();
std::cout<<a;
std::cout<<b;
//for moving circle from right to left, the following loop works

while(kbhit)
{
for(i=getmaxy();i>=393;i--)
{
setcolor(3);
setfillstyle(SOLID_FILL,10);          //LIGHTGREEN-10
circle(i,50,50);
floodfill(i+2,52,3);
delay(3);
cleardevice();
}


for(i=50;i<=103;i++)
{
setcolor(3);
setfillstyle(SOLID_FILL,10);
circle(393,i,50);
floodfill(393,i,3);
delay(3);
cleardevice();
}

for(i=393;i>=236;i--)

{
setcolor(3);
setfillstyle(SOLID_FILL,10);
circle(i,103,50);
floodfill(i,103,3);
delay(3);
cleardevice();
}

for(i=103;i>=50;i--)
{
setcolor(3);
setfillstyle(SOLID_FILL,10);
circle(236,i,50);
floodfill(236,i,3);
delay(3);
cleardevice();
}

for(i=236;i>=50;i--)

{
setcolor(3);
setfillstyle(SOLID_FILL,10);
circle(i,50,50);
floodfill(i+2,52,3);
delay(3);
cleardevice();
}

//for moving circle from top to bottom,the following loop works
for(i=50;i<=getmaxy()-50;i++)
{
setcolor(3);
setfillstyle(SOLID_FILL,10);
circle(50,i,50);
floodfill(52,i+2,3);
delay(3);
cleardevice();
}



for(i=50;i<=236;i++)
{
setcolor(3);
setfillstyle(SOLID_FILL,10);
circle(i,getmaxy()-50,50);
floodfill(i,getmaxy()-50,3);
delay(3);
cleardevice();
}

for(i=429;i>=286;i--)
{
setcolor(3);
setfillstyle(SOLID_FILL,10);
circle(236,i,50);
floodfill(236,i,3);
delay(3);
cleardevice();
}

for(i=236;i<=393;i++)
{
setcolor(3);
setfillstyle(SOLID_FILL,10);
circle(i,286,50);
floodfill(i,286,3);
delay(3);
cleardevice();
}

for(i=286;i<=50;i++)
{
setcolor(3);
setfillstyle(SOLID_FILL,10);
circle(393,i,50);
floodfill(393,i,3);
delay(3);
cleardevice();
}

for(i=286;i<=429;i++)
{
setcolor(3);
setfillstyle(SOLID_FILL,10);
circle(393,i,50);
floodfill(393,i,3);
delay(3);
cleardevice();
}

for(i=393;i<=589;i++)
{
setcolor(3);
setfillstyle(SOLID_FILL,10);
circle(i,429,50);
floodfill(i,429,3);
delay(3);
cleardevice();
}

for(i=getmaxy()-50;i>=50;i--)
{
setcolor(3);
setfillstyle(SOLID_FILL,10);
circle(getmaxx()-50,i,50);
floodfill(getmaxx()-50,i,3);
delay(3);
cleardevice();
}
}
getch();
closegraph();
}

