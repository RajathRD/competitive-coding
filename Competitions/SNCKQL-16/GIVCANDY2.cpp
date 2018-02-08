#include<iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

long long gcd(long long a, long long b)
{
  return (b==0)?a:gcd(b,b%a);
}

int main()
{
  int T;
  long long A,B,C,D;
  cin>>T;
  while(T--)
  {
    cin>>A>>B>>C>>D;
    if(C==D)
    {
      long long d= abs(A-B);
      ans = max(A,B) - (min(A,B) + C*(d/C)+C);
      cout<<min(d,d%C)<<endl;
    }
    else if(gcd(C,D) == 1)
      cout<<0<<endl;
    else
    {
      cout<<min(abs(A-B),gcd(C,D))<<endl;
    }
  }
}
