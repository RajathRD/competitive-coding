#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007;
typedef pair<long long int, long long int> key;
long long int a,b,c,d;
map<long long int,long long int> fibs;
map<long long int,long long int>::iterator iter;
map< pair<long long int,long long int>, long long int> query;
map< pair<long long int,long long int>, long long int>::iterator iter2;

long long int f(long long int n) {
	if (fibs.count(n)) return fibs[n];
	long long int k=n/2;
	if (n%2==0) { // n=2*k
		return fibs[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % MOD;
	} else
   { // n=2*k+1
		return fibs[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % MOD;
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
//  vector <long long int> a;
  //a.reserve(N);
//  cin>>N>>M;
//  vector <long long int> a;
//  a.reserve(N);
 M=1;
 N=120;
 long long a[120]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120};
  // for(long int i=0;i<N;i++)
  // {
  //  cin>>a[i];
  // }
  while(M--)
  {
    querytype='Q';
    num1=1;
    num2=2;
  //  cin>>querytype>>num1>>num2;
      if(querytype=='C')
      {
        a[num1-1]=num2;
        query.clear();
      }
      else if(querytype=='Q')
      {
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
                cout<<a[i]+subsum[j]<<endl;
                subsum.push_back(a[i]+subsum[j]);
              }
              subsum.push_back(a[i]);
            }
            for(long long int n=0;n<subsum.size();n++)
            {
              count<<subsum[n];
            }
          //     count++;
          //     if(!fibs.count(subsum[n]))
          //     {
          //         f(subsum[n]);
          //     }
          //     result+=fibs[subsum[n]];
          //     result=result%MOD;
          //  }
          //  query[p]=result;
        }
      else{
      //  result = query[p];
      }
    //  cout<<result<<"\n";
    }

   }
    return 0;
}
