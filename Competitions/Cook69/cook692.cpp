#include<iostream>
#include<vector>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  int M=100;
  vector<long long int> sum(M+1,0);
  long long int result;
  int T;
  int L,R;
  for(int N=1;N<=M;N+=2)
  {
      for(int i=1;N*i<=M;i++)
      {
        sum[N*i]+=N;
      }
  }
  for(int N=1;N<=M;N++)
    sum[N]+=sum[N-1];

  for(int i=0;i<M;i++)
    cout<<sum[i]<<" ";
  // cin>>T;
  //
  // while(T--)
  // {
  //   cin>>L>>R;
  //   result = sum[R] - sum[L-1];
  //   cout<<result<<"\n";
  // }
  return 0;
}
