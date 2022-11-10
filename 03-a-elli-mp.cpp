#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;


void ellips(int x, int y)
{
    putpixel(x + 200, y + 200, 8);
    putpixel(-x + 200, y + 200, 8);
    putpixel(x + 200, -y + 200, 8);
    putpixel(-x + 200, -y + 200, 8);
}


void midptellipse(int rx, int ry,
				int xc= 0, int yc= 0)
{
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;

	// Initial decision parameter of region 1
	d1 = (ry * ry) - (rx * rx * ry) +
					(0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;

	// For region 1
	while (dx < dy)
	{

		// Print points based on 4-way symmetry
		ellips(x,y);
		// Checking and updating value of
		// decision parameter based on algorithm
		if (d1 < 0)
		{
			x++;
			dx = dx + (2 * ry * ry);
			d1 = d1 + dx + (ry * ry);
		}
		else
		{
			x++;
			y--;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d1 = d1 + dx - dy + (ry * ry);
		}
	}

	// Decision parameter of region 2
	d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
		((rx * rx) * ((y - 1) * (y - 1))) -
		(rx * rx * ry * ry);

	// Plotting points of region 2
	while (y >= 0)
	{

		// Print points based on 4-way symmetry
		ellips(x,y);

		// Checking and updating parameter
		// value based on algorithm
		if (d2 > 0)
		{
			y--;
			dy = dy - (2 * rx * rx);
			d2 = d2 + (rx * rx) - dy;
		}
		else
		{
			y--;
			x++;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d2 = d2 + dx - dy + (rx * rx);
		}
	}
}

// Driver code
int main()
{
    int gdriver = DETECT, gmode, a, b;
    initgraph(&gdriver, &gmode, "C:\\tc\\bgi::");
    printf("\n enter the length of major axis:");
    scanf("\t%d", &a);
    printf("\n enter the length of minor axis:");
    scanf("\t%d", &b);

	midptellipse(a,b);

    getch();
    closegraph();
	return 0;
}
