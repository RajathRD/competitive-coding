#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#define M 1000000007
using namespace std;

int fast_pow(long long base, long long n,long long M)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
    {
        return ( halfn * halfn ) % M;
    }
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}


int main() {

    long long int N,K,result;
    int T;
    cin>>T;
//    T=1;
    while(T--)
    {
      cin>>N;
      cin>>K;
  //    N=1000000000;
  //    K=1000000000;
  //        for(int i=0;i<N-1;i++)
  //    {
        result = fast_pow(K-1,N-1,1000000007);
  //      cout<<result<<endl;
        result=result*(K);
        result=result%1000000007;
        cout<<result<<endl;
//      }
  //    cout<<result<<endl
    }
return 0;
}
