#include<reg51.h>
sbit r1= P1^0; //the size of dialpad is 4 rows and 3 column//
sbit r2= P1^1;
sbit r3= P1^2;
sbit r4= P1^3;
sbit c1= P1^4;
sbit c2= P1^5;
sbit c3= P1^6;
// 4*3 keypad connection //
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
//line 10-12 lcd control lines //
sbit motp=P3^3;
sbit motn=P3^4;
//line 14-15 motor connection//
void lcdcmd(unsigned char);
void lcddat(unsigned char);
void lcddis(unsigned char *,unsigned char);
void delay();
void check();
//line 17-21 function calling//
unsigned char pwd[10],x;//password is stores in the array pwd//
void main()
{
	lcdcmd(0x38); // 2 line 
	lcdcmd(0x01); // Clear display screen //
	lcdcmd(0x10); // shift cursor position to left //
	lcdcmd(0x0c); // Display on,Cursor off //
	lcdcmd(0x80); // Force cursor to beginning to 1st line //
	lcddis("PASSWORD PROTECTION",19);
	lcdcmd(0xc0); // Force cursor to beginning of 2nd line //
	lcddis("SYSTEM",7);
	lcdcmd(0x01);
	lcddis("ENTER PASSWORD",14);
	lcdcmd(0xc0);
	while (1)
	{
		
		r1=0;
		if(c1==0)
		{
			pwd[x] ='1';
			delay();delay();delay();delay();delay();delay();
			delay();delay();delay();delay();
			delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c2==0)
		{
			pwd[x] ='2';
			delay();delay();delay();delay();delay();delay();
			delay();delay();delay();delay();
			delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c3==0)
		{
			pwd[x] ='3';
			delay();delay();delay();delay();delay();delay();
			delay();delay();delay();delay();
			delay();delay();
			lcddat('*');
			x=x+1;
		}
		r2=0;r1=1;
		if(c1==0)
		{
			pwd[x] ='4';
			delay();delay();delay();delay();delay();
			delay();delay();delay();delay();
			delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c2==0)
		{
			pwd[x] ='5';
			delay();delay();delay();delay();delay();
			delay();delay();
			delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c3==0)
		{
			pwd[x] ='6';
			delay();delay();delay();delay();delay();
			delay();delay();delay();
			delay();delay();
			lcddat('*');
			x=x+1;
		}
		r3=0;r2=1;
		if(c1==0)
		{
			pwd[x] ='7';
			delay();delay();delay();delay();delay();
			delay();delay();delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c2==0)
		{
			pwd[x] ='8';
			delay();delay();delay();delay();delay();
			delay();delay();delay();delay();
			delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c3==0)
		{
			pwd[x] ='9';
			delay();delay();delay();delay();delay();
			delay();delay();delay();delay();
			delay();delay();
			lcddat('*');
			x=x+1;
		}
		r4=0;r3=1;
		if(c1==0)
		{
			pwd[x] ='*';
			delay();delay();delay();delay();delay();
			delay();delay();
			delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c2==0)
		{
			pwd[x] ='0';
			delay();delay();delay();delay();delay();
			delay();delay();
			delay();delay();
			lcddat('*');
			x=x+1;
		}
		if(c3==0)
		{
			check();
			delay();
			delay();
			
		}
		r4=1;
	}
	
}	

void check()
{
if(pwd[0]=='6' && pwd[1]=='2' && pwd[2]=='3' && pwd[3]=='8' && pwd[4]=='6' && pwd[5]=='3' 
	&& pwd[6]=='0' && pwd[7]=='0' && pwd[8]=='2' && pwd[9]=='1')

{
	motp=1;
	motn=0;
	lcdcmd(0x01);
	lcddis("PASSWORD MATCHED",16);
	delay();
}
else
{
	lcdcmd(0x01);
	lcddis("PASSWORD WRONG",14);
}
}
void lcdcmd(unsigned char val)
{
	P2=val;
	rs=0;
	rw=0;
	en=1;
	delay();
	en=0;
}
void lcddat(unsigned char dat)
{
P2=dat;
rs=1;
rw=0;
en=1;
delay();
en=0;	
}
void lcddis(unsigned char *s,unsigned char r)
{
unsigned char w;
for(w=0;w<r;w++)
	{
		lcddat(s[w]);
		delay();
	}
}
void delay()
{
unsigned int i,j;
for(i=0;i<4000;i++);
for(j=0;i<100;j++);
}
