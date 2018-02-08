#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  int val;
  cout<<1<<"\n"<<4<<" "<<1<<" "<<2<<" "<<2<<" "<<5<<"\n"<<4<<" "<<3<<" "<<3<<" "<<4<<" "<<5<<"\n";
  fflush(stdout);
  cin>>val;
  if( val == 1 )
    cout<<"2\n1";
  if( val == 2 )
    cout<<"2\n2";
  if( val == -2 )
    cout<<"2\n3";
  if( val == -1 )
    cout<<"2\n4";
  if( val == 0 )
    cout<<"2\n5";

  return 0;
}
