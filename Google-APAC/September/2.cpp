#include<iostream>

using namespace std;
int M[3000][3000];
void printMaxSubSquare(int R, int C)
{
  int i,j;
  int S[R][C];
  int max_of_s, max_i, max_j;

  for(i = 0; i < R; i++)
     S[i][0] = M[i][0];

  for(j = 0; j < C; j++)
     S[0][j] = M[0][j];

  for(i = 1; i < R; i++)
  {
    for(j = 1; j < C; j++)
    {
      if(M[i][j] == 1)
        S[i][j] = min( S[i][j-1], min(S[i-1][j], S[i-1][j-1]) ) + 1;
      else
        S[i][j] = 0;
    }
  }

  max_of_s = S[0][0]; max_i = 0; max_j = 0;
  for(i = 0; i < R; i++)
  {
    for(j = 0; j < C; j++)
    {
      if(max_of_s < S[i][j])
      {
         max_of_s = S[i][j];
         max_i = i;
         max_j = j;
      }
    }
  }

  for(i = max_i; i > max_i - max_of_s; i--)
  {
    for(j = max_j; j > max_j - max_of_s; j--)
    {
      cout<<M[i][j]<<" ";
    }
    cout<<endl;
  }
}

/* Driver function to test above functions */
int main()
{
  int T,R,C,K;
  cin>>T;
  while(T--)
  {
    for(int i=0; i<R; i++)
      for(int j=0; j<C; j++)
        M[i][j] = 0;
    cin>>R>>C>>K;
    for(int i=0; i<K; i++)
    {
      int temp1,temp2;
      cin>>temp1>>temp2;
      M[temp1][temp2] = 1;
    }
    for(int i=0; i<R; i++)
    {
      for(int j=0; j<C; j++)
      {
        if( M[i][j] == 0 )
          M[i][j] = 1;
        else
          M[i][j] = 0;
      }
    }
    printMaxSubSquare(R,C);
  }
}
