#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  int M=100000;
  vector<long long int> sum(M+1,0);
  long long int result;
  int T;
  int L,R;
  for(int N=1;N<=M;N++)
  {
  //    cout<<"N:"<<N<<endl;
      int temp = sqrt(N);
      for(int i=1;i<=temp;i++)
      {
        if(N%i==0)
        {
          if(i%2==1)
          {
      //      cout<<i<<" ";
            sum[N]+=i;
          }
          if((N/i)%2==1 && N/i != i)
          {
          //    cout<<N/i<<" ";
              sum[N]+=(N/i);
          }
        }
      }
    //  cout<<endl;
  }
  for(int N=1;N<=M;N++)
    sum[N]+=sum[N-1];

  cin>>T;

  while(T--)
  {
    cin>>L>>R;
    result = sum[R] - sum[L-1];
    cout<<result<<"\n";
  }
  return 0;
}
