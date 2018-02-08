#include<iostream>
#include<math.h>
using namespace std;

int main()
{
  int N,K;
  long long count = 0;
  cin>>N;
  for(int i=1; i<=(int)sqrt(N); i++)
  {
    if(N%i == 0)
    {
      count += (N/i) - i + 1;
      // cout<<i<<" "<<N/i<<endl;
    }
  }
  cout<<count;
  return 0;
}
