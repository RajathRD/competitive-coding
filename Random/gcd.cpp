#include<iostream>

using namespace std;

int gcd(int a,int b)
{
   return b==0?a:gcd(b,a%b);
}

int main()
{
  int a[10],b[10],n;
  cin>>n;
  for(int i=0;i<n;i++)
   cin>>a[i];

  for(int j=0;j<n;j++)
   cin>>b[j];

  for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
   {
      int gcda = gcd(a[i],b[j]);
      if(gcda==1)
       cout<<a[i]<<" "<<b[j]<<endl;
   }
   
  return 0;
}
