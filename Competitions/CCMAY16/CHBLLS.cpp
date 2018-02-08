#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  int val;
  cout<<"1\n1 2 3\n4 5\n";
  fflush(stdout);
  cin>>val;
  if( val == 0 )
  {
    cout<<"1\n4\n5\n";
    fflush(stdout);
    cin>>val;
    if( val == 1)
    {
      cout<<"2\n4"<<endl;
      return 0;
    }
    else if( val == -1)
    {
      cout<<"2\n5"<<endl;
      return 0;
    }
  }
  if( val > 0 )
  {
    cout<<1<<endl;
    cout<<"1 2\n3\n";
    fflush(stdout);
    cin>>val;
    if( val == 0)
    {
      cout<<"2\n3"<<endl;
      return 0;
    }
    else if ( val > 0)
    {
      cout<<"1\n1\n2\n";
      fflush(stdout);
      cin>>val;
      if( val == 1)
      {
      cout<<"2\n1"<<endl;
      return 0;
      }
      else if( val == -1)
      {
      cout<<"2\n2"<<endl;
      return 0;
      }
    }
  }
  return 0;
}
