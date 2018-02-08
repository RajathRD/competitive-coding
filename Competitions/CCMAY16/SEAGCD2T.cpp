#include <bits/stdc++.h>

using namespace std;

struct node
{
  int N;
  vector<int> nums;
};

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int do_magic(int N, int M)
{
  queue<node> q;
  int count = 0;
  node X;
  for( int i = 1;i<=M; i++)
  {
    X.nums.clear();
    X.N = 1;
    X.nums.push_back(i);
    q.push(X);
  }
  while( !q.empty() )
  {
      node check = q.front();
      if( check.N == N)
      {
        count++;
        // for( int i = 0; i<check.nums.size(); i++)
        // {
        //   cout<<check.nums[i]<<" ";
        // }
        // cout<<endl;
      }
      else
      {
        for(int i = 1; i<= M; i++)
        {
          int flag = 1;
          for( int j=0; j<check.nums.size(); j++)
          {
            if(gcd(check.nums[j],i) != 1)
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
      q.pop();

  }
  cout<<count<<endl;
}

int main()
{
  int T,N,M;
  map <int, vector<int> > excl;
  for(int i = 1; i<=10;i++)
  {
    for( int j=i; j<=10; j++)
    {
      if( gcd(i,j) == 1 )
      {
        excl[i].push_back(j);
      }
    }
  }
  // map<int,vector<int> >::iterator iter;
  // for(iter = excl.begin(); iter!=excl.end(); iter++)
  // {
  //   cout<<iter->first<<endl;
  //   for( int i = 0; i<iter->second.size();i++)
  //   {
  //     cout<<iter->second[i]<<" ";
  //   }
  //   cout<<endl;
  // }
  cin>>T;
  while( T-- )
  {
    cin>>N>>M;
    do_magic(N,M);
  }
  return 0;
}
