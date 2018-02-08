#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007;
typedef pair<long long int, long long int> key;
long long int a,b,c,d;
map<long long int,long long int> fibs;
map<long long int,long long int>::iterator iter;
map< pair<long long int,long long int>, long long int> query;
map< pair<long long int,long long int>, long long int>::iterator iter2;

void fast_fib(long long int n,long long int ans[])
{
    if(n==0)
    {
          ans[0] = fibs[n];
          ans[1] = fibs[n+1];
          return;
    }
    else{
    fast_fib((n/2),ans);
    }
    a = ans[0];             /* F(n) */
    b = ans[1];             /* F(n+1) */
    c = 2*b - a;
    if(c < 0)
        c += MOD;
    c = (a * c) % MOD;      /* F(2n) */
    d = (a*a + b*b) % MOD;  /* F(2n + 1) */
    if(n%2 == 0)
    {
        ans[0] = c;
        ans[1] = d;
        fibs[n]=c;
        fibs[n+1]=d;
    }
    else
    {
        ans[0] = d;
        ans[1] = c+d;
        fibs[n]=d;
        fibs[n+1]=(c+d);

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    long int N,M,num1,num2,temp,count;
    long long int result,sum;
    fibs[0]=0;
    fibs[1]=1;
    vector<int> subsum;

    char querytype;
    cin>>N>>M;
    vector <long long int> a;
    a.reserve(N);

    for(long int i=0;i<N;i++)
    {
     cin>>a[i];
    }
    while(M--)
    {
      count=0;
      cin>>querytype>>num1>>num2;
      if(querytype=='C')
      {
        a[num1-1]=num2;
        query.clear();
      }

      else if(querytype=='Q')
      {
        // for(long int i=0;i<N;i++)
        //   cout<<a[i]<<" ";
        subsum.clear();
        num1=num1-1;
        num2=num2-1;
        key p(num1,num2);
        iter2=query.find(p);
        if(iter2==query.end())
        {
            result=0;
            for(long long int i=num2;i>=num1;i--)
            {
              temp=subsum.size();
              for(long long int j=0;j<temp;j++)
              {
                subsum.push_back(a[i]+subsum[j]);
              }
              subsum.push_back(a[i]);
            }
            for(long long int n=0;n<subsum.size();n++)
            {
              count++;
              iter=fibs.find(subsum[n]);
              long long int ans[2]={0,0};
              if(iter!=fibs.end())
              {
                  ans[0]=fibs[subsum[n]];
                  fibs[subsum[n]]=ans[0];
              }
              else{
                fast_fib(subsum[n],ans);
              }
              result+=ans[0];
              result=result%MOD;
           }
           query[p]=result;
        }
      else{
        result = query[p];

      }
      result=result%MOD;
      cout<<result<<"\n";
    }
   }
    return 0;
}
