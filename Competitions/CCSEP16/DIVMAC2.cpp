#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int A[100000],N;
vector <int> primes;

void genPrime(int num)
{
  for(int i = 0; i < primes.size() && primes[i] <= sqrt(num); i++)
  {
    if( num % primes[i] == 0 )
      return;
  }
  primes.push_back(num);
}

int leastPrimeDivisor(int num)
{
   if( num == 1 )
    return num;
  return num;
}

int RMQ(int *a, int L, int R)
{
  int result = 1;
  for(int i=L; i<=R; i++)
  {
    result = max(result, leastPrimeDivisor(a[i]));
  }
  return result;
}

void update(int *a, int L, int R)
{
  for(int i=L; i<=R; i++)
  {
    a[i] = a[i] / leastPrimeDivisor(a[i]);
  }
  // for(int i=0; i<N; i++)
  //   cout<<a[i]<<" ";
  // cout<<endl;
}

int main()
{
  primes.push_back(2);
  for(int i=3; i<1000; i+=2)
  {
    genPrime(i);
  }

  int T;
  cin>>T;
  while(T--)
  {
    int M;
    cin>>N>>M;
    for(int i=0; i<N; i++)
      cin>>A[i];

    for(int i=0; i<M; i++)
    {
      int type,L,R;
      cin>>type>>L>>R;
      if( type == 0 )
      {
        update(A,L-1,R-1);
      }
      else
      {
        cout<<RMQ(A,L-1,R-1)<<" ";
      }
    }
    cout<<endl;
  }
  return 0;
}
