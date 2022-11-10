#include <iostream>
#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;
void print_pixel(int x,int y,int x1,int y1)
{
    putpixel(x1+x,y1+y,WHITE);
    putpixel(x1+x,y1-y,WHITE);
    putpixel(x1-x,y1-y,WHITE);
    putpixel(x1-x,y1+y,WHITE);
}
void print_hyperbola_midpoint(int x1,int y1,int a,int b)
{
   int x,y;
   x=a,y=0;
   int d = b*b*(2*a+1)*(a+1/2) - 2*a*a -2*a*a*b*b;
   while(y<=b*b*x/(a*a))
   {
       print_pixel(x,y,x1,y1);
       if(d>0)
       {
           d-=2*a*a*(1+2*(y+1));
       }
       else
       {
           d+=b*b*(2+2*(2*x+1))-2*a*a*(1+2*(y+1)) ;
           x++;
       }
       y++;
   }
   int init = 100;
   while(init--)
   {
       if(d>0)
       {
           d+=2*b*b*(1+(2*x+1));
       }
       else
       {
           d+=2*b*b*(1+(2*x+1)) -2*a*a*(1+2*y+1);
           y++;
       }
       x++;
       print_pixel(x,y,x1,y1);
   }
}
void print_hyperbola_bresenham(int x1,int y1,int a,int b)
{
    int x,y;
    x=a,y=0;
    int d = 2*a*a-2*a*b*b-b*b;
    while(y<=b*b*x/(a*a))
    {
        print_pixel(x,y,x1,y1);
        if(d<0)
        {
            d+=2*a*a*(2*y+3);
        }
        else
        {
            d+=2*a*a*(2*y+3)-4*b*b*(x+1) ;
            x++;
        }
        y++;
    }
    int init = 100;
    while(init--)
    {
        if(d<0)
        {
            d+=2*b*b*(3+2*x);
        }
        else
        {
            d+=2*b*b*(3+2*x) -4*a*a*(y+1);
            y++;
        }
        x++;
        print_pixel(x,y,x1,y1);
    }
}
int main()
{
    int gm=DETECT,gd,i=0,x1,y1,a,b,c,d;
    float maj_axis,min_axis;
    initgraph(&gm,&gd,"C:\\TC\\BGI");
    while(i++<100)
    {
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,x1,y1);
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,a,b);
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,c,d);
        maj_axis=sqrt(pow((a-x1),2)+pow((b-y1),2));
        min_axis=sqrt(pow((c-x1),2)+pow((d-y1),2));
        print_hyperbola_midpoint(x1,y1,maj_axis,min_axis);
    }
    getch();
    closegraph();
    return 0;
}