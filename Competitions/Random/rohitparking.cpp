#include<iostream>
#include<map>
#include<vector>
#include<stdlib.h>
#include<string>

using namespace std;

int main()
{
  int T,Q,N,type,num,result,hour,min;
  float totaltime;
  string timee,ampm,hours,minutes;
  cin>>T;
  map<float,int> query;
  map<float,int>::iterator iter;
  vector<float> check;

  while(T--)
  {
    check.clear();
    cin>>Q>>N;
    query.clear();
    while(Q--)
    {

      cin>>type;
      cin>>timee>>ampm;
      hours=timee.substr(0,2);
      minutes=timee.substr(3,2);
      hour=atoi(hours.c_str());
      if(ampm=="PM")
        hour+=12;
      min=atoi(minutes.c_str());
      totaltime=hour+ ((float)min/60.0);

  //    cout<<type<<" "<<totaltime<<" ";

      if(type==1 || type==2)
      {
        cin>>num;
  //      cout<<num<<endl;
        if(type==1)
        {
          query[totaltime]=num;
        }
        else if(type==2)
        {
          query[totaltime]= -num;
        }
      }
      else if(type==3)
      {
  //      cout<<endl;
        check.push_back(totaltime);
      }

    }
    for(int i=0;i<check.size();i++)
    {
      result=N;
      iter=query.begin();
      while(iter!=query.end() && iter->first<=check[i])
      {
        result+=iter->second;
        iter++;
      }
      cout<<result<<endl;
    }
  }

  return 0;
}
