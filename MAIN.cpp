#include "bits/stdc++.h"
#include "NEW_S.cpp"
#include "pinch.cpp"
#include "trans.cpp"
#include "welcome.cpp"
#include "thanks.cpp"
void deposit2();
void deposit1();
void balance();
void fast_cash();
void withdrawl();
void main_menu();
void others();
void ms();
void welcome();
void transac();
struct cddt
{char a[21];
 char p[5];
}cd;
void bo(int a,int b)
{     int mx=getmaxx();int my=getmaxy();
	setcolor(a);
	rectangle(4*mx/5,4*my/5,5*mx/5+50,4*my/5+40);
	setcolor(b);
	rectangle(4*mx/5,4*my/5+60,5*mx/5+50,4*my/5+100);
	setcolor(WHITE);
}

void main()
{
    //int mx=getmaxx();
   //	int my=getmaxy();
       int g=0,d=0;
	initgraph(&g,&d,"C:\\TURBOC3\\BGI");
       chkupd();
       wlcm();
       //setbkcolor(GREEN);
       //logo();
       //wel();
       //delay(4000);
      login_layout();
       updtmst();
       updtblg();
       updts();
       thanks();
       //	main_menu();
      //	fast_cash();
 // withdrawl();
//deposit1();
//deposit1();
	//setfillstyle(SOLID_FILL,RED);
	//bar(100,200,200,300);
	closegraph();
	restorecrtmode();
}