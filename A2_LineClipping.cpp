/* Write C++ program to implement Cohen Southerland line clipping algorithm.*/

#include <iostream>
#include <graphics.h>
#include <math.h>
#include <cstdlib>
using namespace std;

static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8, xmin, ymin, xmax, ymax;

int getcode(int x, int y)
{
    int code = 0;
    if (y > ymax)
        code |= BOTTOM;
    if (y < ymin)
        code |= TOP;
    if (x < xmin)
        code |= LEFT;
    if (x > xmax)
        code |= RIGHT;
    return code;
}

int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);
    setcolor(WHITE);
    cout << "Enter top left and bottom right co-ordinates of window: ";
    cin >> xmin >> ymin >> xmax >> ymax;
    int x1, y1, x2, y2;
    cout << "Enter the endpoints of the line: ";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Before clipping";
    rectangle(xmin, ymin, xmax, ymax);
    line(x1, y1, x2, y2);

    delay(10000);

    int outcode1 = getcode(x1, y1);
    int outcode2 = getcode(x2, y2);
    int accept = 0; 
    while (1)
    {
        float m = (float)(y2 - y1) / (x2 - x1);
        if (outcode1 == 0 && outcode2 == 0)
        {
            accept = 1;
            break;
        }
        else if ((outcode1 & outcode2) != 0)
        {
            break;
        }
        else
        {
            int x, y;
            int temp;
            if (outcode1 == 0)
                temp = outcode2;
            else
                temp = outcode1;

            if (temp & TOP)
            {
                x = x1 + (ymin - y1) / m;
                y = ymin;
            }
            else if (temp & BOTTOM)
            { 
                x = x1 + (ymax - y1) / m;
                y = ymax;
            }
            else if (temp & LEFT)
            {
                x = xmin;
                y = y1 + m * (xmin - x1);
            }
            else if (temp & RIGHT)
            {
                x = xmax;
                y = y1 + m * (xmax - x1);
            }

            if (temp == outcode1)
            {
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2, y2);
            }
        }
    }

    setcolor(YELLOW);
    if (accept)
    {
        cleardevice();
        cout << "After clipping";
        rectangle(xmin, ymin, xmax, ymax);
        line(x1, y1, x2, y2);
    }
    else
    {
        cleardevice();
        cout << "After clipping";
        rectangle(xmin, ymin, xmax, ymax);
    }
    getch();
    closegraph();
}

//50 100
//150 300
//20 50
//100 200
