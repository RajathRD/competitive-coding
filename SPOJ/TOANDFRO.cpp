#include <iostream>
#include <vector>
#include <string>

using namespace std;

string rev(const string s)
{
  string r = "";
  for(int i=s.length()-1; i>=0; i--)
  {
    r = r + s[i];
  }
  return r;
}

int main()
{
  int N;
  string S;
  vector<string> str;
  cin>>N;
  while( N != 0 )
  {
    str.clear();
    cin>>S;
    for(int i=0; i<S.length(); i+=N)
    {
        str.push_back(S.substr(i,N));
    }
    for(int i=1; i<str.size(); i+=2)
    {
      str[i] = rev(str[i]);
    }
    for(int i=0; i<N; i++)
    {
      for(int j=0; j<str.size(); j++)
      {
        cout<<str[j][i];
      }
    }
    
    cout<<endl;
    cin>>N;
  }
  return 0;
}
