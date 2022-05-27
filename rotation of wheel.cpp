#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
//(example of rotation and translation)
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

int xc=150,yc=200,r=50;
int x[15],y[15];
void drawcircles()
{
        setcolor(YELLOW);
        circle(xc,yc,r);
        circle(xc,yc,r+5);
}
int main()
{
        double angle=0,theta;
        int i,a;
        int gd=DETECT,gm;
        initgraph(&gd,&gm,"");
        a=xc+r;
        while(!kbhit())
        {
                while(a<=630)
                {
                        theta=M_PI*angle/180;
                        cleardevice();
                        drawcircles();
                        for(i=0;i<18;i++)
                        {
                                theta=M_PI*angle/180;
                                x[i]=xc+r*cos(theta);
                                y[i]=yc+r*sin(theta);
                                angle+=20;
                                DDA(xc,yc,x[i],y[i]);
                        }
                        angle+=2; xc+=2; a=xc+r;
                        delay(50);
                }
                xc=50;  r=35; a=xc+r;
        }
        getch();
        closegraph();
        return 0;
}
