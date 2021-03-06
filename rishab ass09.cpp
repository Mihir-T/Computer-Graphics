 # include <iostream>
 # include <graphics.h>
 # include    <conio.h>
 # include     <math.h>


 # define  f                 0.3
 # define  projection_angle   45

 using namespace std;

 int x,y,z,midx,midy,maxx,maxy;

 void show_screen( );

 void apply_yz_reflection(int[5][3]);
 int multiply_matrices(const float[4],const float[4][4],float[4]);

 void draw_pyramid(const int [5][3]);
 void get_projected_point(int&,int&,int&);

 void Line(const int,const int,const int,const int);

 void apply_yz_reflection(int edge_points[5][3])
    {
        for(int count=0;count<5;count++)
      {
         float matrix_a[4]={
         edge_points[count][0],
         edge_points[count][1],
         edge_points[count][2],
         edge_points[count][3]};
         float matrix_b[4][4]={
                    { -1,0,0,0 } ,
                    { 0,1,0,0 } ,
                    { 0,0,1,0 } ,
                    { 0,0,0,1 }
                  };

         float matrix_c[4]={0};

         multiply_matrices(matrix_a,matrix_b,matrix_c);

         edge_points[count][0]=(int)(matrix_c[0]+0.5+640);
         edge_points[count][1]=(int)(matrix_c[1]+0.5);
         edge_points[count][2]=(int)(matrix_c[2]+0.5);
      }
    }
        int multiply_matrices(const float matrix_1[4],const float matrix_2[4][4],float matrix_3[4])
        {

    {
       for(int count_1=0;count_1<4;count_1++)
      {
         for(int count_2=0;count_2<4;count_2++)
        matrix_3[count_1]+=
               (matrix_1[count_2]*matrix_2[count_2][count_1]);
      }
    }
        }
    void draw_pyramid(const int points[5][3])
    {
       int edge_points[5][3];

       for(int i=0;i<5;i++)
      {
         edge_points[i][0]=points[i][0];
         edge_points[i][1]=points[i][1];
         edge_points[i][2]=points[i][2];

         get_projected_point(edge_points[i][0],
                    edge_points[i][1],edge_points[i][2]);
      }

       Line(edge_points[0][0],edge_points[0][1],
                      edge_points[1][0],edge_points[1][1]);
       Line(edge_points[1][0],edge_points[1][1],
                      edge_points[2][0],edge_points[2][1]);
       Line(edge_points[2][0],edge_points[2][1],
                      edge_points[3][0],edge_points[3][1]);
       Line(edge_points[3][0],edge_points[3][1],
                      edge_points[0][0],edge_points[0][1]);

       Line(edge_points[0][0],edge_points[0][1],
                      edge_points[4][0],edge_points[4][1]);
       Line(edge_points[1][0],edge_points[1][1],
                      edge_points[4][0],edge_points[4][1]);
       Line(edge_points[2][0],edge_points[2][1],
                      edge_points[4][0],edge_points[4][1]);
       Line(edge_points[3][0],edge_points[3][1],
                      edge_points[4][0],edge_points[4][1]);
    }

   void get_projected_point(int &x,int &y,int &z)
    {

       float fcos0=(f*cos(projection_angle*(M_PI/180)));
       float fsin0=(f*sin(projection_angle*(M_PI/180)));

       float Par_v[4][4]={
                {1,0,0,0},
                {0,1,0,0},
                {fcos0,fsin0,0,0},
                {0,0,0,1}
             };

       float xy[4]={x,y,z,1};
       float new_xy[4]={0};

       multiply_matrices(xy,Par_v,new_xy);

       x=(int)(new_xy[0]+0.5);
       y=(int)(new_xy[1]+0.5);
       z=(int)(new_xy[2]+0.5);
    }

    void Line(const int x_1,const int y_1,const int x_2,const int y_2)
    {

       int color=getcolor( );

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
              {
             x++;
             p+=two_dx_dy;
              }

           putpixel(x,y,color);
        }
      }
    }

    void show_screen( )
    {

     setcolor(11);
       outtextxy(200,29,"3D Reflection along yz-plane");

     setcolor(15);
    }

void axis()
{
  getch();
  cleardevice();
  line(midx,0,midx,maxy);
  line(0,midy,maxx,midy);

}

 int main( )
    {
       int c;
       int driver=VGA;
       int mode=VGAHI;

       initgraph(&driver,&mode,"..\\Bgi");
       cout<<"Enter the choice for 3D transformation:\n1.Reflection about YZ plane\n2.Scaling";
       cout<<"\n\nChoice:";
       cin>>c;
       if (c==1)
    {
       show_screen( );

       int pyramid[5][3]={
                {170,300,50},      //  base front left
                {270,300,50},      //  base front right
                {270,300,-50},     //  base back right
                {170,300,-50},     //  base back left
                {200,150,0}        //  top
             };

      setcolor(15);
     draw_pyramid(pyramid);

       setcolor(15);



       apply_yz_reflection(pyramid);

       getch( );

       setcolor(10);
     draw_pyramid(pyramid);

       getch( );
       closegraph();
       return 0;
    }
  else
  {
  setfillstyle(5,14);
  maxx=getmaxx();
  maxy=getmaxy(); // BKSLASH_FILL-5,YELLOW-14
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
  }
}
