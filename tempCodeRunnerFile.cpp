#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
void ellips(int x, int y);
void completellipse(int r, int g, int u, int v)
{
    float s, k, e, f, x;
    double p1, p2;
    s = r;
    k = g;
    e = (pow((s + .5), 2));
    f = (pow((k - 1), 2));
    p2 = ((u * e) + (v * f) - (u * v));
    ellips(s, k);
    while (k >= 0)
    {
        if (p2 > 0)
            p2 = (p2 + v - (2 * v * s));
        else
        {
            p2 = (p2 + (2 * u * (s + 1)) - (2 * v * (k - 1)) + v);
            s++;
        }
        k--;
        ellips(s, k);
    }
}
void main()
{
    int gdriver = DETECT, gmode;
    int a, b, x, y;
    long u, v, p1;
    initgraph(&gdriver, &gmode, "C:\\tc\\bgi::");
    printf("\n enter the length of major axis:");
    scanf("\t%d", &a);
    printf("\n enter the length of minor axis:");
    scanf("\t%d", &b);
    x = 0;
    y = b;
    u = pow(b, 2);
    v = pow(a, 2);
    p1 = (u - (v * b) + (.25 * v));
    ellips(x, y);
    while (2 * (u * x) <= 2 * (v * y))
    {
        x++;
        if (p1 < 0)
            p1 = (p1 + (2 * u * v) + v);
        else
        {
            p1 = (p1 + (2 * u * x) - (2 * v * y) + u);
            y--;
        }
        ellips(x, y);
    }
    completellipse(x, y, u, v);
    getch();
    closegraph();
}
void ellips(int x, int y)
{
    putpixel(x + 200, y + 200, 8);
    putpixel(-x + 200, y + 200, 8);
    putpixel(x + 200, -y + 200, 8);
    putpixel(-x + 200, -y + 200, 8);
}
