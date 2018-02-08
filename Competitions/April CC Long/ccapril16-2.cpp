#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  int T;
  long long int numofballoons[3],K,count=0;
  cin>>T;
//  T=1;
  while(T--)
  {
    count=0;
    for(int i=0;i<3;i++)
      cin>>numofballoons[i];
    cin>>K;
    // K=1000000000;
    // numofballoons[0]=1000000000;
    // numofballoons[1]=1000000000;
    // numofballoons[2]=1000000000;
    if(K<=min(numofballoons[0],min(numofballoons[1],numofballoons[2])))
    {
      K=K-1;
      count=(3*K)+1;
    }
    else
    {
    // numofballoons[0]-=K;
    // numofballoons[1]-=K;
    // numofballoons[2]-=K;
    if(numofballoons[0]>=K)
      count+=(K-1);
    else
      count+=numofballoons[0];

    if(numofballoons[1]>=K)
      count+=(K-1);
    else
      count+=numofballoons[1];
    if(numofballoons[2]>=K)
      count+=(K-1);
    else
      count+=numofballoons[2];

    count+=1;
    }
    cout<<count<<endl;
  }
  return 0;
}
