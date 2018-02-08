#include <bits/stdc++.h>

using namespace std;

int main()
{
  string enc;
  cin>>enc;
  int a = ceil(sqrt( enc.length() ) );
  char mat[a][a];
  int nrow = a;
  int k = 0;

  for(int i=0; i<a; i++)
    for(int j=0; j<a; j++)
      mat[i][j] = '0';
  int i;
  for(i=0; i<a; i++)
  {
    for(int j=0; j<nrow; j++)
    {
      mat[i][j] = enc[k++];
    }
    if( ( enc.length() - k ) % (a-i-1) == 0 )
    {
        nrow = ( enc.length() - k ) / (a-i-1);
        cout<<"break";

        break;
    }
  }
  cout<<nrow<<endl;
  ++i;
  for(;i<a; i++)
  {
    for(int j=0; j<nrow; j++)
    {
      mat[i][j] = enc[k++];
    }
  }
  for(i=0; i<a; i++)
  {
    for(int j=0; j<a; j++)
      cout<<mat[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}
