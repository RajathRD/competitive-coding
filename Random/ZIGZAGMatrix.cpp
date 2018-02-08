// zig zag matrix which kk suggested
/*
1 2 3 4
1 2 3 4
1 2 3 4
=
1 2 1 1 2 3 4 3 2 3 4 4
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
  int R,C;
  cin>>R>>C;
  vector<int> row;
  vector< vector<int> > mat;
  for(int i=0; i<R; i++)
  {row.clear();
     for(int j=0; j<C; j++)
    {

      int temp;
      cin>>temp;
      row.push_back(temp);
    }
    mat.push_back(row);
  }
  // for(int i=0;i<R;i++){
  //   for(int j=0; j<C; j++)
  //     cout<<mat[i][j]<<" ";
  //   cout<<endl;
  // }
  int iter = 1,i=0,j=0;
  cout<<mat[i][j]<<" ";
  while(true)
  {
    if(iter%2 == 1)
    {
      if( j+1 < C )
        j++;
      else if( i + 1 < R )
        i++;
      if( j+1 == C && i+1 == R)
      {
          cout<<mat[i][j];
          break;
      }
      while( i < R && j >= 0)
      {
        cout<<mat[i][j]<<" ";
        i++;
        j--;
      }
      i--;
      j++;
    //  cout<<endl<<"Here:" <<i<<" "<<j<<endl;
    }
    else
    {
      if( i + 1 < R )
        i++;
      else if( j+1 < C )
        j++;
      if( j+1 == C && i+1 == R)
      {
          cout<<mat[i][j];
          break;
      }
      while( i >= 0 && j < C)
      {
        cout<<mat[i][j]<<" ";
        i--;
        j++;
      }
      i++;
      j--;
    //  cout<<endl<<"Here two: "<<i<<" "<<j<<endl;
    }
    iter++;
  }

  return 0;
}
