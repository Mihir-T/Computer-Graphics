#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

int main()
{
    int n;
    printf("Choose the algorithm: 1.DDA 2.Bresenham");
    printf("\nEnter the number:");
    scanf("%d",&n);
    if(n == 1)
    {
        printf("DDA:");
        int gd = DETECT,gm;
        initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

        int x[20],y[20],X,Y,dx,dy,s,n,j,k,a=0,i=0;

        printf("\nEnter the Number of Vertices : ");
        scanf("%d",&n);
        printf("Enter the Co ordinates of points : ");
        for(i=0;i<n;i++)
        {
            printf("\npoint %d :\nx : ",i+1);
            scanf("%d",&x[i]);
            printf("\ny : ");
            scanf("%d",&y[i]);
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
        while(k<=s)
        {
            putpixel(X,Y,YELLOW);
            X = X + dx;
            Y = Y + dy;
            k = k+1;
        }
        if(a == 1)
        {
            break;
        }
      }
        getch();
        closegraph();
    }
   else if(n ==2 )
   {
        printf("Bresenham");
        int gd = DETECT,gm;
        initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

        int x[20],y[20],X,Y,dx,dy,s1,s2,n,p,v,temp,swap,j,k,a=0,i=0;

        printf("\nEnter the Number of Vertices : ");
        scanf("%d",&v);
        printf("Enter the Co ordinates of points : ");
        for(i=0;i<v;i++)
        {
            printf("\npoint %d :\nx : ",i+1);
            scanf("%d",&x[i]);
            printf("\ny : ");
            scanf("%d",&y[i]);
        }
        for(i=0,j=1;i<v;i++,j++)
        {
            if(j == v)
            {
                j = j-1;
                i = 0;
                a = 1;
            }
            X = x[i];
            Y = y[i];
            dx = x[j]-x[i];
            if(dx < 0)
            {
                dx = dx * -1;
            }
            dy = y[j]-y[i];
            if(dy < 0)
            {
                dy = dy * -1;
            }
            s1 = (x[j]-x[i])/dx;
            s2 = (y[j]-y[i])/dy;
            if(dy > dx)
            {
                temp = dx;
                dx = dy;
                dy = temp;
                swap = 1;
            }
            else
            {
                swap = 0;
            }
            n = 1;
            p = 2 * (dy - dx);
            putpixel(X,Y,YELLOW);
            while(n<=dx)
            {
                if(p >= 0)
                {
                    X = X + s1;
                    Y = Y + s2;
                    p = p + (2*(dy-dx));
                }
                else
                {
                    if(swap == 1)
                    {
                        Y = Y + s2;
                    }
                    else
                    {
                        X = X + s1;
                    }
                    p = p + 2*dy;
                }
                putpixel(X,Y,YELLOW);
                n = n + 1;
            }
            if(a == 1)
            {
                break;
            }
        }
        getch();
        closegraph();
        }
    else
    {
        printf("Enter a correct choice");
    }
}
