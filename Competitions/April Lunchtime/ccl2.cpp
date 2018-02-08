#include<bits/stdc++.h>

using namespace std;

bool cmd ( long long a, long long b)
{
  return a>b;
}

int main()
{
  int N,K,count = 0,count1 = 0;
  cin>>N>>K;
  long long sum = 0;
  vector<int> v;
  v.reserve(N+1);
  vector <long long> csums;
  for(int i=0;i<N;i++)
  {
    cin>>v[i];
  }

  for(int i=N;i>=0;i--)
  {
    for(int j=0; j<N && j+i<N ;j++)
    {
      sum = 0;
      for(int k=j; k<=j+i ;k++)
      {
    //    cout<<v[k]<<" ";
        sum+=v[k];
      }
      count++;
      csums.push_back(sum);
  //   cout<<endl;
    }
    if(count >= K)
    {
      if(count1 == 1)
      {
        break;
      }
      count1 = 1;
    }
  }
 sort(csums.begin(),csums.end(), cmd);
  for(int i=0;i<K;i++)
  {
    cout<<csums[i]<<" ";
  }
  return 0;
}
