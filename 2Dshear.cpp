//2D shear
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<dos.h>
#include<math.h>

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
    float x1,y1,x2,y2,x,y,x3,y3,n;
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    cout<<"Enter the first coordinates of triangle:";
    cin>>x1>>y1;
    cout<<"\nEnter the second coordinates of the triangle:";
    cin>>x2>>y2;
    cout<<"\nEnter the third coordinates of the triangle:";
    cin>>x3>>y3;
    setcolor(5);
    DDA(x1,y1,x2,y2);
    DDA(x1,y1,x3,y3);
    DDA(x3,y3,x2,y2);
    cout<<"\nEnter the number for axis to see the shear:"; /*1 for x-axis,2 for y-axis*/
    cin>>n;
    switch(int(n))
    {
        case 1:
        {
            cout<<"\nEnter the value of shearing coordinates for x-shear:";
            cin>>x;
            cout<<"\nShear in x-axis is:";
            setcolor(10);
            DDA(x1,y1,x2*x,y2);
            DDA(x1,y1,x3*x,y3);
            DDA(x3*x,y3,x2*x,y2);
            getch();
            break;
        }
        case 2:
        {
            cout<<"\nEnter the value of shearing coordinates for y-shear:";
            cin>>y;
            cout<<"\nShear in y-axis is:";
            setcolor(4);
            DDA(x1,y1,x2,y2*y);
            DDA(x1,y1,x3,y3*y);
            DDA(x3,y3*y,x2,y2*y);
            getch();
            break;
        }
    }
    closegraph();
    getch();
    return 0;
}
