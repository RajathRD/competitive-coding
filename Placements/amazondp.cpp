// largest rectangular area in histogram
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin>>N;
  int a[N];
  int dp[N][N];
  int size = N;
  for(int i=0; i<N; i++)
  {
    cin>>a[i];
  }


// DP BAG
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      if( a[j] < a[i] )
      {
        dp[i][j] = 0;
      }
      else if( a[j] >= a[i] )
      {
        dp[i][j] = a[i];
      }
    }
  }
  // KINDA KADANE ALGO
  vector<int> max_with_each;
  for(int i=0; i<N; i++)
  {
    int max = 0;

    for(int j=0; j<N; j++)
    {
      if( dp[i][j] == 0 )
      {
        cout<<max<<" "<<j<<endl;
        if( j < i )
          max = 0;
        if( j > i )
          break;
      }
      else
      {
        max += dp[i][j];
      }
    }
    max_with_each.push_back(max);
  }
  //TRACE
  for(int i=0; i<N ;i++)
  {
    for(int j=0; j<N; j++)
      cout<<dp[i][j]<<" ";
    cout<<endl;
  }

  for(int i=0; i<N; i++)
    cout<<max_with_each[i]<<" ";
  cout<<endl;
 // TRACE TILL HERE
  int max = 0;

// THIS JUST FINDS MAX IN THE POSSIBLE AREAS
  for(int i=0; i<N; i++)
  {
    if( max_with_each[i] > max )
      max = max_with_each[i];
  }
  cout<<max<<endl;

  return 0;
}
