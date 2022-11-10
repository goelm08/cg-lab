#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

using namespace std;
void PlotEllipse(float, float, float, float);

class Ellipse
{
    float a, b, xc = 0, yc = 0, x, y, h, v, k;

public:
    void getdata()
    {
        cout << "Enter the value of a: ";
        cin >> a;
        cout << "Enter the value of b: ";
        cin >> b;
    };
    void plot()
    {
        xc = getmaxx() / 2;
        yc = getmaxy() / 2;
        line(0, yc, xc * 2, yc);
        line(xc, 0, xc, yc * 2);
        for (k = 0; k < 360; k++)
        {
            h = a * cos((k * 3.14) / 180);
            v = b * sin((k * 3.14) / 180);
            x = h;
            y = v;
            PlotEllipse(xc, yc, x, y);
        }
    };
};

int main()
{
    Ellipse e;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TC/BGI");
    cleardevice();
    gotoxy(2, 2);
    e.getdata();
    settextstyle(2, 0, 8);
    outtextxy(325, 5, "ELLIPSE");
    e.plot();
    getch();
    closegraph();
}

void PlotEllipse(float xc, float yc, float x, float y)
{
    int i, j;
    long a1, a2;
    getaspectratio(&i, &j);
    a1 = (long)x * (long)j / long(i);
    a2 = a1;
    putpixel(xc + a2, yc + y, 15);
    putpixel(xc - a2, yc + y, 15);
    putpixel(xc + a2, yc - y, 15);
    putpixel(xc - a2, yc - y, 15);
}