#include<graphics.h>

void boundaryfill(int x,int y,int f_color,int b_color)
{
	if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
	{
		putpixel(x,y,f_color);
		boundaryfill(x+1,y,f_color,b_color);
		boundaryfill(x,y+1,f_color,b_color);
		boundaryfill(x-1,y,f_color,b_color);
		boundaryfill(x,y-1,f_color,b_color);
	}
}
//getpixel(x,y) gives the color of specified pixel

int main()
{
	int gm,gd=DETECT,radius;
	int x,y;

	printf("Enter x position for circle:");
	scanf("%d",&x);
	printf("Enter y position for circle:");
	scanf("%d",&y);
	printf("Enter radius of circle:");
	scanf("%d",&radius);

	initgraph(&gd,&gm,"");
	circle(x,y,radius);
	boundaryfill(x,y,4,15);
	delay(5000);
	closegraph();

	return 0;
}
