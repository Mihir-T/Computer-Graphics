#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main()
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
        putpixel(x_mid + x, y_mid + y, 2); /*2 = Green colour*/
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

    getch();
}

