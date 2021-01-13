#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>

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

