
#include <iostream>
#include <cmath>
#include <algorithm>
#include<math.h>
#include <vector>

#define ll long long

using namespace std;

/*
 * Sieve of Atkins
 */
void sieve_atkins(ll int n,vector<ll int> &prime)
{
    vector<bool> is_prime(n + 1);
    is_prime[2] = true;
    is_prime[3] = true;
    for (ll int i = 5; i <= n; i++)
    {
        is_prime[i] = false;
    }
    ll int lim = ceil(sqrt(n));
    for (ll int x = 1; x <= lim; x++)
    {
        for (ll int y = 1; y <= lim; y++)
        {
            ll int num = (4 * x * x + y * y);
            if (num <= n && (num % 12 == 1 || num % 12 == 5))
            {
                is_prime[num] = true;
            }
            num = (3 * x * x + y * y);
            if (num <= n && (num % 12 == 7))
            {
                is_prime[num] = true;
            }

            if (x > y)
            {
                num = (3 * x * x - y * y);
                if (num <= n && (num % 12 == 11))
                {
                    is_prime[num] = true;
                }
            }
        }
    }
    for (ll int i = 5; i <= lim; i++)
    {
        if (is_prime[i])
        {
            for (ll int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    for (ll int i = 2; i <= n; i++)
    {
         if (is_prime[i])
         {
             prime.push_back(i);
         }
    }
}

int main()
{
    int T,flag;
    
    vector<ll int> divide;
    vector<ll int>::iterator iter;
    ll int start,end,sqroot;
    sieve_atkins(1000000,divide);
    // cin>>T;
    T = 10;
    while(T--)
    {
        start = 100;
        end = 0;
    //   cin>>start>>end;
      if(start==1)
        start++;
      for(int i=start;i<=end;i++)
      {

          flag=1;
          sqroot=sqrt(i);
          for(iter=divide.begin();(*iter)<=sqroot;iter++)
          {
              if(i%(*iter)==0)
              {
                  flag=0;
                  break;
              }
          }
          if(flag)
            cout<<i<<"\n";
      }
    }
    return 0;
}
