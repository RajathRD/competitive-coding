#include <iostream>
#include <math.h>
#include <map>
#include <vector>
using namespace std;

map<int, vector<int> > Fmap;

int a[1000];
int F(int i, int j)
{
  // cout<<(a[i]&a[j])<<endl;
  return ( (i&j) == i || (i&j) == j)?true:false;
}

int main()
{
  int N;
  N = pow(2,14);
  bool visited[16384];
  for(int i=0; i<N; i++)
    visited[i] = 0;
  cout<<N<<endl;
  long long count = 0;
  for(int i=0; i<N; i++)
  {
    for(int j=i+1; j<N; j++)
    {
      if( visited[i] == 0 && visited[j] == 0 && F(i,j) )
      {
        Fmap[i].push_back(j);
        visited[i] = 1;
        visited[j] = 1;
        count++;
        // cout<<i<<" "<<j<<endl;
      }
    }
  }
  cout<<count;
}
