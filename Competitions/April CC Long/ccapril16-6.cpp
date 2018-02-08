#include<bits/stdc++.h>
#include<string>

using namespace std;

bool check(string s)
{
  int count=0;
  if(s.length()>2)
    for(int i = 0;i<s.length()-2;i++)
    {
      if((s[i+1]-s[i])==(s[i+2]-s[i+1]) || (s[i]==s[i+1] && s[i+1]==s[i+2]))
        return false;
    }
    return true;
}

int main()
{
  int T,A,distance;
  long int count;
  set<string> unique,considered;
  set<string>::iterator it,it2,it3;
  set<string> results,finalset;
  string str;
  cin>>T;
  while(T--)
  {
    count=0;
    considered.clear();
    unique.clear();
    finalset.clear();
    results.clear();
    string alpha = "abc";
    cin>>A>>distance;
    alpha=alpha.substr(0,A);
    cin>>str;

    if(check(str))
      count=1;
    finalset.insert(str);
    unique.insert(str);

    string new_str,onestring=str;
    for ( int d=0;d<distance;d++)
    {
    //  cout<<"Distance : "<<d+1<<endl;
      for(it=unique.begin();it!=unique.end();it++)
      {
      //  cout<<"Considering: "<<*it<<endl;
        it3=considered.find(*it);
        if(it3==considered.end())
        {
              considered.insert(*it);
              for( int pos=0; pos< (*it).length();pos++)
              {
            //  cout<<pos<<" "<<(*it).length()<<endl;
                for( int i=0;i<alpha.length();i++)
                {

                  onestring=*it;
                  if(onestring[pos]!=alpha[i])
                    {
                      onestring[pos]=alpha[i];
                    }
                   it2=finalset.find(onestring);

                   if(it2==finalset.end())
                   {
                     results.insert(onestring);
                      if(check(onestring))
                      {
                  //   cout<<onestring<<endl;
                        count++;
                        finalset.insert(onestring);
                      }
                  }
                }
              }
          }
      }
     unique.clear();
     for(it2=results.begin();it2!=results.end();it2++)
     {
       unique.insert(*it2);
     }
     results.clear();
    }
    cout<<count%1000000007<<endl;
  }

  return 0;
}
