//#include "header.h"



       //	setfillstyle(1,BLUE);
       //	pieslice(mx/2,my/5,0,360,10);
void logo()
{

	int mx=getmaxx();
	int my=getmaxy();
	setfillstyle(9,BROWN);
	pieslice(mx/2,my/5,0,360,95);
	setfillstyle(1,WHITE);
	pieslice(mx/2,my/5,0,240,75);
	pieslice(mx/2,my/5,300,360,75);
		//bar(mx/2-50,my/6,mx/2+50,my/6+20);
	setfillstyle(1,GREEN);
	pieslice(mx/2,my/5,0,180,50);
	pieslice(mx/2,my/5,240,300,75);
	bar(mx/2-10,my/5,mx/2+10,my/5+30);
	setbkcolor(2);
	settextstyle(3,0,1);
	outtextxy(mx/2-35,my/5-30,"Union");
	outtextxy(mx/2-2,my/5+12,"A");
	outtextxy(mx/2-2,my/5+32,"T");
	outtextxy(mx/2-2,my/5+52,"M");
}
void wel()
{

	int mx=getmaxx();
	int my=getmaxy();
	settextstyle(7,0,7);
	outtextxy(mx/4,my/2,"Welcome to");
	outtextxy(mx/4-50,my/2+100,"Union ATM !!");


}
void wlcm()
{      // int g=0,d=0;
	//initgraph(&g,&d,"C:\\TURBOC3\\BGI");
	cleardevice();
	logo();
	wel();
	delay(3000);
	//getch();
	//closegraph();
	//restorecrtmode();
}
