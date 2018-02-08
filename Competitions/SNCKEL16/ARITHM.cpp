#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main()
{
  int T,N;
  LL C;
  float sum;
  cin >> T;
  while(T--)
  {
    cin>>N>>C;

    sum = ( N*(N+1) / 2 );
    if ( sum > C )
    {
       cout<<"No"<<endl;
       continue;
    }
    for( int a=C/N; a>=1; a--)
    {
      sum = ( (N/2.0)*( (2*a)+ (N-1) ) );
      float shift = (C-sum)/(float)(N-1);
      cout<<"A:"<<a<<" Sum:"<<sum<<" Shift:"<<shift<<endl;
      if( ceil(shift) == floor(shift) )
      {
        sum = ( (N/2.0)* ( (2*a) + ((N-1)*(shift)) ) );
        cout<<"Adds up to : "<< sum<<endl;
      }
    }

  }
  return 0;
}
