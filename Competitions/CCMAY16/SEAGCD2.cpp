#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

struct node
{
  int N;
  vector<int> nums;
};
long long fact[13];

void facto( int N )
{
  for(int i = 1;i<=N;i++)
    fact[i] = (fact[i-1] * i)%MOD;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void do_magic(int N, int M)
{
  queue<node> q;
  long long count = 0;
  long long counter[101] = {0};
  node X;
  for( int i = 2;i<=M; i++)
  {
    X.nums.clear();
    X.N = 1;
    X.nums.push_back(i);
    q.push(X);
  }
  while( !q.empty() )
  {
      node check = q.front();
      if( check.N !=N )
      {
        for(int i = check.nums[check.nums.size() - 1]; i<= M; i++)
        {
          int flag = 1;
          for( int j=0; j<check.nums.size(); j++)
          {
            if( gcd(check.nums[j],i) != 1 )
            {
              flag = 0;
              break;
            }
          }
          if( flag )
          {
            check.nums.push_back(i);
            check.N ++;
            q.push(check);
            check.N --;
            check.nums.pop_back();
          }
        }
      }
      counter[check.N]++;
      q.pop();

  }
  // for(int i=1; i<=N; i++)
  // {
  //   cout<<i<<": "<<counter[i]<<endl;
  // }
  // cout<<endl;
  for(int i = 1; i<=N ; i++)
  {
    if(counter[i] == 0)
      break;
    count += counter[i] * (fact[N]/fact[N-i]);
    count %= MOD;
  }
  // cout<<"Count: "<<counter[N]<<endl;
  cout<<count+1<<endl;
}

int main()
{
  int T,N,M;
  fact[0] = 1;
  facto(100);
  cin>>T;
  // T = 1;
  while( T-- )
  {
      cin>>N>>M;
      // N=10,M=10;
      do_magic(N,M);
  }
  return 0;
}
