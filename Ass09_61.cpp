#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<iostream>

using namespace std;

int maxx,maxy,midx,midy;

// function to create axes

void axis()
{
  getch();
  cleardevice();
  line(midx,0,midx,maxy);  // x-axis
  line(0,midy,maxx,midy);  // y-axis

}

main()
{
  int gd,gm,x,y,z,ang,x1,x2,y1,y2;
  int ch;
  detectgraph(&gd,&gm);
  initgraph(&gd,&gm,"");
  setfillstyle(5,14); // BKSLASH_FILL-5,YELLOW-14
  maxx=getmaxx();
  maxy=getmaxy();
  midx=maxx/2;
  midy=maxy/2;

  //display the original object

  outtextxy(100,20,"ORIGINAL OBJECT");
  line(midx,0,midx,maxy);
  line(0,midy,maxx,midy);
  bar3d(midx+100,midy-20,midx+60,midy-90,20,5);
  axis();
  cout<<"Enter the choice for 3D transformation:\n1.Translation\n2.Rotation about arbitrary axis";
  cout<<"\n\nChoice:";
  cin>>ch;
  if (ch == 1)
  {
      outtextxy(100,20,"TRANSLATION");
      cout<<"\n\nEnter the Translation vector: ";
      cin>>x>>y;
      bar3d(midx+100,midy-20,midx+60,midy-90,20,5);
      bar3d(midx+(x+100),midy-(y+20),midx+(x+60),midy-(y+90),20,5);
      axis();
  }
  else if (ch == 2)
  {
      outtextxy(100,20,"ROTATION");

      cout<<"\nEnter the choice for Rotation:\n1.Rotation about x-axis\n2.Rotation about y-axis\n3.Rotation about z-axis";
      cout<<"\n\nChoice:";
      cin>>ch;
      if (ch == 1)
      {
          cout<<"\nEnter the Rotation angle: ";
          cin>>ang;
          x1=100*cos(ang*3.14/180)-20*sin(ang*3.14/180);
          y1=100*sin(ang*3.14/180)+20*sin(ang*3.14/180);
          x2=60*cos(ang*3.14/180)-90*sin(ang*3.14/180);
          y2=60*sin(ang*3.14/180)+90*sin(ang*3.14/180);
          axis();
          cout<<"\nAfter rotating about x-axis\n";
          bar3d(midx+100,midy-20,midx+60,midy-90,20,5);
          bar3d(midx+100,midy-x1,midx+60,midy-x2,20,5);
          axis();
      }
      else if (ch == 2)
      {
          cout<<"\nEnter the Rotation angle: ";
          cin>>ang;
          x1=100*cos(ang*3.14/180)-20*sin(ang*3.14/180);
          y1=100*sin(ang*3.14/180)+20*sin(ang*3.14/180);
          x2=60*cos(ang*3.14/180)-90*sin(ang*3.14/180);
          y2=60*sin(ang*3.14/180)+90*sin(ang*3.14/180);
          axis();
          cout<<"\nAfter rotating about y-axis\n";
          bar3d(midx+100,midy-20,midx+60,midy-90,20,5);
          bar3d(midx+x1,midy-20,midx+x2,midy-90,20,5);
          axis();
      }
      else if (ch == 3)
      {
          cout<<"\nEnter the Rotation angle: ";
          cin>>ang;
          x1=100*cos(ang*3.14/180)-20*sin(ang*3.14/180);
          y1=100*sin(ang*3.14/180)+20*sin(ang*3.14/180);
          x2=60*cos(ang*3.14/180)-90*sin(ang*3.14/180);
          y2=60*sin(ang*3.14/180)+90*sin(ang*3.14/180);
          axis();
          cout<<"\nAfter rotating about z-axis\n";
          bar3d(midx+100,midy-20,midx+60,midy-90,20,5);
          bar3d(midx+x1,midy-y1,midx+x2,midy-y2,20,5);
          line(0,0,maxx,maxy);
          axis();
      }
      else
      {
          cout<<"Enter a valid choice!";
      }
   }
  else
  {
      cout<<"Enter a valid choice!";
  }
  getch();
  closegraph();
}
