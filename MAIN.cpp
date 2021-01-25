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
void setb(int i)
{	switch(i)
	{case 0:bo(YELLOW,WHITE);
		break;
	 case 1:bo(WHITE,YELLOW);
		break;
	}
}

int sc()
{
	int dir;
	int c=0;

	setb(c);
	while(1)
	{ dir=getch();
		if(dir==80)
		{	c++;
			if(c==2)
			{c=0;}
		}
		if(dir==72)
		{c--;
			if(c==-1)
			{c=1;}
		}
		if(dir==13)
			{break;}
		setb(c);
	}//while

return(c);
}
void login_layout()
{       int lab;
	lab:

	cleardevice();
	setbkcolor(RED);
	setcolor(YELLOW);
	int mx=getmaxx();
	int my=getmaxy();
	settextstyle(1,0,3);
	outtextxy(mx/3-10,10,"CARD DETAIL");
	setcolor(WHITE);
	settextstyle(0,0,1);
	outtextxy(mx/20,my/3+5,"Card Number");
	setcolor(YELLOW);
	rectangle(mx/20*5,my/3-20+5,mx/20*15-5,my/3+20+5);
	setcolor(WHITE);
	outtextxy(mx/20,my/2,"Enter PIN");
	rectangle(mx/20*5,my/2-20,mx/20*15-5,my/2+20);
	char cno[21],di[2];
	int a;int bm=0;
	a:
	int i=0;
	di[1]='\0';
	//int l1;l1:
	//int x=23,y=11;
	for(i=0;i<20;i++)
	{cno[i]='\0';}
	i=0;
	while(i<20)
	{       bm=0;
		 cno[i]=getch();
		if(cno[i]==13)
		{
		  if(i<19)
		  { outtextxy(mx/20*6+10,my/3+30,"cardno.not upto size ");
		    delay(500); bm=1;
		    setfillstyle(SOLID_FILL,RED);
		    bar(mx/20*6+10,my/3+25+5,mx/20*6+250,my/3+40);
		  --i;}
		  else
		  break;
		}

		if(cno[i]==8)
		{
			//di[0]=' ';
			--i;
			if(i<0)
				i=0;
			setcolor(RED);
		       //	outtextxy(mx/20*6+(i*10),my/3,di);
		     for(int j=0;j<20;j++)
				rectangle(mx/20*6+(i*10)-3,my/3-5,mx/20*6+(i*10)-3+j,my/3-5+j);
			setcolor(WHITE);
			continue;
		}
		if((cno[i]<48||cno[i]>57)&&cno[i]!=13)
		{	outtextxy(mx/20*6+10,my/3+30+5,"Enter valid Info.");
			delay(500);
			setfillstyle(SOLID_FILL,RED);
			bar(mx/20*6,my/3-10,mx/20*15-20,my/3+10);

			bar(mx/20*6+10,my/3+25+5,mx/20*6+200,my/3+40+5);
			goto a;
			bm=1;
		}
		if(bm==0)
		{	di[0]=cno[i];
		outtextxy(mx/20*6+(i*10),my/3+3,di); }

		i++;
	}//Card no. while ends

	delay(500);
	//flush();  ******************************************
	setcolor(YELLOW);
	rectangle(mx/20*5,my/2-20,mx/20*15-5,my/2+20);
	setcolor(WHITE);
	rectangle(mx/20*5,my/3-20+5,mx/20*15-5,my/3+20+5);
	int b;
	b:
	char ipin[5]; ipin[4]='\0';
	int i2=0;
	while(i2<4)
	{	 ipin[i2]=getch();
		if(ipin[i2]==13)
		  {	if(i2<4)
		  { outtextxy(mx/20*6+10,my/2+130,"pin not upto size ");
		    delay(400);
		    setfillstyle(SOLID_FILL,RED);
		    bar(mx/20*6,my/2+120,mx/20*6+300,my/2+170);
		    bar(mx/20*5+2,my/2-10,mx/20*15-30,my/2+10);
		  i2=0;
		  continue;
		  }
		  else
		  break; }
		if(ipin[i2]==8)
		{       i2--;
			if(i2<0)
				i2=0;
			setcolor(RED);

			for(int j=0;j<20;j++)
				rectangle(mx/4+10+(i2*10)-3,my/2-3,mx/20*6+(i2*10)-3+j,my/2-3+j);
			setcolor(WHITE);
			continue;

		}
		if(ipin[i2]<48||ipin[i2]>57)
		{
			outtextxy(mx/4+20,my/2+50,"Enter valid Info.");
			delay(500);
			setfillstyle(SOLID_FILL,RED);
			bar(mx/4+10,my/2-3,mx/20*15-20,my/2+5);
			bar(mx/4+20,my/2+45,mx/20*15+200,my/2+60);
			goto b;
		}//if ends
		else
		{		outtextxy(mx/4+10+(i2*10),my/2,"* ");
		}
		//to match the ipin with text file
		i2++;
	}  //end of while
	rectangle(4*mx/5,4*my/5,5*mx/5+50,4*my/5+40);
	rectangle(4*mx/5,4*my/5+60,5*mx/5+50,4*my/5+100);
	outtextxy(4*mx/5+10,4*my/5+20,"Proceed");
	outtextxy(4*mx/5+10,4*my/5+80,"Cancel");

	cno[20]='\0';
	setcolor(WHITE);
	rectangle(mx/20*5,my/2-20,mx/20*15-5,my/2+20);
      int lm=sc();
      if(lm==1)
      goto lab;

     lm=verify(cno,ipin);
      if(lm==0)
	{ outtextxy(mx/3,my-100,"No such account exists");
	 delay(600);
       goto lab;
	}
      if(lm==1)
      {welcome();
       //cout<<global.cno<<" "<<global.name<<" "<<global.opal;
      main_menu();
      }

getche();
}//ends login_layout


void withdrawl()
{
	cleardevice();
	setbkcolor(BLUE);
	int mx=getmaxx();
	int my=getmaxy();
	setcolor(YELLOW);
	settextstyle(1,0,3);
	outtextxy(mx/3+30,20,"CASH WITHDRAWL");
	setcolor(WHITE);
	settextstyle(0,0,2);
	outtextxy(50,my/2-20,"Enter Amount to be Withdrawn");
	rectangle(2*mx/3,my/2+20,mx-10,my/2+60);
//	moveto(2*mx/3+5,my/2+40);        ***************
	settextstyle(0,0,1);
	outtextxy(2*mx/3+5,my/2+40,"Rs");
	int a;
	a:          //goto
	int i=0;
	char cno[9],di[2];
	for(i=0;i<9;i++)
		cno[i]='\0';
	di[1]='\0';
	i=0;
	while(i<7)
	{	char c=getch();
		if(c==13)
		break;
		if(c==8)
		{	//di[0]=' ';
			--i;
			setcolor(BLUE);
			for(int j=0;j<20;j++)
			rectangle(2*mx/3+32+(i*10),my/2+35,2*mx/3+32+(i*10)+j,my/2+35+j);      			setcolor(WHITE);
			continue;
		}
		if(c<48||c>57)
		{outtextxy(2*mx/3+10,my/2+80,"Enter valid Info.");
			delay(500);
			setfillstyle(SOLID_FILL,BLUE);
			bar(2*mx/3+30,my/2+30,mx-40,my/2+50);
			bar(2*mx/3+8,my/2+70,2*mx/3+200,my/2+90);
			goto a;
		}//if ends
		else
			di[0]=c;
		outtextxy(2*mx/3+35+(i*10),my/2+40,di);
		cno[i]=c;
		i++;
	} //while ends
	cno[i]='\0';
	rectangle(4*mx/5,4*my/5,5*mx/5+50,4*my/5+40);
	rectangle(4*mx/5,4*my/5+60,5*mx/5+50,4*my/5+100);
	outtextxy(4*mx/5+10,4*my/5+20,"Accept");
	outtextxy(4*mx/5+10,4*my/5+80,"Cancel");
	//to check balance with min_balance and give appropriate message
	int jk=0;
	long drawn=0,bal;
	while(cno[jk]!='\0')
	{     	drawn=drawn*10+(cno[jk]-48);
		jk++;
	}
	//cout<<"drawn"<<drawn;
	//exit(0);
	//cout<<"balance"<<bal;
	if(drawn)
       bal=withdrawal(drawn);
      //<<" "<<drawn;
      // updtmst();
      // updts();
      // view();
       transac();
       balance();

}//Withdrawl_Page ends




void bomd(int a,int b)
{int mx=getmaxx();
int my=getmaxy();
setcolor(YELLOW);
		rectangle(mx/60,my/3+20,mx/20*8,my/3-30);            //1L
		rectangle(mx/60,my/3+70,mx/20*8,my/3+120);           //2L
		rectangle(mx/60,my/3+170,mx/20*8,my/3+220);          //3L
		rectangle(mx/60,my/3+270,mx/20*8,my/3+320);          //4L
		rectangle(mx/2+60,my/3+20,mx/60*53+100,my/3-30);     //1R
		rectangle(mx/2+60,my/3+70,mx/60*53+100,my/3+120);    //2R
		rectangle(mx/2+60,my/3+170,mx/60*53+100,my/3+220);   //3R
		rectangle(mx/2+60,my/3+270,mx/60*53+100,my/3+320);   //4R
      setcolor(BLUE);
      if(a==0)
      { if(b==0)
		rectangle(mx/60,my/3+20,mx/20*8,my/3-30);            //1L
	if(b==1)
		rectangle(mx/60,my/3+70,mx/20*8,my/3+120);           //2L
	if(b==2)
		rectangle(mx/60,my/3+170,mx/20*8,my/3+220);          //3L
	if(b==3)
		rectangle(mx/60,my/3+270,mx/20*8,my/3+320);          //4L
      }
      if(a==1)
      {if(b==0)
		rectangle(mx/2+60,my/3+20,mx/60*53+100,my/3-30);     //1R
       if(b==1)
		rectangle(mx/2+60,my/3+70,mx/60*53+100,my/3+120);    //2R
       if(b==2)
		rectangle(mx/2+60,my/3+170,mx/60*53+100,my/3+220);   //3R
       if(b==3)
		rectangle(mx/2+60,my/3+270,mx/60*53+100,my/3+320);   //4R
     }
setcolor(WHITE);
}


int  s()
{ 	int dir;
	int cx=0,cy=0;
	bomd(cx,cy);
	while(1)
	{ dir=getch();
	if(dir==80)
	{cy++;
		if(cy==4)
		{cy=0;}
	}
	if(dir==72)
	{cy--;
		if(cy==-1)
		cy=3;
	}
	if(dir==77)
	{cx++;
		if(cx==2)
		cx=0;
	}
	if(dir==75)
	{cx--;
		if(cx==-1)
		cx=1;
	}
	if(dir==13)
	{
	 if(cx==0)
	 { if(cy==0)
	   return(1);
	   if(cy==1)
	   return(2);
	   if(cy==2)
	   return(3);
	   if(cy==3)
	   return(4);
	 }
	 if(cx==1)
	 {	if(cy==0)
		return(5);
		if(cy==1)
		return(6);
		if(cy==2)
		return(7);
		if(cy==3)
		return(8);
	 }
	}
	bomd(cx,cy);
	}
}


void main_menu()
{

	cleardevice();
	setbkcolor(RED);
	setcolor(WHITE);
	int mx=getmaxx();
	int my=getmaxy();
	settextstyle(1,0,2);
	outtextxy(mx/3-40,my/20,"B A N K   OF   S  P  S  E  C");
	settextstyle(0,0,0);
	outtextxy(mx/3+30,my/10+30,"SELECT TRANSACTION");
	setcolor(YELLOW);
	settextstyle(1,0,2);
		// RECTANGLES CODING HERE L-LEFT RECTANGLES & R-RIGHT RECTANGLES.
		rectangle(mx/60,my/3+20,mx/20*8,my/3-30);            //1L
		rectangle(mx/60,my/3+70,mx/20*8,my/3+120);           //2L
		rectangle(mx/60,my/3+170,mx/20*8,my/3+220);          //3L
		rectangle(mx/60,my/3+270,mx/20*8,my/3+320);          //4L
		rectangle(mx/2+60,my/3+20,mx/60*53+100,my/3-30);     //1R
		rectangle(mx/2+60,my/3+70,mx/60*53+100,my/3+120);    //2R
		rectangle(mx/2+60,my/3+170,mx/60*53+100,my/3+220);   //3R
		rectangle(mx/2+60,my/3+270,mx/60*53+100,my/3+320);   //4R
		// RECTANGLES CODING END HERE.:-)
	      // ********************************************
		//CODING FOR ENTERING TEXT INTO RECTANGLS.
		setcolor(CYAN);
		outtextxy(mx/60+75,my/3-20,"DEPOSIT");
		outtextxy(mx/60+70,my/3+80,"TRANSFER");
		outtextxy(mx/60+60,my/3+180,"PIN CHANGE");
		outtextxy(mx/60+80,my/3+280,"OTHERS");
		outtextxy(mx/2+130,my/3-20,"FAST CASH");
		outtextxy(mx/2+105,my/3+80,"CASH WITHDRAWL");
		outtextxy(mx/2+100,my/3+180,"BALANCE ENQUIRY");
		outtextxy(mx/2+105,my/3+280,"MINI STATEMENT");
		//CODING FOR ENTERING TEXT INTO RECTANGLES END HERE.:-)
		//*******************************************************
		//ENDING PROCESS.
	int frm=s();//value indicating frame to be opened
	if(frm==1)
	{deposit1();
	}
	if(frm==2)
	{
	 transfer();
	}
	if(frm==3)
	{pin();
	}
	if(frm==4)
	{others();
	}
	if(frm==5)
	{fast_cash();
	}
	if(frm==6)
	{withdrawl();}
	if(frm==7)
	{balance();
	}
	if(frm==8)
	{ms();
	}

	//PROCESS FOR FORMING MENU ENDS HERE.
	//*******************************************
}//main menu ends



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