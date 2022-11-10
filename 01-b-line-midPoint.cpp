#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int x, y, x1, x2, y1, y2;
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
    printf("enter first point ");
    scanf("%d%d", &x1, &y1);
    printf("enter second point ");
    scanf("%d%d", &x2, &y2);
    
    int dx = x2 - x1;
        int dy = y2 - y1;
        if(dy<=dx){
        int d = dy - (dx/2);
        int x = x1, y = y1;
        // cout << x << "," << y << "\n";
    
        while (x < x2)
        {
            x++;
            if (d < 0)
                d = d + dy;
            {
                d += (dy - dx);
                y++;
            }
            putpixel(x, y, 7);

               // cout << x << "," << y << "\n";
        }
        }
    
    else if(dx<dy)
    {
        int d = dx - (dy/2);
        int x = x1, y = y1;
        cout << x << "," << y << "\n"; 
        while (y < y2)
        {
            y++;
    
            if (d < 0)
                d = d + dx;
            else
            {
                d += (dx - dy);
                x++;
            }
            putpixel(x, y, 7);

            // cout << x << "," << y << "\n";
        }
    }

    getch();
    closegraph();
}
