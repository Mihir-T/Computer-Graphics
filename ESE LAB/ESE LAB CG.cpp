#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int x[20],y[20],n = 4;

void boundaryfill(int x,int y,int nc,int bc)
{

    if(getpixel(x,y)!=nc && getpixel(x,y)!=bc)
    {
        putpixel(x,y,nc);
        boundaryfill(x,y+1,nc,bc);
        boundaryfill(x,y-1,nc,bc);
        boundaryfill(x+1,y,nc,bc);
        boundaryfill(x-1,y,nc,bc);
    }
}

void dda()
{
    int X,Y,dx,dy,s,j,k,a=0,i=0;
    printf("Enter 4 Co-ordinates : \n\n");

    for(i=0;i<n;i++)
    {
        printf("\nEnter Co-ordinates for vertice %d :\n\nx : ",i+1);
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
        putpixel(X,Y,YELLOW);
        while(k<=s)
        {
            X = X + dx;
            Y = Y + dy;
            k = k+1;
            putpixel(X,Y,YELLOW);
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

    fx = ((x[0]+x[1])/2 + (x[2]+x[3])/2)/2;
    fy = ((y[0]+y[1])/2 + (y[2]+y[3])/2)/2;

    int nc=RED;

    boundaryfill(fx,fy,nc,YELLOW);

    getch();
    closegraph();
}
