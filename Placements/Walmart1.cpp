/*
Q2. Find the maximum digit occurred in a range of prime numbers
 Eg: Range ( 21 -40) –>Prime numbers are 23,29,31,37,39
( 2 occurs 2 times, 3 occurs 4 times, 1 and 7 occur 1 time and 9 occurs 2 times ->Answer is 3)
*/

#include<iostream>
#include<math.h>
#include <map>
using namespace std;

bool isPrime(int N)
{
  int sq = sqrt(N);
  if( N%2 == 0)
    return false;
  for(int i=3; i<=sq; i+=2)
  {
    if(N%i == 0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int L,R;
  cin>>L>>R;
  map<int,int> countbag;
  countbag[0]=0;
  countbag[1]=0;
  countbag[2]=0;
  countbag[3]=0;
  countbag[4]=0;
  countbag[5]=0;
  countbag[6]=0;
  countbag[7]=0;
  countbag[8]=0;
  countbag[9]=0;
  if(L%2 == 0)
    L++;
  for(int i = L; i<=R; i+=2)
  {
    if(isPrime(i))
    {
      int check = i;
      // cout<<check<<endl;
      while(check>0)
      {
        int temp = check % 10;
        countbag[temp]++;
        check /= 10;
      }
    }
  }
  int max = 0;
  int pos = 0;
  map<int,int>::iterator iter;
  for(iter = countbag.begin(); iter != countbag.end(); iter++)
  {
    // cout<<iter->first<<" "<<iter->second<<endl;
    if( max <= iter->second )
    {
      max = iter->second;
      pos = iter->first;
    }
  }
  cout<<pos<<endl;
  return 0;
}
