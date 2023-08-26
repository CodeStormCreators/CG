/*c)Write C++ program to draw man walking in the rain with an umbrella. Apply the concept of
polymorphism.*/


#include<iostream>
#include<graphics.h>
#include<math.h>

void man(){
    int x,y;
    line(0,550,getmaxx(),550);
    for(int i=0;i<getmaxx()-180;i++){
        cleardevice();
        rectangle(10+i,300,60+i,400);
		line(15+i,400,55+i,450);
		line(15+i,450,55+i,400);
		circle(35+i,280,20);
		line(35+i,310,75+i,350);
		line(60+i,340,75+i,310);
		line(75+i,310,75+i,250);
		line(0+i,250,150+i,250);
		arc(75+i,250,180,0,75);

        for(int j=0;j<100;j++)
		{
			x=rand()%getmaxx();
			y=rand()%getmaxy();
			line(x,y,x+4,y+4);
		}
    }
}
int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);

    man();
    delay(1000);
    closegraph();
    return 0;
}
