#include<map>
#include<iostream>
#include <set>
using namespace std;

int main()
{
  int T;
  cin>>T;
  set <int, greater<int> > r;
  map< int,int >::iterator iter;
  map < int,int,greater<int> > rank;
  while(T--)
  {
    rank.clear();
    int N,K;
    cin>>N>>K;
    int a[N];
    for(int i=0; i<N; i++)
      cin>>a[i];
    for(int i=0; i<N; i++)
    {
      if( rank.count (a[i]) )
        rank[a[i]] ++;
      else
        rank[a[i]] = 1;
    }
    int count = 0,i;
    for(iter = rank.begin(),i = 0; iter != rank.end() && i < K ; iter++,i++)
    {
      cout<<iter->first<<"->"<<iter->second<<endl;
      count += iter->second;
    }
    cout<<count<<endl;
  }
  return 0;
}
