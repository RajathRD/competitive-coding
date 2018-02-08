#include<bits/stdc++.h>

using namespace std;

int main()
{
  int T;
  int a[100000];
  int start,high,low,minimum;
  int N,A,B;
  cin>>T;
  while(T--)
  {
    start = 1;
    cin>>N>>A>>B;
    int here = 0;
    if( A == 1 && B == 1 && N == 1)
    {
      cout<<1<<endl;
      continue;
    }
    if( N < A+B-1 || ( A == 1 && B == 1) || ( A == 1 && B != N) || ( B == 1 && A != N) )
    {
      cout<<-1<<endl;
      continue;
    }

    for(int i=0;i<A; i++)
    {
        a[here++]=start++;
    }
    high = start-1;
    start=0;
    for(int i=0;i<B-1; i++)
    {
       a[here++]=start--;
    }
    minimum = start + 1;
    low = start + 1;
    if( A + B-1 < N )
    {
      for(int i=0; i<=N-A-B; i++)
      {
        if(i%2 == 0)
          a[here++]= ++high;
        else
        {
          a[here++]= --low;
          minimum = low;
        }
      }
    }
    minimum = 1-minimum;
    if( minimum > 0 )
    {
      for(int i=0; i<N; i++)
      {
        a[i] += minimum;
      }
    }
    for(int i=0; i<N; i++)
      cout<<a[i]<<" ";
    cout<<endl;
  }
}
