#include <iostream>

using namespace std;

int main()
{
  int N;
  cin>>N;
  int a[N];
  int b[N];
  int mat[N+1][N+1];
  for(int i=0; i<N; i++)
  {
     cin>>a[i];
     mat[0][i+1] = 0;
  }
  for(int i=0; i<N; i++)
  {
     cin>>b[i];
     mat[i+1][0] = 0;
  }
  mat[0][0] = 0;
  for(int i=1; i<=N; i++)
  {
    for(int j=1; j<=N; j++)
    {
      if(a[i-1] == b[j-1] )
      {
        mat[i][j] = max(mat[i][j-1]+1,mat[i-1][j]);
      }
      else if( a[i-1] != b[j-1] )
      {
        mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
      }
    }
  }
  for(int i=0; i<=N; i++)
  {
    for(int j=0; j<=N; j++)
    {
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }

}
