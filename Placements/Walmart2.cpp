#include <iostream>

using namespace std;

int main()
{
  int S = 10;
  int count = 0;
  for(int i=1; i<=S; i++)
  {
    for(int j=1; j<=S; j++)
    {
      for(int k=1; k<=S; k++)
      {6;
        for(int l=1; l<=S; l++)
        {
          if( i+j+k+l == S)
          {
            count++;
            //cout<<i<<" + "<<j<<" + "<<k<<" + "<<l<<" = "<<S<<endl;
          }
        }
      }
    }
  }

  cout<<count<<endl;

  return 0;
}
