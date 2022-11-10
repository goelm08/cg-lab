#include <iostream>
#include <graphics.h>
typedef struct point point;
using namespace std;
double xmax,ymax,xmin,ymin;
struct point{
  double x,y;
};
void dda_line(double x1,double y1,double x2,double y2);
int gencode(point p)
{
    int code=0;
    if(p.x<xmin)
    {
      code=code|(1);
    }
     if(p.x>xmax)
    {
      code=(code)|(1<<1);
    }
    if(p.y>ymax)
    {
        code=code|(1<<2);
    }
     if(p.y<ymin)
    {
        code=code|(1<<3);
    }
    return code;
}
point getpoint(point a,double m,int code)
{
    point p;
    if((code&1)==1)
    {  //left edge
        p.x=xmin;
        p.y=a.y+(p.x-a.x)*m;
    }
    else if((code&(2)))
    {
        //right
        p.x=xmax;
        p.y=a.y+(p.x-a.x)*m;
    }
    else if((code&(4)))
    {   //top edge
        p.y=ymax;
        p.x=a.x+(p.y-a.y)/m;
    }
    else if((code&(8)))
    {  //bottom
        p.y=ymin;
        p.x=a.x+(p.y-a.y)/m;
    }
   return p;
}
void clip(point a,point b)
{   double m=(b.y-a.y)/(b.x-a.x);
    int done=0,flag=0,code1=0,code2=0;
    do{
       code1=gencode(a);
       code2=gencode(b);
       if(code1==0&&code2==0)
       {
           done=1;flag=1;
       }
       else if(code1&code2)
           done=1;
       else
       {  //if code is non zero then only we will clip else we will not clip our line
           if(code1)
                a=getpoint(a,m,code1);
            if(code2)
                b=getpoint(b,m,code2);
       }
    }while(!done);
    if(flag==1)
    {
        setcolor(5);
        dda_line(a.x,a.y,b.x,b.y);
    }
}
int main()
{
    int gm=DETECT,gd;
    initgraph(&gm,&gd,"C:\\TC\\BGI");
    xmax=400;   xmin=150;  ymax=300;  ymin=150;
    dda_line(xmin,ymin,xmax,ymin);
    dda_line(xmin,ymin,xmin,ymax);
    dda_line(xmin,ymax,xmax,ymax);
    dda_line(xmax,ymin,xmax,ymax);
    point a,b;
    a.x=150;a.y=50;b.x=400;b.y=320;
    dda_line(a.x,a.y,b.x,b.y);
    getch();
    cleardevice();
    clip(a,b);
    dda_line(xmin,ymin,xmax,ymin);
    dda_line(xmin,ymin,xmin,ymax);
    dda_line(xmin,ymax,xmax,ymax);
    dda_line(xmax,ymin,xmax,ymax);
    getch();
    closegraph();
    return 0;
}
void dda_line(double x1,double y1,double x2,double y2)
{

    double dy=y2-y1,dx=x2-x1;
    double m=dy/dx;
    if(x1<=x2&&y1<=y2)    // 4th quad
    {
        if(abs(dy)<abs(dx))
        {
            while(x1<=x2)
            {
                putpixel(x1,y1,WHITE);
                y1+=m;
                x1++;
            }
        }
        else
        {
            while(y1<=y2)
            {
                putpixel(x1,y1,WHITE);
                x1+=1/m;
                y1++;
            }
        }

    }
    else if(x1<=x2&&y1>=y2)
    {
        if(abs(dy)<abs(dx))
        {
            while(x1<=x2)
            {
                putpixel(x1,y1,WHITE);
                y1+=m;
                x1++;
            }
        }
        else
        {
            while(y1>=y2)
            {
                putpixel(x1,y1,WHITE);
                x1-=1/m;
                y1--;
            }
        }
    }
    else if(x1>=x2&&y1<=y2)
    {
        if(abs(dy)<abs(dx))
        {
            while(x1>=x2)
            {
                putpixel(x1,y1,WHITE);
                y1-=m;
                x1--;
            }
        }
        else
        {
            while(y1<=y2)
            {
                putpixel(x1,y1,WHITE);
                x1+=1/m;
                y1++;
            }
        }
    }
    else
    {
        if(abs(dy)<abs(dx))
        {
            while(x1>=x2)
            {
                putpixel(x1,y1,WHITE);
                y1-=m;
                x1--;
            }
        }
        else
        {
            while(y1>=y2)
            {
                putpixel(x1,y1,WHITE);
                x1-=1/m;
                y1--;
            }
        }
    }
}