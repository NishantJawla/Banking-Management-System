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
	outtextxy(mx/3-40,my/20,"B A N K   OF   U N I O N");
	settextstyle(0,0,0);
	outtextxy(mx/3+30,my/10+30,"SELECT TRANSACTION");
	setcolor(YELLOW);
	settextstyle(1,0,2);
		// RECTANGLES CODING HERE L-LEFT RECTANGLES & R-RIGHT RECTANGLES
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


void balance()         //balance begins
{cleardevice();
 int mx=getmaxx(),my=getmaxy();
 setbkcolor(BLUE);
 setcolor(YELLOW);
 settextstyle(1,0,0);
 outtextxy(mx/4-30,my/20,"BALANCE   ENQUIRY");
 settextstyle(1,0,1);
 outtextxy(140,my/2-100,"Dear user your current balance is:");
 //char* bal=readfile();
 outtextxy(80,my/2+27,"BALANCE:            Rs.");
gotoxy(40,18);
cout<<global.opal;
 getch();
}//balance ends

void fast_cash()
{       cleardevice();
	int mx=getmaxx();
	int my=getmaxy();
	setbkcolor(RED);
	setcolor(YELLOW);
	//*************
	outtextxy(mx/3-40,my/20,"B A N K   OF   S  P  S  E  C");
	//***************
		rectangle(mx/60,my/3+20,mx/20*8,my/3-30);            //1L
		rectangle(mx/60,my/3+70,mx/20*8,my/3+120);           //2L
		rectangle(mx/60,my/3+170,mx/20*8,my/3+220);          //3L
		rectangle(mx/60,my/3+270,mx/20*8,my/3+320);          //4L
		rectangle(mx/2+60,my/3+20,mx/60*53+100,my/3-30);     //1R
		rectangle(mx/2+60,my/3+70,mx/60*53+100,my/3+120);    //2R
		rectangle(mx/2+60,my/3+170,mx/60*53+100,my/3+220);   //3R
		rectangle(mx/2+60,my/3+270,mx/60*53+100,my/3+320);   //4R

	setcolor(CYAN);
		outtextxy(mx/60+75,my/3-20,"1,000");	//1l               1
		outtextxy(mx/60+75,my/3+80,"2,000");        //2l           2
		outtextxy(mx/60+75,my/3+180,"5,000");           //3l       3
		outtextxy(mx/60+70,my/3+280,"10,000");              //4l   4
		outtextxy(mx/2+145,my/3-20,"20,000");           //1r       5
		outtextxy(mx/2+145,my/3+80,"30,000");           //2r       6
		outtextxy(mx/2+145,my/3+180,"50,000");            //3r     7
		outtextxy(mx/2+145,my/3+280,"60,000");             ///4r   8
	long bal;			 //to receive return val from withdr
	int frm=s();
	if(frm==1)
	{
	bal=withdrawal(1000);
	}
	if(frm==2)
	{
	bal=withdrawal(2000);
	}
	if(frm==3)
	{
	bal=withdrawal(5000);
	}
	if(frm==4)
	{
	bal=withdrawal(10000);
	}
	if(frm==5)
	{
	bal=withdrawal(20000);
	}
	if(frm==6)
	{
	bal=withdrawal(30000);
	}
	if(frm==7)
	{
	bal=withdrawal(50000);
	}
	if(frm==8)
	{
	bal=withdrawal(60000);
	}
       //	updtmst();
       //	updts();
	transac();
	balance();
	//getch();
}//fast_cash ends


void box(int a,int b)
{     int mx=getmaxx();int my=getmaxy();
	setcolor(a);
	rectangle(mx-100,my-110,mx-5,my-70);
	setcolor(b);
	rectangle(mx-100,my-60,mx-5,my-20);

	setcolor(WHITE);
}
void setbox(int i)
{	switch(i)
	{case 0:box(WHITE,BLACK);
		break;
	 case 1:box(BLACK,WHITE);
		break;
	}
}

int scroll(char a)
{
	int dir;
	int c=0;
	if(a=='\0')
	{setbox(1); c=1;}
	else{
	setbox(c);
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
		setbox(c);
	}//while
	}
return(c);
}//scroll

void box1(int c)
{     	int mx=getmaxx();int my=getmaxy();
setcolor(c);
rectangle(mx/2-150,my/3-40+5,mx/2+150,my/3+20+5);
	setcolor(WHITE);
	rectangle(mx/2-150,my/3+60+5,mx/2+150,my/3+120+5);
	rectangle(mx/2-150,(my/3)+160+5,mx/2+150,my/3+220+5);
}

void box2(int c)
{      	int mx=getmaxx();int my=getmaxy();
setcolor(c);
	rectangle(mx/2-150,my/3+60+5,mx/2+150,my/3+120+5);
	setcolor(WHITE);
	rectangle(mx/2-150,my/3-40+5,mx/2+150,my/3+20+5);
	rectangle(mx/2-150,(my/3)+160+5,mx/2+150,my/3+220+5);
}//box2
void box3(int c)
{	int mx=getmaxx();int my=getmaxy();
setcolor(c);
	rectangle(mx/2-150,(my/3)+160+5,mx/2+150,my/3+220+5);
	setcolor(WHITE);
	rectangle(mx/2-150,my/3-40+5,mx/2+150,my/3+20+5);
	rectangle(mx/2-150,my/3+60+5,mx/2+150,my/3+120+5);
}//box3
void setbox1(int i)
{
	switch(i)
	{	case 0: box1(GREEN);
			break;
		case 1: box2(GREEN);
			break;
		case 2: box3(GREEN);
			break;
	}

}//setbox


void scr()
{
int i;
int counter=0;
setbox1(counter);
while(1)
{       i=getch();
	if(i==80)
	{       counter++;
		if(counter==3)
			counter=0;
	}
	if(i==72)
	{	counter--;
		if(counter==-1)
			counter=2;
	}
	if(i==13)
	       { break;}
	setbox1(counter);

	 //getch();
}//while
}


void deposit1()
{	cleardevice();
	setbkcolor(BLUE);
	int mx=getmaxx();
	int my=getmaxy();
	setcolor(YELLOW);
	settextstyle(1,0,4);
	outtextxy(mx/4,20,"BANK  OF  SPSEC");
	setcolor(WHITE);
	settextstyle(1,0,2);
	rectangle(mx/2-150,my/3-40+5,mx/2+150,my/3+20+5);
	rectangle(mx/2-150,my/3+60+5,mx/2+150,my/3+120+5);
	rectangle(mx/2-150,(my/3)+160+5,mx/2+150,my/3+220+5);
	setcolor(GREEN);
	outtextxy(mx/2-100,my/3-20,"CURRENT ACCOUNT");
	outtextxy(mx/2-95,my/3+80,"SAVINGS ACCOUNT");
	outtextxy(mx/2-80,my/3+180,"FIXED DEPOSIT");
	scr();
	deposit2();
 }


 void deposit2()
 {cleardevice();

 setbkcolor(BLUE);
 setcolor(WHITE);
	int mx=getmaxx();
	int my=getmaxy();
	setcolor(YELLOW);
	settextstyle(1,0,4);
	outtextxy(mx/4,20,"BANK  OF  SPSEC");
	settextstyle(1,0,3);
	outtextxy(20,my/2-30,"Enter amount to be deposited");
	setcolor(WHITE);
	rectangle(mx/2+90,my/2-31,mx-10,my/2+31);
	rectangle(mx-100,my-110,mx-5,my-70);
	rectangle(mx-100,my-60,mx-5,my-20);
	setcolor(GREEN);
	outtextxy(mx-95,my-105,"Proceed");
	setcolor(RED);
	outtextxy(mx-90,my-55,"Cancel");
	setcolor(WHITE);
	int l1;
	l1:
	char a[8];
		int i=0; int x=55,y=15;
	for(i=0;i<8;i++)
	{a[i]='\0';} i=0;
	while(i<8)
	{
		a[i]=getch();
		settextstyle(0,0,1);
		if(a[i]==13)
			{  a[i]='\0';
			if(i!=0)
			{gotoxy(x,y);
			cout<<". 0 0";}
			delay(500);
			break;}
		if(a[i]==8)
			{a[i]='\0';
			gotoxy(x-2,y);
			x-=2;
			if(x<=55)
				x=55;
			cout<<"  ";
			--i;
			if(i<0)
				i=0;
			continue;
			}
		if(a[i]<48||a[i]>57)
			{settextstyle(1,0,4);
			setcolor(RED);
			outtextxy(245,my/2+50,"Invalid Input");
			delay(1000);
			setfillstyle(SOLID_FILL,BLUE);
			bar(200,my/2+50,470,my/2+100);

			setcolor(WHITE);
			settextstyle(0,0,1);
			x=55;y=15;
			for(int k=0;k<i*2;k++)
				{gotoxy(x+k,y);
				cout<<" ";
				}
			i=0;
			for(k=0;k<8;k++)
				{a[k]='\0';}
			continue;
			}
		gotoxy(x,y);
		cout<<a[i];
		x+=2;
		i++;
	if(i==8)
	{ gotoxy(x,y);
			cout<<". 0 0";
	}
	}

       int ab=scroll(a[0]);
       delay(500);
       if(ab==0)
       {cleardevice();
	int jk=0;
	long depo=0;
	while(a[jk]!='\0')
	{     	depo=depo*10+(a[jk]-48);
		jk++;
	}    //while
	//cout<<depo;
	//delay(1000);
	depos(depo);
	//updtmst();
	//updts();
	transac();
	}//if
	balance();
//getch();
}

void others()
{
	cleardevice();
	int mx=getmaxx();
 //	int my=getmaxy();
	setbkcolor(RED);
	settextstyle(1,0,3);
	outtextxy(mx/3+20,30,"ATM OF U N I O N");
	settextstyle(1,0,2);
	outtextxy(mx/3+70,90,"GUIDELINES");
	settextstyle(1,0,1);
	outtextxy(mx/20,150,"1. Guard your ATM Pin Number");
	outtextxy(mx/20,180,"2. Never write the PIN on anything");
	outtextxy(mx/20,210,"3. Keep your card in safe and secured place");
	outtextxy(mx/20,240,"4. Check ATM for any fraudulent devices attached");
	outtextxy(mx/20,270,"5. Change your ATM Pin immediately when fraud is suspected");

	outtextxy(mx/20,350,"For more queries, contact:");
	outtextxy(mx/20,380,"Phone: 0512-2218222");
	outtextxy(mx/20,410,"Toll-Free No.: 1800 425 3800");
	outtextxy(mx/20,440,"Website: www.unionatm.com");
	setfillstyle(SOLID_FILL,MAGENTA);
	bar(8*mx/15-10,340,mx-5,410);
	setcolor(YELLOW);
	rectangle(4*mx/5-30,430,mx-5,480);
	rectangle(mx/20-10,340,mx/2-10,480);
	setcolor(WHITE);
	settextstyle(3,0,1);
	outtextxy(8*mx/15+5,350,"New Rules and Charges :");
	outtextxy(8*mx/15,380,"Applicable w.e.f 01/01/2021 !");
	setcolor(BLUE);
	outtextxy(4*mx/5-10,450,"Back To Menu");
	getch();
}//others ends

void welcome()
{	cleardevice();
	setbkcolor(RED);
	int mx=getmaxx();
	int my=getmaxy();
	setcolor(BLUE);
	settextstyle(1,0,4);
	outtextxy(200,25," W E L C O M E");
	settextstyle(1,0,3);
	outtextxy(50,200,"Dear user,");
	setcolor(YELLOW);
	outtextxy(200,200,global.name);
	setcolor(BLUE);
	int i=0;
	for(i=0;i<=11;i++)
		{
		 int j=i%4;
		 switch(j)
			{
				case 0:gotoxy(66,14);
				       cout<<".       ";
				       delay(300);
				       break;
				case 1:gotoxy(66,14);
				       cout<<". .     ";
				       delay(440);
				       break;
				case 2:gotoxy(66,14);
				       cout<<". . .   ";
				       delay(570);
				       break;
				case 3:gotoxy(66,14);
				       cout<<". . . . ";
				       delay(660);
				       break;
				default: cout<<" ";
			} //switch
		delay(1);
		}//for
	//getch();
}

void ms()
{       int lab;
	lab:

	cleardevice();
	setbkcolor(RED);
	setcolor(YELLOW);
	int mx=getmaxx();
	int my=getmaxy();
	settextstyle(1,0,3);
	outtextxy(mx/3-10,10,"Mini Statment");
	setcolor(WHITE);
	settextstyle(0,0,1);
	outtextxy(mx/20+150,my/5,"Your Previous 3 Transictions Are ");
	fstream g;
	g.open("ballog.dat",ios::in|ios::binary);
	while(!g.eof())
	{ bal p;
	  g.read((char*)&p,sizeof(p));
	  if(strcmpi(p.cno,globe.cno)==0)
	  {   gotoxy(25,17);
	      cout<<" Balance:               Rs."<<p.balance<<endl;
	      gotoxy(25,18);
	      cout<<" Drawn:                 Rs."<<p.drawn;
	      gotoxy(25,19);
	      cout<<" Deposited:             Rs."<<p.deposited;
	      gotoxy(25,20);
	      cout<<"Last date of transaction:  ";
	      putch(p.dot.da_day);
	      cout<<"/";
	      putch(p.dot.da_mon);
	      cout<<"/"<<p.dot.da_year;
	  }
	}
	g.close();

	delay(500);
	//flush();  ******************************************
	setcolor(YELLOW);




	rectangle(4*mx/5,4*my/5+40,5*mx/5+50,4*my/5+90);

	outtextxy(4*mx/5+10,4*my/5+60,"Proceed");



setcolor(13);
rectangle(1,1,639,479);
rectangle(15,15,624,464);
//setcolor(LIGHTBLUE);
setfillstyle(6,11);

floodfill(2,2,13);
settextstyle(7,0,3);
setcolor(12);


outtextxy(200,200,"S.P.S.E.C BANK") ;

getch();
}


void transac()
{cleardevice();                     //showing result
      int mx= getmaxx();
      int my=getmaxy();
      setbkcolor(BLUE);
      setcolor(WHITE);
     // int mx=getmaxx();
     // int my=getmaxy();
      setcolor(YELLOW);
      settextstyle(1,0,4);
      outtextxy(200,20,"BANK  OF  UNION");
      setcolor(CYAN);
      settextstyle(1,0,3);
      outtextxy(150,my/2,"Your transaction is complete");
      delay(2000);
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