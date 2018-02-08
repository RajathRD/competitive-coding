#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
  char ch;
  int count;
};

int find( vector<node>& v, char ch )
{
  for(int i=0; i<v.size(); i++)
  {
    if( v[i].ch == ch )
    {
      v[i].count++;
      return i;
    }
  }
  return -1;
}

bool compare( node s1, node s2 )
{
  return s1.count>s2.count;
}

int exchange( vector<node> s1, vector<node> s2, int size )
{
  for(int i=0; i<s1.size(); i++)
  {
    int add = find(s2,s1[i].ch);
    if( add != -1 )
    {
      s1[i].count += s2[add].count;
    }
  }
  int sum = 0,i;
  for(i=0; sum <= size ; i++)
  {
    sum += s1[i].count;
  }
  // cout<<sum<<" "<<i<<endl;
  return i;
}

int main()
{
  string s1,s2;
  cin>>s1;
  cin>>s2;
  vector<node> hash1;
  vector<node> hash2;
  for(int i=0; i<s1.length(); i++)
  {
    int add = find(hash1,s1[i]);
    if( add == -1)
    {
      node temp;
      temp.ch = s1[i];
      temp.count = 1;
      hash1.push_back(temp);
    }
  }
  for(int i=0; i<s2.length(); i++)
  {
    int add = find(hash2,s2[i]);
    if( add == -1)
    {
      node temp;
      temp.ch = s2[i];
      temp.count = 1;
      hash2.push_back(temp);
    }
  }
  sort(hash1.begin(),hash1.end(),compare);
  sort(hash2.begin(),hash2.end(),compare);
  for(int i=0; i<hash1.size(); i++)
  {
    cout<<hash1[i].ch<<" "<<hash1[i].count<<"\t";
  }
  cout<<endl;
  for(int i=0; i<hash2.size(); i++)
  {
    cout<<hash2[i].ch<<" "<<hash2[i].count<<"\t";
  }
  cout<<endl;
  int res = min ( exchange(hash1,hash2,s1.length()), exchange(hash2,hash1,s2.length()));
  cout<<res<<endl;
}
