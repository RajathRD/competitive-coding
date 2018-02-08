#include<iostream>
#include<vector>

using namespace std;

int main()
{
  int T,N,pos,max;
  vector<int> L,R,LR;
  cin>>T;
  while(T--)
  {
    cin>>N;
    L.reserve(N);R.reserve(N);LR.reserve(N);
    for(int i=0;i<N;i++)
       cin>>L[i];
    max=-1;
    for(int i=0;i<N;i++)
    {
      cin>>R[i];
      LR[i]=L[i]*R[i];
      if( LR[i] > max || LR[i]==max && R[i]>R[pos] )
      {
          max = L[i]*R[i];
        pos = i;
      }
    }
    cout<<pos+1<<"\n";
  }
  return 0;
}
