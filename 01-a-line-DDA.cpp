#include <stdio.h>
#include <conio.h>
#include <graphics.h>
int main()
{
    int x, y, x1, x2, y1, y2, k, dx, dy, s, xi, yi;
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
    printf("enter first point ");
    scanf("%d%d", &x1, &y1);
    printf("enter second point ");
    scanf("%d%d", &x2, &y2);
    x = x1;
    y = y1;
    putpixel(x, y, 7);
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
        s = abs(dx);
    else
        s = abs(dy);
    xi = dx / s;
    yi = dy / s;
    x = x1;
    y = y1;
    putpixel(x, y, 7);
    for (k = 0; k < s; k++)
    {
        x = x + xi;
        y = y + yi;
        putpixel(x, y, 7);
    }
    getch();
    closegraph();
}
