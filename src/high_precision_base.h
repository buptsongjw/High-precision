#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class hpnumber
{
	private:
		string value;
	public:
		bool negative;
		void shownegative(){cout<<negative<<endl;}
		hpnumber(){negative=false;}
		hpnumber(string a)
		{
			negative=false;
			int i,p=0;
			while(a[p]=='0')p++;
			value=a.substr(p,strlen(&a[0]));
			 
		}
		string getval(){return &value[0];}
		friend ostream& operator<<(ostream& os,hpnumber a)
		{
			if(a.negative==0)os<<a.getval();
			if(a.negative==1)os<<"-"<<a.getval();
			return os;
		}
		hpnumber operator+(hpnumber b)  
			{
				hpnumber tmp(value);
				return add(tmp,b);
			}
		hpnumber operator-(hpnumber b)
			{
				hpnumber tmp(value);
				return sub(tmp,b);
			}
		hpnumber operator*(hpnumber b)
		{
			hpnumber tmp(value);
			return multi(tmp, b);
		}
		hpnumber add(hpnumber a,hpnumber b);
		hpnumber sub(hpnumber a,hpnumber b);
		hpnumber multi(hpnumber a,hpnumber b);
		hpnumber dvi(hpnumber a,hpnumber b);	
};
