#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
  int N;
  vector <int> candies;

  while ( true )
  {
    long long count = 0;
    candies.clear();
    long long sum = 0;
    cin>>N;
    if( N == -1 )
      break;
    int temp;
    for (int i=0 ; i < N; i++)
    {
      cin>>temp;
      sum += temp;
      candies.push_back(temp);
    }
    long avg = sum/N;
    if(sum % N != 0)
    {
      cout<<-1<<endl;
      continue;
    }

    for (int i = 0;i < N ; i++)
    {
      if( candies[i] > avg)
      {
        count += candies[i] - avg;
      }
    }
    cout<<count<<endl;
  }
  return 0;
}
