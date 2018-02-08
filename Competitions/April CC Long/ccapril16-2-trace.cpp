#include<iostream>

using namespace std;

int main()
{
  int T;
  long int numofballoons[3],K,count=0;
  cin>>T;
//T=1;
  while(T--)
  {

    count=0;
    // numofballoons[0]=1000000000;
    // numofballoons[1]=1000000000;
    // numofballoons[2]=1000000000;
    for(int i=0;i<3;i++)
      cin>>numofballoons[i];
    //  K=1000000000;
    cin>>K;
     for(int i=0;i<K-1;i++)
      {
       cout<<numofballoons[0]<<" "<<numofballoons[1]<<" "<<numofballoons[2]<<endl;
    //    K=K-1;
        count+=3;
        if(numofballoons[0]<=0)
          count--;

        if(numofballoons[1]<=0)
          count--;

        if(numofballoons[2]<=0)
          count--;

        numofballoons[0]-=1;
        numofballoons[1]-=1;
        numofballoons[2]-=1;
    //    cout<<numofballoons[0]<<" "<<numofballoons[1]<<" "<<numofballoons[2]<<endl;

        cout<<i+1<<" - Count: "<<count<<endl;
      }

    cout<<count+1<<endl;
  }
  return 0;
}
