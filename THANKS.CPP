//#include "header.h"
void  thanks()
{      //	int g=0,d=0;
       //	initgraph(&g,&d,"C:\\TURBOC3\\BGI");
	int mx=getmaxx();
	int my=getmaxy();
	setbkcolor(RED);
	//cleardevice();
	//cout<<mx<<endl<<my;
	settextstyle(7,0,3);
	for(int i=0;i<my;i=i+5)
       {	cleardevice();
		outtextxy(mx/2-40,my-i-40,"Thank You");
		outtextxy(mx/3,my-i-10,"for using S.P.S.E.C. ATM !");
		delay(150);
	}
       //chkupd();
       //updtmst();
       //updts();
      //	closegraph();
     //	restorecrtmode();
}