#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N,T;
  long val[44723];
  for(int i=1;i<44722;i++)
  {
   long result = (i*i + i)/2;
   val[i] = result;
  }
  cin>>T;
  while(T--)
  {
    cin>>N;
    int i;
    for(i=1;val[i]<=N;i++);
    cout<<i-1<<endl;
  }
  return 0;
}
