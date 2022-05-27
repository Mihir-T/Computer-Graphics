#include<iostream>
#include<conio.h>
#include<graphics.h>

using namespace std;

float x[20],y[20],n;

void dda(int n)
{
    int X,Y,dx,dy,s,j,k,a=0,i=0;
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

void newcoordinate(float s[][3], float p[][1])
{
	float temp[3][1] = { 0 };
    int i,j,k;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 3; k++)
				temp[i][j] += (s[i][k] * p[k][j]);

	p[0][0] = temp[0][0];
	p[1][0] = temp[1][0];
	p[2][0] = temp[2][0];
}

void scale(float x[], float y[], float sx, float sy)
{
	float s[3][3] = {sx,0,0,0,sy,0,1,1,1};
	float p[3][1];

	for (int i = 0; i < 3; i++)
	{
		p[0][0] = x[i];
		p[1][0] = y[i];

		newcoordinate(s,p);

		x[i] = p[0][0];
		y[i] = p[1][0];
	}
}

void reflectx()
{
    int x1[3],y1[3],rx1[3],ry1[3];
    int i;

    cout<<"Enter the points\n";
    for(i=0;i<3;i++){
        cin>>x1[i];
        cin>>y1[i];
    }

    int maxx = getmaxx();
    int maxy = getmaxy();
    cout<<"\n max x="<<maxx;
    cout<<"\n max y="<<maxy;

    int midx = maxx/2;
    int midy=maxy/2;

    for(i=0;i<3;i++){
        x1[i] = midx+x1[i];

        if(y1[i]<0){
            y1[i]=-y1[i];
            y1[i]+=midy;
        }
        else
            y1[i]=midy - y1[i];

    }
    cout<<"\n mid x="<<midx;
    cout<<"\n mid y="<<midy;

    line(midx,0,midx,maxy);
    line(0,midy,maxx,midy);

    line(x1[0],y1[0],x1[1],y1[1]);
    line(x1[1],y1[1],x1[2],y1[2]);
    line(x1[2],y1[2],x1[0],y1[0]);

    int diffy;
    for(i=0;i<3;i++){
        if(y1[i]>midy){
            diffy = y1[i]-midy;
            ry1[i]=midy-diffy;
        }
        if(y1[i]<midy){
            diffy = midy-y1[i];
            ry1[i]=midy+diffy;
        }
    }

    int diff;
    for(i=0;i<3;i++){
        if(x1[i]>midx){
            diff = x1[i]-midx;
            rx1[i]=midx-diff;
        }
        if(x1[i]<midx){
            diff = midx-x1[i];
            rx1[i]=midx+diff;
        }
    }

    outtextxy(x1[2],y1[2]-5,"Before");

    line(rx1[0],ry1[0],rx1[1],ry1[1]);
    line(rx1[1],ry1[1],rx1[2],ry1[2]);
    line(rx1[2],ry1[2],rx1[0],ry1[0]);

    getch();
}

int main()
{
	int gd = DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	int i,c,ch;
	float sx,sy;

    cout<<"Enter 1 to scale and 2 to reflect:";
    cin>>ch;
    if(ch==1){
    cout<<"\n1.Scaling";

	cout<<"\nEnter the Number of Vertices : ";
    cin>>n;
    cout<<"\nEnter the Co ordinates of points : ";
    for(i=0;i<n;i++)
    {
        cout<<"\npoint "<<i+1<<" :\nx : ";
        cin>>x[i];
        cout<<"\ny : ";
        cin>>y[i];
    }
    dda(n);
    cout<<"\nEnter Scaling Factor : \nx : ";
    cin>>sx;
    cout<<"\ny : ";
    cin>>sy;
    scale(x,y,sx,sy);
    dda(n);
    scale(x,y,1/sx,1/sy);

}
if(ch ==2){
    cout<<"\n\n";
    reflectx();
}

	getch();
	return 0;
}

