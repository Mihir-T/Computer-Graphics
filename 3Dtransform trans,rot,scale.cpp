#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<iostream>

using namespace std;

int maxx,maxy,midx,midy;

// function to create axes
//z axis:->line(midx,midy,0,0); line(maxy,maxx,midy,0); line(0,maxy,midx,midy);  line(maxx,maxy,midx,midy); line(0,0,maxx,maxy);

void axis()
{
  getch();
  cleardevice();
  line(midx,0,midx,maxy);
  line(0,midy,maxx,midy);
  line(0,0,maxx,maxy);

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
  bar3d(midx+40,midy-90,midx+70,midy-50,20,5);
  /*axis();
  outtextxy(100,20,"TRANSLATION");
  cout<<"\n\n Enter the Translation vector: ";
  cin>>x>>y;
  bar3d(midx+40,midy-90,midx+70,midy-50,20,5);
  bar3d(midx+(x+40),midy-(y+90),midx+(x+70),midy-(y+50),20,5);
  axis();
  outtextxy(100,20,"SCALING");
  cout<<"\n Enter the Scaling Factor: ";
  cin>>x>>y>>z;
  bar3d(midx+40,midy-90,midx+70,midy-50,20,5);
  bar3d(midx+(x*40),midy-(y*90),midx+(x*70),midy-(y*50),20*z,5);*/
  axis();
  outtextxy(100,20,"ROTATION");
  cout<<"\n Enter the Rotation angle: ";
  cin>>ang;
  x1=40*cos(ang*3.14/180)-90*sin(ang*3.14/180);
  y1=40*sin(ang*3.14/180)+90*sin(ang*3.14/180);
  x2=70*cos(ang*3.14/180)-50*sin(ang*3.14/180);
  y2=70*sin(ang*3.14/180)+50*sin(ang*3.14/180);
  axis();
  cout<<"\n After rotating about x-axis\n";
  bar3d(midx+40,midy-90,midx+70,midy-50,20,5);
  bar3d(midx+40,midy-x1,midx+70,midy-x2,20,5);
  axis();
  cout<<"\n After rotating about y-axis\n";
  bar3d(midx+40,midy-90,midx+70,midy-50,20,5);
  bar3d(midx+x1,midy-90,midx+x2,midy-50,20,5);
  axis();
  cout<<"\n After rotating about z-axis\n";
  bar3d(midx+40,midy-90,midx+70,midy-50,20,5);
  bar3d(midx+x1,midy-y1,midx+x2,midy-y2,20,5);
  axis();
  closegraph();
}
