#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

int drawcircle(int xc,int yc,int x,int y)
{
    putpixel(xc+x, yc+y, YELLOW);
    putpixel(xc-x, yc+y, YELLOW);
    putpixel(xc+x, yc-y, YELLOW);
    putpixel(xc-x, yc-y, YELLOW);
    putpixel(xc+y, yc+x, YELLOW);
    putpixel(xc-y, yc+x, YELLOW);
    putpixel(xc+y, yc-x, YELLOW);
    putpixel(xc-y, yc-x, YELLOW);
}

int main()
{
    int n;
    printf("Choose: 1.Bresenham 2.Midpoint");
    printf("\nEnter the choice:");
    scanf("%d",&n);
  if(n==1)
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
    }
   else
  {
        int x, y, x_mid, y_mid, r, d;
        int gd = DETECT, gm;
        initgraph(&gd, &gm ,"");
        printf("MIDPOINT CIRCLE ALGORITHM");
        printf("\nEnter the co-ordinate x_mid: ");
        scanf("%d",&x_mid);
        printf("\nEnter the co-ordinate y_mid: ");
        scanf("%d",&y_mid);
        printf("\nEnter the radius: ");
        scanf("%d",&r);
        x = 0;
        y = r;
        d = 1-r;
        do
        {
            putpixel(x_mid + x, y_mid + y, 2); /*2 = Green color*/
            putpixel(x_mid + y, y_mid + x, 2);
            putpixel(x_mid - y, y_mid + x, 2);
            putpixel(x_mid - x, y_mid + y, 2);
            putpixel(x_mid - x, y_mid - y, 2);
            putpixel(x_mid - y, y_mid - x, 2);
            putpixel(x_mid + y, y_mid - x, 2);
            putpixel(x_mid + x, y_mid - y, 2);
            if(d<0)
            {
                d+=(2*x)+1;
            }
            else
            {
                y=y-1;
                d+=(2*x)-(2*y)+1;
            }
            x=x+1;
          }while(y>x);
       }

        getch();
        return 0;
}

