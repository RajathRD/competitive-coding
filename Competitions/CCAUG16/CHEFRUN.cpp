
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int dp[100000];
bool present[100000];
bool visited[100000];

int iterative(int it, int find, int size)
{
  while( visited[it] == false )
  {
    present[it] = true;
    if( dp[it] == find )
    {
      return it;
    }
    it = dp[it];
    if( present[it] == true)
    {
      return it;
    }
  }

  return -1;
}

int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    int N;
    cin>>N;

    for(int i=0; i<N; i++)
    {
      int temp;
      cin>>temp;
      dp[i] = (i+temp+1)%N;
      present[i] = 0;
      visited[i] = 0;
    }

    int count = 0;
    for(int i=0; i<N; i++)
    {

      int key = iterative(i,i,N);

      if( key != -1 && visited[key] == 0 )
      {
        count ++;
        visited[key] = 1;
        int j = dp[key];
        while( j != key  && visited[j] == 0)
        {
          visited[j] = 1;
          j = dp[j];
          count ++;
        }
      }
      int j = i;
      while( visited[j] == 0 )
      {
        present[j] = false;
        visited[j] = true;
        j = dp[j];
      }
    }
    cout<<count<<endl;
  }
  return 0;
}
