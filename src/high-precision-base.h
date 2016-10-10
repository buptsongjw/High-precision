//high-precision
#include<iostream>
#include<vector>
#include<string>
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
		string getnum(){return value;}
		hpnumber add(hpnumber a,hpnumber b);
		hpnumber sub(hpnumber a,hpnumber b);
		hpnumber muti(hpnumber a,hpnumber b);
		hpnumber dvi(hpnumber a,hpnumber b);	
};
