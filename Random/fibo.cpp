#include <bits/stdc++.h>
using namespace std;
map<int,int > f;
void fib(int N)
{
  if( f.count(N-1) == 0 )
    fib(N-1);
  if( f.count(N-2) == 0 )
    fib(N-2);
  f[N] = f[N-1]+f[N-2];
  f[N] %= 1000000007;
}

int main()
{
  f[1] = 0;
  f[2] = 1;
  fib(100000);

  map<int,int>::iterator iter;
  for(iter=f.begin(); iter != f.end(); iter++)
  {
    cout<<iter->first<<" "<<iter->second<<endl;
  }
  return 0;
}
