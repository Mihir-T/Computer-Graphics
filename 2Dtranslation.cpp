/* 2D translation of triangle*/
#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

using namespace std;

int abs (int n)
{
    if(n>0)
        return n;
    else
        return ( n * (-1));
}

void DDA(int X0, int Y0, int X1, int Y1)
{

    int steps;
    int dx = X1 - X0;
    int dy = Y1 - Y0;

    if (abs(dx)>abs(dy))
         steps = abs(dx);
    else
         steps = abs(dy);

    // calculate increment in x & y for each steps
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
        putpixel (round(X),round(Y),WHITE);  // put pixel at (X,Y)
        X += Xinc;           // increment in x at each step
        Y += Yinc;           // increment in y at each step
        delay(0.5);
    }
}

int main()
{
    int gd=DETECT,gm;
    int x,y,x1,y1,x2,y2,tx,ty;
    initgraph(&gd,&gm," ");
    cout<<"\nPlease enter first coordinates of the triangle:";
    cin>>x>>y;
    cout<<"\n Enter second coordinates of the triangle:";
    cin>>x1>>y1;
    cout<<"\nEnter third coordinates of the triangle:";
    cin>>x2>>y2;
    DDA(x,y,x1,y1);
    DDA(x1,y1,x2,y2);
    DDA(x2,y2,x,y);
    cout<<"\nNow enter the translation vector:";
    cin>>tx>>ty;
    DDA(x+tx,y+ty,x1+tx,y1+ty);
    DDA(x1+tx,y1+ty,x2+tx,y2+ty);
    DDA(x2+tx,y2+ty,x+tx,y+ty);
    getch();
    closegraph();
    return 0;
}

