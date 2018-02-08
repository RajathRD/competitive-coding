#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dig[10];
int N;
bool check(int D)
{
  // cout<<D<<endl;
  vector<int> check;
  while(D)
  {
    int d = D%10;
    check.push_back(d);
    D /= 10;
  }
  for(int i=0; i<N; i++)
  {
    // cout<<check[i]<<" "<<dig[N-i-1]<<endl;
    if( check[i] != dig[N-1-i] )
      return false;
  }
  return true;
}

int main()
{
  cin>>N;
  int min = 10;
  int sorted[N];
  for(int i=0; i<N; i++)
  {
    cin>>dig[i];
    sorted[i] = dig[i];
    if( min > dig[i] )
      min = dig[i];
  }
  sort(sorted,sorted+N, greater<int>());
  int max = 0;
  for(int i=0; i<N; i++)
  {
    max = max * 10 + sorted[i];
  }
  // cout<<max<<endl;
  for(int i=max; i>=min; i--)
  {
    if( i % 3 == 0 && check(i) )
    {
      cout<<i<<endl;
      break;
    }
  }


}
