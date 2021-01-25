int sc();
void pin()
{       int lab;
	lab:
	cleardevice();
	setbkcolor(RED);
	setcolor(YELLOW);
	int mx=getmaxx();
	int my=getmaxy();
	settextstyle(1,0,3);
	outtextxy(mx/3-10,10,"PIN CHANGE");
	setcolor(WHITE);
	settextstyle(0,0,1);
	outtextxy(mx/20,my/3+5,"Enter new PIN");
	setcolor(YELLOW);
	rectangle(mx/20*5+20,my/3-20+5,mx/20*15-5,my/3+20+5);
	setcolor(WHITE);
	outtextxy(mx/20,my/2,"Confirm PIN");
	rectangle(mx/20*5+20,my/2-20,mx/20*15-5,my/2+20);
	char ipin2[5];
	int a;int bm=0;
	a:
	int i=0;
	//di[1]='\0';
	//int l1;l1:
	//int x=23,y=11;
	for(i=0;i<5;i++)
	{ipin2[i]='\0';}
	i=0;
	while(i<4)
	{       bm=0;
		 ipin2[i]=getch();
		if(ipin2[i]==13)
		{
		  if(i<3)
		  { outtextxy(mx/20*6+10,my/3+30,"pin not upto size ");
		    delay(500); bm=1;
		    setfillstyle(SOLID_FILL,RED);
		    bar(mx/20*6+10,my/3+25+5,mx/20*6+250,my/3+40);
		  --i;}
		  else
		  break;
		}

		if(ipin2[i]==8)
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
		if((ipin2[i]<48||ipin2[i]>57)&&ipin2[i]!=13)
		{	outtextxy(mx/20*6+10,my/3+30+5,"Enter valid Info.");
			delay(500);
			setfillstyle(SOLID_FILL,RED);
			bar(mx/20*6,my/3-10,mx/20*15-50,my/3+10);

			bar(mx/20*6+10,my/3+25+5,mx/20*6+200,my/3+40+5);
			goto a;
			bm=1;
		}
		if(bm==0)
		{	//di[0]=cno[i];
		outtextxy(mx/20*6+(i*10),my/3+3,"*"); }

		i++;
	}//pin 1 while ends
	delay(500);
	//flush();  ******************************************
	setcolor(YELLOW);
	rectangle(mx/20*5+20,my/2-20,mx/20*15-5,my/2+20);
	setcolor(WHITE);
	rectangle(mx/20*5+20,my/3-20+5,mx/20*15-5,my/3+20+5);

	int b;
	b:
	char ipin1[5]; ipin1[4]='\0';
	int i2=0;
	while(i2<4)
	{	 ipin1[i2]=getch();
		if(ipin1[i2]==13)
		  {	if(i2<4)
		  { outtextxy(mx/20*6+10,my/2+130,"pin not upto size ");
		    delay(400);
		    setfillstyle(SOLID_FILL,RED);
		    bar(mx/20*6,my/2+120,mx/20*6+300,my/2+170);
		   // bar(mx/20*5+20,my/2-10,mx/20*15-30,my/2+10);

		  continue;
		  }
		  else
		  break; }
		if(ipin1[i2]==8)
		{       i2--;
			if(i2<0)
				i2=0;
			setcolor(RED);

			for(int j=0;j<20;j++)
				rectangle(mx/4+30+(i2*10)-3,my/2-3,mx/20*6+(i2*10)-3+j+30,my/2-3+j);
			setcolor(WHITE);
			continue;

		}
		if(ipin1[i2]<48||ipin1[i2]>57)
		{
			outtextxy(mx/4+20,my/2+50,"Enter valid Info.");
			delay(500);
			setfillstyle(SOLID_FILL,RED);
			bar(mx/4+20,my/2-3,mx/20*15-20,my/2+5);
			bar(mx/4+20,my/2+45,mx/20*15+200,my/2+60);
			goto b;
		}//if ends
		else
		{		outtextxy(mx/4+30+(i2*10),my/2,"* ");
		}
		//to match the ipin with text file
		i2++;
	}  //end of while
	setcolor(WHITE);
	rectangle(mx/20*5+20,my/2-20,mx/20*15-5,my/2+20);
	if(strcmpi(ipin1,ipin2))
	{
	 outtextxy(mx/2-120,my/2+100,"The provided pins don't match");
	 delay(700);
	 goto lab;
	}//if
	else
	{
	rectangle(4*mx/5,4*my/5,5*mx/5+50,4*my/5+40);
	rectangle(4*mx/5,4*my/5+60,5*mx/5+50,4*my/5+100);
	outtextxy(4*mx/5+10,4*my/5+20,"Proceed");
	outtextxy(4*mx/5+10,4*my/5+80,"Cancel");
	int lm=sc();
	if(lm==1)
		{exit(0) ;  }
	else
	strcpy(global.pin,ipin1);

	delay(200);

	}
	//getch();

}