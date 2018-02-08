// infecting skin tissue
#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int main()
{
  int N,M;
  long long total_ways = 1;
  cin>>N>>M;
  int a[M];
  if( M == 1 )
  {
    cout << 1;
    return 0;
  }

  for(int i=0; i<M; i++)
  {
    cin>>a[i];
  }

  sort(a,a+M);

  for(int i=1; i<M; i++)
  {
    total_ways *= ( a[i] - a[i-1] );
    total_ways %= MOD;
  }
  cout<<total_ways<<endl;
}
