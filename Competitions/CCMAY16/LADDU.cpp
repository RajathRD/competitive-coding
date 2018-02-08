#include <iostream>

using namespace std;

int main()
{
  int T,act,val;
  int laddus;
  string type,activity;
  cin>>T;
  while(T--)
  {
    laddus = 0;
    cin>>act>>type;
    for(int i=0;i<act;i++)
    {
      cin>>activity;
      if(activity == "CONTEST_WON")
      {
        cin>>val;
        laddus += ( 20 - val <= 0 )?300: 300 + (20-val);
      }
      else if( activity == "TOP_CONTRIBUTOR" )
      {
        laddus += 300;
      }
      else if( activity == "BUG_FOUND")
      {
        cin>>val;
        laddus += val;
      }
      else if( activity == "CONTEST_HOSTED" )
      {
        laddus += 50;
      }

    }
  //  cout<<laddus<<endl;
    if( type == "INDIAN")
    {
      cout<<laddus/200<<endl;
    }
    else
    {
      cout<<laddus/400<<endl;
    }
  }
}
