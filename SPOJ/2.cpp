#include<iostream>

using namespace std;

typedef long long int l;

l reverse(l a)
{
  l rev=0,temp;
  while(a>0)
  {
    temp = a%10;
    rev=rev*10+temp;
    a/=10;
  }
  return rev;
}

int main()
{
  ios_base::sync_with_stdio(false);
  int N;
  l a,b,sum=0;
  cin>>N;
  while(N--)
  {
    cin>>a;
    a=reverse(a);
    cin>>b;
    b=reverse(b);
    sum=a+b;
    sum=reverse(sum);
    cout<<sum<<"\n";
  }
  return 0;
}
