#include<iostream>

using namespace std;

int gcd(int a,int b)
{
  return b==0?a:gcd(b,a%b);
}

int lcm(int a,int b)
{
  int pr = a*b;
  return pr/gcd(a,b);
}

int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  int p = lcm(lcm(a,b),c);
  cout<<p<<endl;
  return 0;
}
