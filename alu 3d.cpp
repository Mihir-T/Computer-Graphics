#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<iostream>

using namespace std;

int maxx,maxy,midx,midy;

void axis()
{
  getch();
  cleardevice();
  line(midx,0,midx,maxy);
  line(0,midy,maxx,midy);
}

main()
{
  int gd,gm,x,y,z,ang,x1,x2,y1,y2;
  detectgraph(&gd,&gm);
  initgraph(&gd,&gm,"");
  setfillstyle(6,15);
  maxx=getmaxx();
  maxy=getmaxy();
  midx=maxx/2;
  midy=maxy/2;
  outtextxy(100,100,"ORIGINAL OBJECT");
  line(midx,0,midx,maxy);
  line(0,midy,maxx,midy);
  bar3d(midx+100,midy-20,midx+60,midy-90,20,5);
  axis();
  outtextxy(100,20,"SCALING");
  cout<<"\n Enter the Scaling Factor: ";
  cin>>x>>y>>z;
  bar3d(midx+100,midy-20,midx+60,midy-90,20,5);
  bar3d(midx+(x*100),midy-(y*20),midx+(x*60),midy-(y*90),20*z,5);
  axis();
  outtextxy(100,20,"ROTATION");
  cout<<"\n Enter the Rotation angle: ";
  cin>>ang;
  x1=100*cos(ang*3.14/180)-20*sin(ang*3.14/180);
  y1=100*sin(ang*3.14/180)+20*sin(ang*3.14/180);
  x2=60*cos(ang*3.14/180)-90*sin(ang*3.14/180);
  y2=60*sin(ang*3.14/180)+90*sin(ang*3.14/180);
  axis();
  cout<<"\n After rotating about z-axis\n";
  bar3d(midx+100,midy-20,midx+60,midy-90,20,5);
  bar3d(midx+x1,midy-y1,midx+x2,midy-y2,20,5);
  axis();
  cout<<"\n After rotating about x-axis\n";
  bar3d(midx+100,midy-20,midx+60,midy-90,20,5);
  bar3d(midx+100,midy-x1,midx+60,midy-x2,20,5);
  axis();
  cout<<"\n After rotating about y-axis\n";
  bar3d(midx+100,midy-20,midx+60,midy-90,20,5);
  bar3d(midx+x1,midy-20,midx+x2,midy-90,20,5);
  axis();
  closegraph();
}
