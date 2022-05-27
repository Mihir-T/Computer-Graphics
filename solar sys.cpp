#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<random>
#include<stdio.h>

//-------------------------------  Planet  ------------------------------//
using namespace std;
class Planet
{
private:
    int x;
    int y;
    int rx;
    int ry;
    int color;
    int radius;
    int position;

    float displacement;
    char* Buffer;

public:
    Planet( )
    {
        x=y=rx=ry=radius=0;
    }
    ~Planet( )
    {
        delete Buffer;
    }
    Planet(const int,const int,const int,const float,int);

    void Show( );
    void Move( );
    void ShowOrbit( );
    void GetNextPosition( );
};
//-----------------------------  Planet( )  -----------------------------//
Planet::Planet(const int _rx,const int _ry,const int _radius,
               const float _displacement, int colour)
{
    rx=_rx;
    ry=_ry;

    x=(319+rx);
    y=240;

    radius=_radius;
    displacement=_displacement;
    position=0;
    color=colour;
}
//----------------------------  ShowOrbit( )  ---------------------------//
void Planet::ShowOrbit( )
{
    setcolor(7);
    ellipse(320,240,0,360,rx,ry);
}
//--------------------------------  Show( )  ----------------------------//
void Planet::Show( )
{
    Buffer=new char[imagesize((x-(radius+3)),(y-(radius+3)),
                              (x+radius+3),(y+radius+3))];

    getimage((x-(radius+3)),(y-(radius+3)),(x+radius+3),(y+radius+3),Buffer);
    setcolor(color);
    setfillstyle(1,color);


    setcolor(11);
    circle(x,y,radius);
}
//--------------------------------  Move  -------------------------------//
void Planet::Move( )
{
    putimage((x-(radius+3)),(y-(radius+3)),Buffer,3);

    delete Buffer;

    GetNextPosition( );
    Show();
    setcolor(color);
    setfillstyle(1,color);
    pieslice(x,y,0,360,radius);

    setcolor(color);
    circle(x,y,radius);
}
//-------------------------  GetNextPosition( )  ------------------------//
void Planet::GetNextPosition( )
{
    float angle=(displacement*position);

    x=(rx*cosl(angle)+319);
    y=(ry*sinl(angle)+240);



    position++;
}
//----------------------------main()------------------------------------//
int main( )
{
    int gd=DETECT,gm;

    initgraph(&gd,&gm,"");

    setlinestyle(0,0,3);

    setcolor(7);
    rectangle(0,0,getmaxx( ),getmaxy( ));

    setlinestyle(0,0,0);

    for(int count=0; count<5000; count++)
        putpixel((rand()*640),(rand()*480),(rand()*15));

    settextstyle(8,0,2);
    setcolor(11);
    outtextxy(15,10,"Solar");

    setcolor(12);
    outtextxy(72,20,"System");

    setcolor(11);

    setcolor(14);
    setfillstyle(1,14);
    pieslice(320,240,0,360,20);

    setcolor(12);
    circle(320,240,20);

    setcolor(4);
    circle(320,240,21);

    Planet Mercury(50,30,5,0.0175,9868950);
    Planet Venus(80,55,9,0.0155,3289730);
    Planet Earth(110,80,8,0.0135,15785639);
    Planet Mars(140,105,7,0.0115,3286972);
    Planet Jupiter(170,130,14,0.0095,3314175);
    Planet Saturn(200,155,12,0.0075,4638975);
    Planet Uranus(230,180,10,0.0055,15192143);
    Planet Neptune(260,205,8,0.0035,12211263);
    Planet Pluto(290,230,4,0.0025,8);

    Mercury.ShowOrbit( );
    Mercury.Show( );

    Venus.ShowOrbit( );
    Venus.Show( );

    Earth.ShowOrbit( );
    Earth.Show( );

    Mars.ShowOrbit( );
    Mars.Show( );

    Jupiter.ShowOrbit( );
    Jupiter.Show( );

    Saturn.ShowOrbit( );
    Saturn.Show( );

    Uranus.ShowOrbit( );
    Uranus.Show( );

    Neptune.ShowOrbit( );
    Neptune.Show( );

    Pluto.ShowOrbit( );
    Pluto.Show( );

    do
    {
        delay(25);
        Mercury.Move( );
        Venus.Move( );
        Earth.Move( );
        Mars.Move( );
        Jupiter.Move( );
        Saturn.Move( );
        Uranus.Move( );
        Neptune.Move( );
        Pluto.Move( );
    }
    while(1);

    getch( );
    closegraph( );
}
