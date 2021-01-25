void balance();
void vrtrans(char cno[21],long money)
{
	long ver=0;
	fstream f;
	//long opal=global.opal;
	mst p;
	f.open("mst.dat",ios::in|ios::binary);
	while(f.read((char*)&p,sizeof(p)))
	 {
	       long	point1=f.tellg()-sizeof(p);
		if(strcmpi(p.cno,cno)==0)
		{
		  //ver=1;
		  //cout<<p.cno<<" "<<p.name<<" ";
		  f.close();

		  ver=withdrawal(money);
		  if(ver==1)
			  {
				f.open("mst.dat",ios::in|ios::out|ios::binary);
				p.opal+=money;
				f.seekp(point1,ios::beg);
				f.write((char*)&p,sizeof(p));
				f.close();
				break;
			  }

		  // f.close();
		 // break;
		}//outer if
	}//while
if(ver==0)
	{
	 outtextxy(200,320,"No Such Account exixts!");
	 delay(800);
	 setcolor(RED);
	 bar(190,300,450,350);
	}
//delay(2000);
}//trvrfy
void transfer()
{
	cleardevice();
	setbkcolor(RED);
	setcolor(YELLOW);
	int mx=getmaxx();
	int my=getmaxy();
	settextstyle(1,0,3);
	outtextxy(mx/3-10,10,"TRANSFER MONEY");
	setcolor(WHITE);
	settextstyle(0,0,1);
	outtextxy(mx/20,my/3+5,"Card Number");
	setcolor(YELLOW);
	rectangle(mx/20*5,my/3-20+5,mx/20*15-5,my/3+20+5);
	setcolor(WHITE);
	outtextxy(mx/20,my/2,"Enter money");
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
	char ipin[9];
	for(int op=0;op<9;op++)
	{ipin[op]='\0';
	}
	int i2=0;
	while(i2<8)
	{	 ipin[i2]=getch();
		if(ipin[i2]==13)
		  {	/*if(i2<8)
		  { outtextxy(mx/20*6+10,my/2+130,"pin not upto size ");
		    delay(400);
		    setfillstyle(SOLID_FILL,RED);
		    bar(mx/20*6,my/2+120,mx/20*6+300,my/2+170);
		    bar(mx/20*5+2,my/2-10,mx/20*15-30,my/2+10);
		  i2=0;
		  continue;
		  }  */
		  //else
		  ipin[i2]='\0';
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
		{
			di[0]=ipin[i2];
			outtextxy(mx/4+10+(i2*10),my/2,di);
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
	if(lm==0)
	{ int jk=0;
	long m=0;
	while(ipin[jk]!='\0')
	{     	m=m*10+(ipin[jk]-48);

		jk++;

	}

	//gotoxy(40,20);cout<<m<<" "<<cno;
	//delay(1000);
	vrtrans(cno,m);
	}
	balance();
}