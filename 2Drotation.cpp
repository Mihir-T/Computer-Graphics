//2D rotation
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<iostream>

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
    int gd=0,gm;
    int x1,y1,x2,y2,x3,y3;
    double s,c, angle;
    initgraph(&gd, &gm, "");
    setcolor(RED);
    cout<<"Enter the first coordinates of triangle: ";
    cin>>x1>>y1;
    cout<<"\nEnter the second coordinates of triangle: ";
    cin>>x2>>y2;
    cout<<"\nEnter the third coordinates of triangle: ";
    cin>>x3>>y3;
    DDA(x1,y1,x2,y2);
    DDA(x2,y2, x3,y3);
    DDA(x3, y3, x1, y1);
    cout<<"\nEnter rotation angle: ";
    cin>>angle;
    c = cos(angle *M_PI/180);
    s = sin(angle *M_PI/180);
    x1 = floor(x1 * c + y1 * s);
    y1 = floor(-x1 * s + y1 * c);
    x2 = floor(x2 * c + y2 * s);
    y2 = floor(-x2 * s + y2 * c);
    x3 = floor(x3 * c + y3 * s);
    y3 = floor(-x3 * s + y3 * c);
    DDA(x1, y1 ,x2, y2);
    DDA(x2,y2, x3,y3);
    DDA(x3, y3, x1, y1);
    getch();
    closegraph();
    return 0;
}

