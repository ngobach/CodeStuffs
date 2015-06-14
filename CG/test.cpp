
#include <graphics.h>
#include<math.h>
#define Round(a) int(a+0.5)
#define DELAY 10
int color=GREEN;
void put4pixel(int xc,int yc, int x,int y)//,int t1,int t2)
{
    //int x0,y0;
    putpixel(x+xc,y+yc,color);
    putpixel(x+xc,-y+yc,color);
    putpixel(-x+xc,-y+yc,color);
    putpixel(-x+xc,y+yc,color);
}
void MidpointEllipse(int xc,int yc,int rx,int ry)
{
    int x=0,y=ry;
    float p1,p2,t1,t2;
    int k;
    p1=ry*ry-rx*rx*ry+0.25*rx*rx;
    put4pixel(xc,yc,x,y);
    for(k=0;(2*ry*ry*x)<=(2*rx*rx*y);k++)
    {
        t1=2*ry*ry*x+2*ry*ry;
        t2=2*rx*rx*y-2*rx*rx;
        if(p1<0)
        p1=p1+t1+ry*ry;
        else
        {
            p1=p1+t1-t2+ry*ry;
            y--;
        }
        x++;
        put4pixel(xc,yc,x,y);

    }
    p2=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
    put4pixel(xc,yc,x,y);
    for(k=0;y>=0;k++)
    {
        t1=2*ry*ry*x+2*ry*ry;
        t2=2*rx*rx*y-2*rx*rx;
        if(p2>0)
        p2=p2-t2+rx*rx;
        else
        {
            p2=p2+t1-t2+rx*rx;
            x++;
        }
        y--;
        put4pixel(xc,yc,x,y);

    }
}
int  main()
{
    int gd=DETECT,gm,r;
    initgraph(&gd,&gm,"d:\\tc\\bgi");
    //printf("Ban kinh duong tron:");scanf("%d",&r);
    //ellipse(100,100,0,360,100,50);
    MidpointEllipse(200,200,100,40);

    //circle(100,100,100);
    //line(50,50,350,300);
    getch();
    closegraph();
}
