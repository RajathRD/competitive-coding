#include<iostream>

using namespace std;

int main()
{
  int n;
  cin>>n;
  int a[100000],b[100000],c[100000];
  for(int i=0;i<n;i++)
  cin>>a[i];
  for(int j=0;j<n;j++)
  cin>>b[j];

  int i=0,j=0,k=0;
  while(i!=n&&j!=n)
  {
    if(a[i]<b[j])
     c[k++] = a[i++];
    else
     c[k++] = b[j++];
  }
  if(i!=n)
   while(i!=n)
    c[k++] = a[i++];
  else
   while(j!=n)
    c[k++] = b[j++];

  for(int i=0;i<2*n;i++)
   cout<<c[i]<<"\t";
  cout<<endl;
  return 0;
}
