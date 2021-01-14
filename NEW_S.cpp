#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>
long point;
struct mst
{	char cno[21], pin[5];
	char name[50];
	long	 opal;

};
struct bal
{	char cno[21];
	long drawn,deposited, balance;
	date dot;                       //date of trans..

}globe;
mst global;

void precaution()
{   clrscr();
	fstream f,g;
	f.open("s.txt",ios::in);
	g.open("i2334.txt",ios::out);
	char c,d;
	while(f.get(c))
	{      
		if(c=='\n')
		{     
			f.get(d);
			if(d<48 || d>57)
			break;
		}
		g<<c;
	}
	g.close();
	f.close();
	remove("s.txt");
	rename("i2334.txt","s.txt");
}//precaution

void chkupd()
{   clrscr();
	fstream f,g;
	mst p,q,blk={"","","",0};
  
	f.open("s.txt",ios::in);
    
	g.open("mst.dat",ios::out|ios::binary);
	char c;
	int i=0,j=0,z1=0;
	while(!f.eof())
	{     	while(f.get(c))
		{	if(c=='-')
				break;
			p.cno[i++]=c;
		}
		p.cno[i]='\0';
		i=0;
		
		while(f.get(c))
		{	if(c=='-')
				break;
			p.pin[i++]=(c);
		}
		p.pin[i]='\0';
		i=0;
		while(f.get(c))
		{	if(c=='-')
				break;
			p.name[i++]=c;
		}
		p.name[i]='\0';
		i=0;
		p.opal=0;
		while(f.get(c))
		{	if(c=='-')
				break;
			p.opal=p.opal*10+(c-48);
		}
		i=0;
		f.get(c); 
		 int counter1=0;
		 point=0;

		    
			if(strcmpi(p.cno,""))
			g.write((char*)&p,sizeof(p));
			q=p=blk;
	 

	}//while !f.eof
	f.close();
	g.close();

}       //chkupd
void view()
{	clrscr();
	ifstream f;
	mst p;
	int i=0;
	f.open("mst.dat",ios::in|ios::binary);
	while(f.read((char*)&p,sizeof(p)))
	{	cout<<"Rec No "<<i++<<" "<<p.cno<<" - "<<p.name<<" - "<<p.opal<<" - "<<endl;
	}
	f.close();
	getch();
}//view

int verify(char cno[21],char pin[5])
{
	fstream f;
	f.open("mst.dat",ios::in|ios::binary);
	mst p;
	int flag=0;
	while(f.read((char*)&p,sizeof(p)))
	{
	if(strcmpi(p.cno,cno)==0)
		{	if(strcmpi(p.pin,pin)==0)
			{	flag=1;
				global=p;
				strcpy(globe.cno,p.cno);
				break;
			}
		}

	}//while ends

	f.close();
	return flag;
}//verify

void updtblg()
{  mst k;
   bal p;
   fstream f,g;
   f.open("ballog.dat",ios::in|ios::out|ios::binary);
   g.open("mst.dat",ios::in|ios::binary);
   while(!g.eof())
   {
    g.read((char*)&k,sizeof(k));
    while(!f.eof())
	{point=f.tellg();
	f.read((char*)&p,sizeof(p));
	 if(strcmpi(p.cno,k.cno)==0)
	 {
		p.balance=k.opal;

		f.seekp(point);
		f.write((char*)&p,sizeof(p));
	 }
	 }//in while
    f.seekg(ios::beg);
   }//while
}//update

long withdrawal(long pr)
{       mst k;
	bal p,q;
	fstream f,g;
       /*	f.open("ballog.dat",ios::out|ios::binary);
	g.open("mst.dat",ios::in|ios::binary);
	//g.seekg(0);
	while(g.read((char*)&k,sizeof(k)))
	{
		strcpy(p.cno,k.cno);
		p.drawn=0;
		p.balance=k.opal;
		p.deposited=0;
		date d;
		getdate(&d);
		p.dot=d;
		f.write((char*)&p,sizeof(p));
	}//while
	f.close();
	g.close();
	*/
	f.open("ballog.dat",ios::in|ios::binary);
	long ver=0;

	//strcpy(global.cno,"1111111111111111111");
	while(f.read((char*)&p,sizeof(p)))
	{point=f.tellg()-sizeof(p);
	if(strcmpi(p.cno,global.cno)==0)
		      {
			 q=p;

			 break;
		      }
	}
	f.close();
	f.open("ballog.dat",ios::in|ios::out|ios::binary);
	if(pr<=q.balance)
	{
		q.drawn=pr;
		q.balance-=pr;

		ver=1;
	}
	else
	{	cout<<"Insufficient balance";
	}
	if(ver==1)
	       {
			date d;
			getdate(&d);
			f.seekp(point);
			q.dot=d;
			f.write((char*)&q,sizeof(q));
			global.opal=q.balance;
		    //   cout<<"verified  "<<global.name<<" "<<global.opal;
		      //	delay(3000);
	       }
	f.close();

	return(ver);

}//withdrawal
void depos(long pr)
{
	mst k;
	bal p,q;
	fstream f,g;
	f.open("ballog.dat",ios::in|ios::binary);
	int ver=0;

	while(f.read((char*)&p,sizeof(p)))
	{point=f.tellg()-sizeof(p);
	if(strcmpi(p.cno,global.cno)==0)
		      {
			 q=p;

			 break;
		      }
	}
	f.close();
	f.open("ballog.dat",ios::in|ios::out|ios::binary);
	
	       {        q.deposited=pr;
			q.balance+=pr;
			date d;
			getdate(&d);
			f.seekp(point);
			q.dot=d;
			f.write((char*)&q,sizeof(q));
			global.opal=q.balance;
		    //   cout<<"verified  "<<global.name<<" "<<global.opal;
		      //	delay(3000);
	       }
	f.close();

	//return(q.balance);

}//depos