#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <list>
using namespace std;
int main ()
{
    long long D,depth = 0;
    cin>>D;
    vector <int> val;
    int size = pow(2,D);
    val.reserve( size );
    vector <int> visited( size, 1 );

    for(int i=1 ; i<=pow(2,D) - 1; i++)
    {
          cin>>val[i];
          visited[i] = 0;
    }
    visited[0] = 0;
    int j = 1;
    for(int _ = 0; _ <D/2; _++ )
    {

      while(j>0 && visited[j] == 0)
      {
        cout<<val[j]<<" ";
        visited[j] = 1;
        j = j - 1;
      }
     j++;

     if( visited[j-1] == 1)
     {
       j = (j-1)*2 + 1;
     }
     else
      j = j*2;
      while( j < size && visited[j] == 0  )
        {
          cout<<val[j]<<" ";
          visited[j] = 1;
          j = 2*j;
        }
     j /= 2;
      while(j+1 < size && visited[j+1] == 0 )
      {
        cout<<val[j+1]<<" ";
        visited[j+1] = 1;
        j = j + 1;
      }
      j--;
      while( visited[j/2] == 0)
      {
        cout<<val[j/2]<<" ";
        j = j/2;
        visited[j] = 1;
      }
      j *= 2;
    }
    return 0;
}
