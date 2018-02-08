#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  long long int T,N,M;
  cin>>T;
  while(T--)
  {
    cin>>N>>M;
    if( ( (N * M)-1 ) % 2 == 1 )
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
  return 0;
}
