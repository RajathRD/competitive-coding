// 2+3+5+7=17 , number of sums of primes from 2 to N being integers.
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(const vector<long long>& prime, long long N)
{
  for(int i=0; prime[i]<= sqrt(N); i++)
  {
    if( N % prime[i] == 0 )
      return 0;
  }
  return 1;
}

int main()
{
  vector<long long> prime;
  long long N;
  cin>>N;
  prime.push_back(2);

  for(long long i=3; i<552400 ; i+=2 )
  {
    if( isPrime(prime,i) )
    {
      prime.push_back(i);
    }
  }
  int count=0;
  long long curr_num = 2;
  for(int i=1; curr_num + prime[i]<= N; i++)
  {
    curr_num += prime[i];
    if( isPrime( prime,curr_num) )
    {
      count++;
    }
  }
  cout<<count<<endl;

}
