//high-precision
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class hpnumber
{
	private:
		string value;
	public:
		hpnumber(){}
		hpnumber(string a)
		{
			value=a;
		}
		char* getnum(){return &value[0];}
		hpnumber add(hpnumber a,hpnumber b);
		hpnumber sub(hpnumber a,hpnumber b);
		hpnumber muti(hpnumber a,hpnumber b);
		hpnumber dvi(hpnumber a,hpnumber b);	
};
hpnumber hpnumber::add(hpnumber a,hpnumber b)
{
	int i,carry=0,l1,l2,l3,x,y;
	string c;
	l1=strlen(a.getnum());
	l2=strlen(b.getnum());
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
	c=a.getnum();
	for(i=1;i<=l2;i++)
	{
		x=a.getnum()[l1-i]-'0';
		y=b.getnum()[l2-i]-'0';
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
