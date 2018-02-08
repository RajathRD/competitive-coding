#include <bits/stdc++.h>
using namespace std;

int main()
{
  int count;
  int T;
  cin>>T;
  string test;
  for(int i=1; i<=T; i++)
  {
    cin>>test;
    count = 0;
    for(int j=test.length()-1; j>=0; j--)
    {
      if( count%2 == 0 && test[j] == '-')
        count++;
      else if( count%2 == 1 && test[j] == '+' )
        count++;
    }
    cout<<"Case #"<<i<<": "<<count<<endl;
  }
  return 0;
}
