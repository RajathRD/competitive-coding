#include <stdio.h>
#include <iostream>
#include <vector>
#define M 1000000007
typedef long long int ll;

using namespace std;

void query2 (int R,const vector<int> &v)
{
  ll product = 1;
  int size = v.size();

  for(int i=0; i<size; i += R)
  {
      product = product * v[i];
      product %= M;
  }
  cout<<product%M<<endl;
}

void query1( int P, int F, vector<int> &v)
{
  v[P-1] = F;
}
int main()
{
  int N,Q,query,T;
  vector<int> v;
  cin>>N;
  v.reserve(N);
  for(int i=0; i<N; i++)
  {
    int temp;
    scanf("%d",&temp);
    v.push_back(temp);
  }
  cin>>Q;
  while(T--)
  {
    cin>>query;
    switch(query)
    {
      case 1:
            int p,F;
            cin>>p>>F;
            query1(p,F,v);
      case 2:
            int R;
            cin>>R;
            query2(R,v);
    }
  }
  return 0;
}
