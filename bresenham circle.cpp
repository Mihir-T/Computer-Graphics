#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

int drawcircle(int xc,int yc,int x,int y)
{
    putpixel(xc+x, yc+y, RED);
    putpixel(xc-x, yc+y, YELLOW);
    putpixel(xc+x, yc-y, GREEN);
    putpixel(xc-x, yc-y, WHITE);
    putpixel(xc+y, yc+x, RED);
    putpixel(xc-y, yc+x, YELLOW);
    putpixel(xc+y, yc-x, GREEN);
    putpixel(xc-y, yc-x, WHITE);
}

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    int X,Y,R,D,XC,YC;
    printf("BRESENHAM'S CIRCLE DRAWING ALGORITHM");
    printf("\nEnter the radius : ");
    scanf("%d",&R);
    printf("\n\nEnter the Co ordinates of center of Circle : ");
    printf("\nX : ");
    scanf("%d",&XC);
    printf("\nY : ");
    scanf("%d",&YC);
    X = 0;
    Y = R;
    D = 3 - 2*R;
    drawcircle(XC,YC,X,Y);
    while(X<Y)
    {
        X = X + 1;
        if(D < 0)
        {
            D = D + 4*X + 6;
        }
        else
        {
            Y = Y - 1;
            D = D + 4*(X-Y) + 10;
        }
        drawcircle(XC,YC,X,Y);
    }
    getch();
    closegraph();
    return 0;
}
