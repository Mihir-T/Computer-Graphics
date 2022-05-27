
#include<iostream>
#include<conio.h>
#include<stdio.h>>
#include<graphics.h>
#include<math.h>

using namespace std;

void k_curve(long double x,long double y,long double l,long double ang,int n);

void line1(int x_1,int y_1,int x_2,int y_2);

void bezier (int x1[], int y1[], int no_ctrlpt)
{
    int i,j,row,col;
    double t,xt=0,yt=0; // xt , yt - points to plot curve
    int pcoeff[20][20];  // used to save the coefficents of the polynomial
    // created using pascal triangle
// code to find the coefficient of the polynomial
    for(i=0; i<no_ctrlpt; i++) // no_ctrlpt - number of control points .
        // one point is a set of x, y coordinate
        {
            for(j=0; j<=i; j++)
                {
                    if(j==0||i==j)
                        {
                            pcoeff[i][j]=1;
                        }
                    else
                        {
                            pcoeff[i][j]=pcoeff[i-1][j-1]+pcoeff[i-1][j];
                        }
                }
        }
// code to compute the blend and to fit the curve
    for (t = 0.0; t < 1.0; t += 0.005)
        {
            int k, n= no_ctrlpt-1;
            double blend, term1,term2;
            xt=0.0;
            yt=0.0;
            for(k=0; k<no_ctrlpt; k++)
                {
                    if(k==0)   // check needed since if k=0 then pow (t,k) will return domain error
                        term1=1; //since anything raise to zero is 1
                    else
                        term1=pow(t,k);
                    term2=pow( 1-t, n-k);
                    blend = (double)pcoeff[no_ctrlpt-1][k]*term1*term2; // no_ctrlpt - 1 need since
                    //only last row  of the generated pascal triangle is needed
                    xt=xt+x1[k]*blend;
                    yt=yt+y1[k]*blend;
                }
            putpixel ((int)xt,(int)yt, WHITE);
        }
    for (i=0; i<no_ctrlpt; i++)
        putpixel (x1[i], y1[i], YELLOW);
}

void k_curve(long double x,long double y,long double length ,long double angle,int n_order)
    { if(n_order>0)
    {
    length /=3;
    k_curve(x,y,length ,angle,(n_order-1));
    x+=(length *cosl(angle*(M_PI/180)));
    y+=(length *sinl(angle*(M_PI/180)));
    k_curve(x,y,length ,(angle-60),(n_order-1));
    x+=(length *cosl((angle-60)*(M_PI/180)));
    y+=(length *sinl((angle-60)*(M_PI/180)));
    k_curve(x,y,length ,(angle+60),(n_order-1));
    x+=(length *cosl((angle+60)*(M_PI/180)));
    y+=(length *sinl((angle+60)*(M_PI/180)));
    k_curve(x,y,length ,angle,(n_order-1));
    }
    else
    line1(x,y,(int)(x+length *cosl(angle*(M_PI/180))+0.5),(int)(y+length *sinl(angle*(M_PI
    /180))));
    }
    void line1(int x_1,int y_1, int x_2,int y_2)
    {
    int color=getcolor();
    int x1=x_1;
    int y1=y_1;
    int x2=x_2;
    int y2=y_2;
    if(x_1>x_2)
    {
    x1=x_2;
    y1=y_2;
    x2=x_1;
    y2=y_1;
    }
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);
    int inc_dec=((y2>=y1)?1:-1);
    if(dx>dy)
    {
    int two_dy=(2*dy);
    int two_dy_dx=(2*(dy-dx));
    int p=((2*dy)-dx);
    int x=x1;
    int y=y1;
    putpixel(x,y,color);
    while(x<x2)
    {
    x++;
    if(p<0)
    p+=two_dy;
    else
    {
    y+=inc_dec;
    p+=two_dy_dx;
    }
    putpixel(x,y,color);
    }
    }
    else
    {
    int two_dx=(2*dx);
    int two_dx_dy=(2*(dx-dy));
    int p=((2*dx)-dy);
    int x=x1;
    int y=y1;
    putpixel(x,y,color);
    while(y!=y2)
    {
        y+=inc_dec;
        if(p<0)
        p+=two_dx;
        else
        {x++;
        p+=two_dx_dy;
        }
        putpixel(x,y,color);
    }
    }
}


int main()
{
    int ch;
    cout<<"Enter the choice for 3D transformation:\n1.Bezier Curve\n2.Fractal Line";
    cout<<"\n\nChoice:";
    cin>>ch;
    int gd = DETECT, gm;
    int x[20], y[20]; // used to store x, y coordinate system
    int i,n;
    initgraph (&gd, &gm, " ");
    if(ch==1)
    {
    setbkcolor(BLACK);
    cout<<"\nEnter the number of control points:\n";
    cin>>n;
    cout<<"Enter the x- and y-coordinates of the  control points:\n";
    for (i=0; i<n; i++)
        cin>>x[i]>>y[i];
    bezier (x, y,n);// calling  function to fit the curve
    getch();
    closegraph();
    }
    else
   {
    int gd=DETECT,gm;
    long double x=0;
    long double y=0;
    long double l=0;
    long double angle=0;
    int n=0;
    cout<<"\nStarting point of the line:(x,y):";
    cout<<"\nEnter the value of x=:";
    cin>>x;
    cout<<"Enter the value of y=:";
    cin>>y;
    cout<<"Enter the value of line l:";
    cin>>l;
    cout<<"Angle of the line with x axis:";
    cin>>angle;
    cout<<"Enter the order of curve=n=";
    cin>>n;
    initgraph(&gd,&gm," ");
    setcolor(LIGHTGREEN);
    k_curve(x,y,l,angle,n);
    getch();
    closegraph();
    return 0;
   }
}



