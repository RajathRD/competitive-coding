#include<iostream>
#include <math.h>
using namespace std;

int main()
{
  int N;
  // cin>>N;
  for(int N=0; N<=257; N++)
  {
    string s="";
    int zero = N%4;
    if(zero==1 || zero == 2)
      s = "1";
    else
      s = "0";
    for(int i=1; N>=pow(2,i);i++)
    {
      int decide = (N-(int)pow(2,i))%(int)pow(2,i+2);
   	  if(decide >= 0 && decide <= pow(2,i+1)-1)
		    s = "1" + s;
      else
	      s = "0" + s;
    }
    cout<<N<<" -> "<<s<<endl;
  }
  return 0;
}
