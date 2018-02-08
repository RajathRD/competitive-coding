#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
  int N,K;
  cin>>N>>K;
  set<int> inf;
  int mat[K+1][N+1];
  for(int i=0; i<=K; i++)
  {
    for(int j=0; j<=N; j++)
    {
      mat[i][j] = 0;
    }
  }
  for(int i=0; i<K; i++)
  {
    int temp;
    cin>>temp;
    inf.insert(temp);
    mat[0][temp] = 1;
  }

  for(int i=0; i<=K; i++)
  {
    for(int j=0; j<=N; j++)
    {
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }

  for(int i=1; i<=K; i++)
  {
    for(int j=0; j<=N; j++)
    {
      if(j==0)
        mat[i][j] = 0;
      else if(i==0 && inf.count(j) == 0)
        mat[i][j] = 0;
      else if(j==1)
        mat[i][j] = mat[i-1][j];
      else
        mat[i][j] = mat[i-1][j] + mat[i][j-1];
    }
  }
  for(int i=0; i<=K; i++)
  {
    for(int j=0; j<=N; j++)
    {
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<mat[N][K];
}
