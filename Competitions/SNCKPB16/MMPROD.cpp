#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T;
  int N,K;
  int pos,neg;
  long long prod;
  int apos[100000];
  int aneg[100000];
  cin>>T;
  while(T--)
  {
    pos = 0;
    neg = 0;

    cin>>N>>K;

    for(int i=0; i<N; i++)
    {
      int temp;
      cin>>temp;
      if( temp >= 0 )
        apos[pos++] = temp;
      else
        aneg[neg++] = temp;
    }
    if( pos > 0 )
      sort(apos,apos+pos);
    if(neg > 0)
      sort(aneg,aneg+neg);
    // for(int i=0; i<pos; i++)
    //   cout<<apos[i]<<" ";
    // cout<<endl;
    // for(int i=0; i<neg; i++)
    //   cout<<aneg[i]<<" ";
    // cout<<endl;
  }
}
