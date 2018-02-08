#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N,tail;
  cin>>N;
  int y = N/2;
  if( y%2 == 0 )
    y+=1;
  // cou:t<<y<<endl;
  for(int i=0; i<y-1 ; i++)
  {
    for(int k=0; k<i; k++)
      cout<<" ";
    cout<<"*";
    for(int j=0; j<y-(2*i); j++)
    {
      cout<<" ";
    }
    cout<<"*"<<endl;
    if( y-(2*i) == 1)
    {
      tail = i+2;
      break;
    }
  }

  for(int i=0; i<=N-tail; i++)
  {
    for(int j=0; j<tail-1; j++)
      cout<<" ";
    cout<<"*"<<endl;
  }
  return 0;
}
