#include<iostream>
#include<math.h>

using namespace std;

bool isprime(int n)
{
  if(n==2)
   return 1;

  for(int i=2;i<=sqrt(n);i++)
   if(n%i==0)
    return 0;
   return 1;
}
int main()
{
  int start,end;
  cin>>start>>end;
  for(int i=start;i<=end;i++)
  {
    if(isprime(i))
     cout<<i;

  }
  return 0;
}
