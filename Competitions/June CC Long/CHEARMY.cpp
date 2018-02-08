#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long int start(long long int N)
{
  if( N <= 5)
    return (N-1)*2;
  long long int sum = 0;
  int i;
  for(i=1; pow(5,i) <= N; i++)
  {}
  // cout<<i<<endl;
  for(int j=i-1; j>=1; j--)
  {
    // cout<<sum<<endl;
    // cout<<N<<" "<<pow(5,j);
    long long int pow5 = pow(5,j);
    long long int pow10 = pow(10,j);
    sum += ((long long int)(N/pow5) * (pow10 * 2));

    if ( j == 1)
      sum += ((N%5) * 2);
    N %= (long long int)pow(5,j);
  }
  return sum;
}

int main()
{
  int T;
  long long int K,i,num;

  cin>>T;
  // T = 1;
  while(T--)
  {
  // for(int K = 1; K<=100; K++)
  // {
     cin>>K;

      long long int result = start(K);
      if( K > 5)
      {
      if( result % 10 == 0 )
      {
        num = 1;
        i = 1;
        while( result % (long long int)pow(10,i) == 0 )
          i++;
        for(int k = 0; k < i-1; k++)
        {
          num = num*10 + 1;
        }
        num += 1;
        cout<<result - num<<endl;
      }
      else
          cout<<result - 2 << endl;
    }

    else
      cout<<result<<endl;
  // }
}
  return 0;
}
