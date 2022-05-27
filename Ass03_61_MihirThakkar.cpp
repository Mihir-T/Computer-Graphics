#include<graphics.h>

void boundaryfill4(int x,int y,int f_color,int b_color)
    {
        if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
        {
            putpixel(x,y,f_color);
            boundaryfill4(x+1,y,f_color,b_color);
            boundaryfill4(x,y+1,f_color,b_color);
            boundaryfill4(x-1,y,f_color,b_color);
            boundaryfill4(x,y-1,f_color,b_color);
        }
    }

void boundaryFill8(int x, int y, int fill_color,int boundary_color)
        {
            if(getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color)
            {
                putpixel(x, y, fill_color);
                boundaryFill8(x + 1, y, fill_color, boundary_color);
                boundaryFill8(x, y + 1, fill_color, boundary_color);
                boundaryFill8(x - 1, y, fill_color, boundary_color);
                boundaryFill8(x, y - 1, fill_color, boundary_color);
                boundaryFill8(x - 1, y - 1, fill_color, boundary_color);
                boundaryFill8(x - 1, y + 1, fill_color, boundary_color);
                boundaryFill8(x + 1, y - 1, fill_color, boundary_color);
                boundaryFill8(x + 1, y + 1, fill_color, boundary_color);
            }
        }
int main()
{
	int choice;
	printf("Enter your choice for filling the polygon:\n1.4-connected Boundary fill\n");
	printf("2.8-connected Boundary fill\n");
	printf("\nChoice:");
	scanf("%d",&choice);
	if(choice == 1)
	{

        printf("4-connected Boundary fill\n");
        int gm,gd = DETECT,radius;
        int x,y;

        printf("\nEnter x position for circle:");
        scanf("%d",&x);
        printf("Enter y position for circle:");
        scanf("%d",&y);
        printf("Enter radius of circle:");
        scanf("%d",&radius);

        initgraph(&gd,&gm,"");
        circle(x,y,radius);
        boundaryfill4(x,y,4,15);
        delay(5000);
        closegraph();
        return 0;
    }
    else if(choice == 2)
        {
            printf("8-connected Boundary fill");
            int gd = DETECT, gm;
            initgraph(&gd, &gm, "");
            // Rectangle function
            rectangle(50, 50, 100, 100);
            // Function calling
            boundaryFill8(55, 55, 4, 15);
            delay(5);
            getch();
            closegraph();
            return 0;
        }
    else
        {
            printf("\nEnter a valid choice.\n");
            return 0;
        }
}


