#include<iostream>
#include <map>
using namespace std;


int main()
{
  int N;
  cin>>N;

  int a[N],b[N];
  for(int i=0; i<N; i++)
    cin>>a[i];
  for(int i=0; i<N; i++)
    cin>>b[i];
  map<int,int> bag;
  map<int,int> a2b;

  for(int i=0; i<N; i++ )
    a2b[b[i]] = i;

  for(int i=N-1; i>=0; i--)
  {
    int max = 1;
    for(int j=i+1; j<N; j++)
    {
      if( a2b[a[i]] < a2b[a[j]] )
      {
        if( max < bag[ a[j] ] + 1 )
          max = bag[ a[j] ] + 1;
      }
    }
    bag[a[i]] = max;
  }

  int max = 0;
  for(auto & iter : bag)
  {
    if( iter.second > max )
      max = iter.second;
  }
  cout<<max<<endl;

}

//T!o@T#w$H%t^F&i*Fi03041933
