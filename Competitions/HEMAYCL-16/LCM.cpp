#include <bits/stdc++.h>
using namespace std;

long long gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
  return a * ( b / gcd (a,b));
}

long long do_magic(long long M, long long N)
{
  long long result = 1;
  for(int i = M;i <= N; i++)
  {
    result = lcm(result,i);
  }
  cout<<"From:"<<M<<"-"<<N<<endl;
  cout<<"LCM: "<<result<<endl;
}

long long do_magic(long long N)
{
  long long result = 1;
  for(int i = 2;i <= N; i++)
  {
    result = lcm(result,i);
  }
  cout<<"From 1 to "<<N<<endl;
  cout<<"LCM: "<<result<<endl;
}

int main()
{
  long long N,M;
  cin>>N;
  do_magic(N);
  cin>>M>>N;
  do_magic(M,N);
  return 0;
}
