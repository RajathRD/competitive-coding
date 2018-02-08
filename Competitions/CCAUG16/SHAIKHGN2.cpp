#include <iostream>

using namespace std;

int visited[500];
int adj[500];

void get_cycle(int i, int k)
{
  int j = adj[i];
  if( k == 0 )
  {
    cout<<1<<endl<<i+1<<endl;
    return;
  }
  if( i == j )
  {
    cout<<1<<endl<<i+1<<endl;
    return;
  }
  visited[i] = 1;
  int count = 1;
  while( j != i )
  {
    visited[j] = 1;
    if( j == -1 )
    {
      if( count == k )
      {
        cout<<1<<endl<<j+1<<endl;
        return;
      }
      else
      {
        cout<<0<<endl<<-1<<endl;
        return;
      }
    }
    if( count == k )
    {
      cout<<1<<endl<<j+1<<endl;
      return;
    }
    if( visited[j] == 1)
    {
      break;
    }
    j = adj[j];
    count++;
  }
  int z = i;
  count = 0;
  while( z != j )
  {
    z = adj[z];
    count++;
  }
  z = adj[j];
  int cycle_count = 1;
  while( z != j )
  {
    z = adj[z];
    cycle_count++;
  }
  for(int i=0; i<((k-count)%cycle_count); i++)
  {
    j = adj[j];
  }
  cout<<1<<endl<<j+1<<endl;
}

int main()
{
  int N,M;
  cin>>N;

  for(int i=0; i < 500; i++)
  {
    visited[i] = 0;
    adj[i] = -1;
  }

  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      int temp;
      cin>>temp;
      if( temp == 1 )
      {
        adj[i] = j;
      }
    }
  }
  // for(int i=0; i<N; i++)
  // {
  //   cout<<adj[i]<<" ";
  // }
  // cout<<endl;
  cin>>M;
  while(M--)
  {
    int K,x;
    cin>>K>>x;
    for(int i=0; i < 500; i++)
    {
      visited[i] = 0;
    }
    get_cycle(x-1,K%N);
  }

  return 0;
}
