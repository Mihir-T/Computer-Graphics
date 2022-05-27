#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int x[20],y[20],n;

void boundaryfill(int x,int y,int newcolour,int edgecolour,int fencecolour)
{
    int current;
    current = getpixel(x,y);
    if(current != edgecolour && current != newcolour && current != fencecolour)
    {
        putpixel(x,y,newcolour);
        boundaryfill(x,y+1,newcolour,edgecolour,fencecolour);
        boundaryfill(x,y-1,newcolour,edgecolour,fencecolour);
        boundaryfill(x+1,y,newcolour,edgecolour,fencecolour);
        boundaryfill(x-1,y,newcolour,edgecolour,fencecolour);
    }
}

void dda()
{
    int X,Y,dx,dy,s,j,k,a=0,i=0;

    printf("Enter the Number of Vertices : ");
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
        putpixel(X,Y,WHITE);
        while(k<=s)
        {
            X = X + dx;
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

main()
{
    int gd=DETECT,gm;
    int i,fx,fy;
    initgraph(&gd,&gm,"");
    dda();
    setcolor(YELLOW);
    if(n == 3)
    {
        line((x[0]+x[1])/2,(y[0]+y[1])/2,x[2],y[2]);
        fx = ((x[0]+x[1])/2 + x[2])/2;
        fy = ((y[0]+y[1])/2 + y[2])/2;
    }
    else
    {
        line((x[0]+x[1])/2,(y[0]+y[1])/2,(x[2]+x[3])/2,(y[2]+y[3])/2);
        fx = ((x[0]+x[1])/2 + (x[2]+x[3])/2)/2;
        fy = ((y[0]+y[1])/2 + (y[2]+y[3])/2)/2;
    }
    //putpixel(fx,fy,YELLOW);
    int edgecolour,newcolour;
    edgecolour = WHITE;
    newcolour = RED;
    boundaryfill(fx,fy+1,newcolour,edgecolour,YELLOW);
    boundaryfill(fx,fy-1,newcolour,edgecolour,YELLOW);
    getch();
    closegraph();
}
