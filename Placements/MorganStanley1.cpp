#include <iostream>
#include <stack>

using namespace std;

int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    string s1;
    string s2;
    string common="";
    cin>>s1;
    cin>>s2;
    if( s2[s2.length()-1] == '#' && s1[0] == '#' )
    {
      string temp;
      temp = s1;
      s1 = s2;
      s2 = temp;
    }
    if( s1[s1.length()-1] == '#' && s2[0] == '#' )
    {
      stack<char> st;
      for(int i=0; i<s1.length()-1 ; i++)
        st.push(s1[i]);
      for(int i=s2.length()-1; i>0; i--)
      {
        if( st.top() == s2[i] )
          st.pop();
        common = s2[i]+common;
      }
      while(!st.empty())
      {
        common = st.top() + common;
        st.pop();
      }
    }
    else if( s1[s1.length()-1] == '#' && s2[s2.length()-1] == '#')
    {
      string first = (s1.length() > s2.length())?s1:s2;
      string second = (s1.length() > s2.length())?s2:s1;
      stack<char> st;
      for(int i=0; i<second.length()-1; i++)
        st.push(second[i]);
      for(int i=first.length()-2; i>=0; i--)
        if(st.top() == first[i])
          st.pop();
      if(st.empty())
        common = first.substr(0,first.length()-1);
      else
      {
        common = "impossible";
      }
    }
    else
      common = "impossible";
    cout<<common<<endl;
  }

  return 0;
}
