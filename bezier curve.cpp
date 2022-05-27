#include<iostream>
#include<conio.h>
#include<stdio.h>>
#include<graphics.h>
#include<math.h>

using namespace std;

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

int main()
{
    int gd = DETECT, gm;
    int x[20], y[20]; // used to store x, y coordinate system
    int i,n;
    initgraph (&gd, &gm, " ");
    setbkcolor(BLACK);
    cout<<"Enter the number of control points:\n";
    cin>>n;
    cout<<"Enter the x- and y-coordinates of the  control points:\n";
    for (i=0; i<n; i++)
        cin>>x[i]>>y[i];
    bezier (x, y,n);    // calling  function to fit the curve
    getch();
    closegraph();
}
