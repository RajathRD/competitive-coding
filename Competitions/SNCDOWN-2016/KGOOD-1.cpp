#include <bits/stdc++.h>
#include <string>

using namespace std;

int find_sum2(vector<int> &freq,int K,int sum)
{

  for(int i=0; i<freq.size(); i++)
    cout<<freq[i]<<" ";
  cout<<endl;
  int min = 1000000000;
  for(int i=0; i<freq.size(); i++)
  {
    if(freq[i] < min && freq[i] != -1)
      min = freq[i];
  }

  for(int i=0; i<freq.size(); i++)
  {
      if( freq[i] != -1 && freq[i] - min > K)
      {
        sum += freq[i] - min - K;
      }
  }
  cout<<sum<<endl;
  return sum;
}

int find_sum(vector<int> &freq1,int K)
{
  int sum = 0;
  for(int i=0; i<freq1.size(); i++)
    cout<<freq1[i]<<" ";
  cout<<endl;
  map<int,int> ffreq;
  map<int,int>::iterator iter;
  vector<int> freq;

  for(int i=0; i<freq1.size(); i++)
  {
    freq.push_back(freq1[i]);
    if( ffreq.count(freq1[i]) )
      ffreq[freq1[i]]++;
    else
      ffreq[freq1[i]] = 1;
  }

  for(int i=0; i<freq.size(); i++)
  {
    int this_sum = 0;
    if(freq[i] != -1)
    {
      for(int j=i; j<freq.size(); j++)
      {
        if( freq[j] != -1 && abs(freq[i] - freq[j]) > K)
          this_sum += (freq[i] > freq[j])?freq[i]-freq[j]-K:freq[j]-freq[i]-K;
      }
      cout<<this_sum<<" "<<ffreq[freq[i]]*freq[i]<<endl;
      if( this_sum > ffreq[freq[i]] * freq[i] )
      {
        int sum1,sum2,temp;
        sum1 = find_sum2(freq,K,sum);
        temp = freq[i];
        vector<int> freq2;
        for(int k=0; k<freq.size(); k++)
        {
          if( freq[k] == temp)
            freq2.push_back(-1);
          else
            freq2.push_back(freq[k]);
        }
        sum2 = find_sum2(freq2,K,sum+temp);
        if(sum1 > sum2)
        {
          for(int k=0; k<freq.size(); k++)
            if(freq[k] == temp)
              freq[k] = -1;
          sum += temp*ffreq[temp];
        }
      }
    }
  }
  for(int i=0; i<freq.size(); i++)
    cout<<freq[i]<<" ";
  cout<<endl;
  int min = 1000000000;
  for(int i=0; i<freq.size(); i++)
  {
    if(freq[i] < min && freq[i] != -1)
      min = freq[i];
  }

  for(int i=0; i<freq.size(); i++)
  {
      if( freq[i] != -1 && freq[i] - min > K)
      {
        sum += freq[i] - min - K;
      }
  }
  return sum;
}

int main()
{
  int count[26] = {0};
  vector<int> freq;
  int T,K;
  string s;
  cin>>T;

  while(T--)
  {
    freq.clear();
    for(int i=0; i<26; i++)
      count[i] = 0;
    cin>>s>>K;
    for(int i=0; i<s.length(); i++)
    {
      count[ s[i] - 'a' ]++;
    }
    for( int i=0; i<26; i++)
    {
      if(count[i] > 0)
        freq.push_back(count[i]);
    }

    sort(freq.begin(),freq.end());
    cout<<find_sum(freq,K)<<endl;
  }
  return 0;
}
// for(int i=0; i<freq.size(); i++)
//   cout<<freq[i]<<" ";
// cout<<endl;
