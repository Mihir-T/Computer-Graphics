#include<graphics.h>
#include<iostream>
#include<conio.h>
using namespace std;

void dda()
{
int X,Y,dx,dy,n,s,j,k,x[20],y[20];
int a=0,i=0;
cout<<"Enter the Number of Vertices : ";
cin>>n;
cout<<"Enter the Co ordinates of points : ";
for(i=0;i<n;i++)
{
cout<<"\npoint %d :\nx : ";
cin>>x[i];
cout<<"\ny : ";
cin>>y[i];
}
for(i=0,j=1;i<n;i++,j++)
{
if(j == n)
{
j = j-1;
i = 0;
a = 1;
}
X = x[j]-x[i];
if(X<0)
{
X = X * -1;
}
Y = y[j]-y[i];
if(Y<0)
{
Y = Y * -1;
}
if(X>Y)
{
s = X;
}
else
{
s = Y;
}
dx = (x[j]-x[i])/s;
dy = (y[j]-y[i])/s;
X = x[i];
Y = y[i];
k = 1;
putpixel(X,Y,WHITE);
while(k<=s)
{X = X + dx;
Y = Y + dy;
k = k+1;
putpixel(X,Y,WHITE);
}
if(a == 1)
{
break;
}
}
}

void boundaryfill(int x,int y,int newcolour,int
boundcolour)
{
int current;
current = getpixel(x,y);
if(current != newcolour && current !=
boundcolour)
{
putpixel(x,y,newcolour);
boundaryfill(x,y+1,newcolour,boundcolour);
boundaryfill(x,y-1,newcolour,boundcolour);
boundaryfill(x+1,y,newcolour,boundcolour);
boundaryfill(x-1,y,newcolour,boundcolour);
}
}

int main()

{

    int gd = DETECT,gm;
    int x[20],y[20],newcolour;
    initgraph(&gd,&gm,"");
    dda();
    getch();
    int fx = ((x[0]+x[1])/2 + (x[2]+x[3])/2)/2;
    int fy = ((y[0]+y[1])/2 + (y[2]+y[3])/2)/2;
    boundaryfill(fx,fy,newcolour,YELLOW);
    getch();
    closegraph();
    return 0;

}
