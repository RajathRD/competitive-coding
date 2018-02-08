#include<iostream>
#include <map>
#include <algorithm>
using namespace std;

bool compare(char c1,char c2)
{
  return c1<c2;
}
int main()
{
  char mapping[27] = "yhesocvxduiglbkrztnwjpfmaq";
  int T;
  cin>>T;
  string s;
  cin.ignore();
  for(int _=0; _<T; _++)
  {
    s.clear();

    getline(cin,s);
    cout<<"Case #"<<_+1<<": ";
    for(int i=0; i<s.length(); i++)
    {
      if(s[i] != ' ')
        cout<<mapping[s[i]-'a'];
      else
        cout<<" ";
    }
    cout<<endl;
  }
  // cout<<mapping<<endl;
  return 0;
}
