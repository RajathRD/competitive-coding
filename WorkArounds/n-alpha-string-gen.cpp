#include<bits/stdc++.h>
#include<string>

using namespace std;

string given;
int k,diff=0;

bool check(string s)
{
  int count=0;
  if(s.length()>2)
    for(int i = s.length()-1;i>1;i--)
    {
      if((s[i]-s[i-1])==(s[i-1]-s[i-2]) || (s[i]==s[i-1] && s[i-1]==s[i-2]))
        return false;
    }
  return true;
}

int possibleStrings(int maxLength, string alphabet, string curr)
{
  static int count=0;
  if(curr.length()==maxLength)
  {
    if(check(curr))
    {
      count++;
      cout<<curr<<"\n";
    }
  }
  else
  {
    for(int i=0;i<alphabet.length();i++){
      string oldCurr = curr;
      curr += alphabet[i];
      possibleStrings(maxLength,alphabet,curr);
      curr = oldCurr;
    }
  }
  return count;
}

int main()
{
  ios_base::sync_with_stdio(false);
  int T,A;
//  cin>>T;
  T=1;
  while(T--)
  {
    given.clear();
    k=3;
    string alphabet = "abc";
  //  cin>>A>>k;
    A=3;
    alphabet=alphabet.substr(0,A);
  //  cout<<alphabet<<endl;
  //  given="aaccbcbbcaa";
  //  cin>>given;
    int result=possibleStrings(3,alphabet,"");
    cout<<result-diff<<endl;
    diff=result;

  }
  return 0;
}
