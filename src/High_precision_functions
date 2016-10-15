
#include ".\high-precision-base.h"
//-----------------------------addition-------------------------------
hpnumber hpnumber::add(hpnumber a,hpnumber b)
{
	int i,carry=0,l1,l2,l3,x,y;
	string c;
	l1=strlen(&a.getval()[0]);
	l2=strlen(&b.getval()[0]);
	l3=max(l1,l2);
	if(l1<l2)
	{
		hpnumber tmp=a;
		a=b;
		b=tmp;
		l1=l1+l2;
		l2=l1-l2;
		l1=l1-l2;
	}
	c=a.getval();
	for(i=1;i<=l2;i++)
	{
		x=a.getval()[l1-i]-'0';
		y=b.getval()[l2-i]-'0';
		c[l3-i]='0'+(x+y+carry)%10;
		if(x+y+carry>=10)carry=1;
		else carry=0;
	}
	if (carry==1&&l1==l2) c="1"+c;
	if (carry==1&&l1>l2)  
	{
		c[l1-l2-1]=c[l1-l2-1]+1;
		if(c[l1-l2-1]>'9')
		{
			c[l1-l2-1]='0';
			c="1"+c;
		}
	}
	hpnumber ans(c);
	return ans;
}

//-------------------substract-------------------------------------------
hpnumber hpnumber::sub(hpnumber a,hpnumber b)
{
	string c,zero="0";
	bool negative=false;
	int l1,l2,l3,i,borrow=0;			//高精度数长度	borrow:借位 	
	hpnumber ans; 			//将c中的储存的高精度数去零后放入ans
	l1=strlen(&a.getval()[0]);
	l2=strlen(&b.getval()[0]);
	l3=max(l1,l2);
	//以下为判断正负性 
	if(l1>l2)negative=false;
	if(l1<l2)negative=true;
	if(l1==l2)
	{
		int p;
		negative=false;
		while(p<=l1-1&&a.getval()[p]>=b.getval()[p])p++;
		if(p<=l1-1)negative=true;
	}
	//---------------------------------------------------------------------- 
	if(l1<l2)
	{
		hpnumber tmp=a;
		a=b;
		b=tmp;
		l1=l1+l2;
		l2=l1-l2;
		l1=l1-l2;
	}
	c=a.getval();
	for(i=l2-1;i>=0;i--)
	{
		int x=a.getval()[i+l1-l2]-'0',y=b.getval()[i]-'0';
		c[i+l1-l2]=x-y-borrow+'0';
		if(c[i+l1-l2]<'0')
		{
			borrow=1;
			c[i+l1-l2]=c[i+l1-l2]+10;
		}
		else borrow=0; 
	}
	if(borrow==1)
		for(i=l1-l2-1;i>=0;i--)
		{
			if(borrow==0)break;
			int x=a.getval()[i]-'0';
			c[i]=x-borrow+'0';
			if(c[i]<'0')
			{
				borrow=1;
				c[i]=c[i]+10;
			}
			else borrow=0;
		}
	int p=0;
	while(p<=l3-1&&c[p]=='0')p++;
	if(p==l3){hpnumber ans(zero); 	ans.negative=negative;	return ans;}
	else { hpnumber ans(c.substr(p,l3));	ans.negative=negative;	return ans;}			
	return ans;
} 
