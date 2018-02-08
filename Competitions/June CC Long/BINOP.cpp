#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main()
{
  int T;
  string from,to;
  int count1,count0,miss1,miss0;
  cin>>T;
  while(T--)
  {
    long long change = 0;
    cin>>from;
    cin>>to;
    count1 = count0 = miss1 = miss0 = 0;
    for(int i=0; i<from.length(); i++)
    {
      if(from[i] == '1')
        count1++;
      else
        count0++;
      if(from[i] =='1' && to[i] =='0')
        miss1++;
      else if(from[i] == '0' && to[i] =='1')
        miss0++;
    }
    // cout<<count0<<" "<<count1<<" "<<miss0<<" "<<miss1<<endl;
    change += min(miss1,miss0);
    // cout<<change<<endl;
    int temp = miss0;
    miss0 = miss0 - miss1;
    miss1 = miss1 - temp;
    // cout<<miss0<<" "<<miss1<<endl;
    if(miss0 > miss1)
    {
      if( count1 != 0 )
      {
        cout<<"Lucky Chef\n"<<change+miss0<<"\n";
      }
      else
        cout<<"Unlucky Chef\n";
    }
    else
    {
      if( count0 != 0 )
      {
        cout<<"Lucky Chef\n"<<change+miss1<<"\n";
      }
      else
        cout<<"Unlucky Chef\n";
    }
  }
  return 0;
}
