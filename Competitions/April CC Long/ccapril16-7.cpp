// never use a while loop to decrement values needed later
#include<bits/stdc++.h>

using namespace std;

int main()
{
  long int T,parent,child,cost,max;
  long long int N;
  vector<long int> costs;
  cin>>T;

  while(T--)
  {
    costs.clear();
    cin>>N;
    if(N==1)
    {
      cout<<0<<endl;
    }
    else{
          N=N-1;

          for(int i=0;i<N;i++) //mistake used a while(N--) here
          {
            cin>>parent>>child>>cost;
            costs.push_back(cost);
          }

          max=costs[0];

          for(int i=1;i<costs.size();i++)
          {
            if(max<costs[i])
              max=costs[i];
          }

          cout<<max<<endl;

          for(int j=0;j<N;j++)
          {
            cout<<0<<endl;
          }

        }
    }
  return 0;
}
