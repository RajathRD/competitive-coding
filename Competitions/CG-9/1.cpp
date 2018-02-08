#include <bits/stdc++.h>

using namespace std;

int main()
{
  int X,Y,N,Q,i;
  cin>>N;
  int a[10000];
  for(int i=0; i<N; i++)
  {
    cin>>a[i];
  }

  cin>>Q;
  while(Q--)
  {
    cin>>X>>Y;
    int count = 0;
    for(i=0; i<N; i++)
    {
      if( a[i] >= X )
        count++;
      if( count == Y )
        break;
    }
    if( count < Y )
      cout<<-1<<endl;
    else
      cout<<a[i]<<endl;
  }
}
