#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
  map<char,int> count;
  map<char,int>::iterator iter;
  int T,K;
  string s;
  cin>>T;

  while(T--)
  {
    count.clear();
    cin>>s>>K;
    for(int i=0; i<s.length(); i++)
    {
      if(count.count(s[i]) == 0)
      {
        count[s[i]] = 1;
      }
      else
        count[s[i]] ++;
    }
    long long sum = 0;
    int min = (count.begin())->second;
    for(iter = count.begin(); iter!=count.end(); iter++)
    {
      if(iter->second < min)
        min = iter->second;
    }
    cout<<"Minimum count:"<<min<<endl;
    cout<<"-Count Bag-"<<endl;
    for(iter = count.begin(); iter!=count.end(); iter++)
    {
      cout<<iter->first<<" "<<iter->second<<endl;
      if(iter->second > min + K)
      {
        sum += (iter->second-min-K);
      }
    }
    cout<<sum<<endl;
  }
  return 0;
}
