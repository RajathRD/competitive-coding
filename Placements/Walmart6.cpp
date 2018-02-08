/*
Q1. Given n strings consisting of ‘R’ and ‘B’. Two strings can be only combined if last character of first string and first character of second string are same. Given n strings, you have to output the maximum length possible by combining strings.

I/P
RBR
BBR
RRR

O/P
9
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;g++

bool compare( string s1, string s2)
{
  return s1.length()>s2.length();
}

int main()
{
  vector< string > v;
  int N;
  cin>>N;
  v.reserve(N);
  bool r[N],l[N],vis[N];
  for(int i=0; i<N; i++)
  {
    string temp;
    cin>>temp;
    v.push_back(temp);
  }

  sort(v.begin(), v.end(), compare);

  for(int i=0; i<N; i++)
  {
    int sizeI = v[i].length();
    for(int j=i+1; j<N; j++)
    {
      int sizeJ = v[j].length();
      if(v[i][sizeI-1] == v[j][0])
      {
        r[i] = true;
        l[j] = true;
        vis[i] = true;
        vis[j] = true;
      }
      else if( v[i][0] == v[j][sizeI-1] )
      {
        r[j] = true;
        l[i] = true;
        vis[i] = true;
        vis[j] = true;
      }
    }
  }
  int len = 0;
  for(int i=0; i<N; i++)
  {
    if( vis[i] == true )
      len = len + v[i].length();
  }
  cout<<len<<endl;
}
