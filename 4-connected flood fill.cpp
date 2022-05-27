#include<graphics.h>
int flood(int,int,int,int);
int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    rectangle(50,50,250,250);
    flood(55,55,10,0);
    getch();
    return 0;
}
int flood(int x,int y,int fillColor, int defaultColor)
{
    if(getpixel(x,y)== defaultColor)
    {
        delay(float(0.5));
        putpixel(x,y,fillColor);
        flood(x+1,y,fillColor,defaultColor);
        flood(x-1,y,fillColor,defaultColor);
        flood(x,y+1,fillColor,defaultColor);
        flood(x,y-1,fillColor,defaultColor);
    }
}
