/* a) Write C++ program to draw the following pattern. Use DDA line and Bresenham's circle drawing algorithm. Apply the concept of encapsulation.*/



#include<iostream>
#include<graphics.h>
using namespace std;

void dda(int x1,int y1,int x2,int y2)
{
	float dx,dy,len,x,y;
	float xic,yic;
	 int i=1;
	
	x=x1;
	y=y1;
	putpixel(x,y,RED);
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(dx>dy)
	{
	len=dx;
	}
	else
	{
	len=dy;
	}
	xic=(x2-x1)/len;
	yic=(y2-y1)/len;
	
	
	while(i<=len)
	{
		
		
		putpixel(x,y,RED);
		x=x+xic;
		y=y+yic;
		i++;
	}
}

void bresc(int centx,int centy,int r)
{
	int p,x,y;
	x=0;
	y=r;
	p=3-(2*r);
	do
	{
		putpixel(centx+x,centy-y,1);
		putpixel(centx-x,centy-y,2);
		putpixel(centx-x,centy+y,3);
		putpixel(centx+x,centy+y,4);
		
		putpixel(centx+y,centy+x,5);
		putpixel(centx+y,centy-x,6);
		putpixel(centx-y,centy+x,7);
		putpixel(centx-y,centy-x,8);
		if(p<0)
		{
			p=p+(4*x)+6;
		}	
		else
		{
			p=p+(4*(x-y)+10);
			y=y-1;		
		}	
		x=x+1;
			

	}while(x<y);

	
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);	
	int r,centx,centy;
	
	cout<<"Enter x-coordinate of center";
	cin>>centx;	
	
	cout<<"Enter y-coordinate of center";
	cin>>centy;	
	
	cout<<"Enter the radius of outer circle";
	cin>>r;
	
	bresc(centx,centy,r);
	bresc(centx,centy,r/2);
	dda(centx,centy-r,centx-0.865*r,centy+r/2);
	dda(centx-0.865*r,centy+r/2,centx+0.865*r,centy+r/2);
	dda(centx+0.865*r,centy+r/2,centx,centy-r);
	delay(20000);
	closegraph();
}
//300 400 50
