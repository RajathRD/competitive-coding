#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{

  vector<string> names;
  int T,N;
  string name;
  cin>>T;
  for(int _=0; _<T; _++)
  {
    names.clear();
    name.clear();
    cin>>N;
    int alpha[101][26];
    for(int i=0; i<N; i++)
    {
      for(int j=0; j<26; j++)
        alpha[i][j] = 0;
    }
    cin.ignore();
    for(int i=0; i<N; i++)
    {
      getline(cin,name);
      names.push_back(name);
    }
    for(int i=0; i<N; i++)
    {
      for(int j=0; j<names[i].length(); j++)
      {
        if(names[i][j] != ' ')
          alpha[i][names[i][j]-'A'] ++;
      }
    }
    int most = 0;
    int pos = 0;
    for(int i=0; i<N; i++)
    {
      int count = 0;
      for(int j=0; j<26; j++)
      {
        if(alpha[i][j] != 0)
          count++;
      }
      if( most < count )
      {
        // cout<<"Lesser"<<endl;
        // cout<<names[pos]<<endl<<names[i]<<endl;
        // cout<<most<<" < "<<count<<endl;
        most = count;
        pos = i;

      }
      else if( most == count)
      {
        // cout<<"EQUAL"<<endl;
        // cout<<names[pos]<<endl<<names[i]<<endl;
        if( names[i] < names[pos] )
        {
          most = count;
          pos = i;
        }
      }
    }
    cout<<"Case #"<<_+1<<": "<<names[pos]<<endl;
  }
}
