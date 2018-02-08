#include <bits/stdc++.h>

using namespace std;

int main()
{

  int N,Q,temp;
  set <int> isPresent;
  int a,b,c,d,k,l,r,j;
  vector <int> A,unique;
  cin>>N>>Q;
  int count[N];
  count[0] = 0;
  for(int i=1; i<=N; i++)
  {
    cin>>temp;
    if(isPresent.count(temp) == 0)
    {
      A.push_back(temp);
      isPresent.insert(temp);
      count[i] = count[i-1];
    }
    else{
      count[i] = count[i-1]+1;
    }
  }
  cout<<"Dup Counts"<<endl;
  for(int i=1;i<=N;i++)
  {
    cout<<count[i]<<" ";
  }
  cout<<endl;
  cin>>l>>r;
  for(int i=l-1-count[l]; i<=r-1-count[r];i++)
  {
    cout<<A[i]<<" ";
  }
  cout<<endl;
  return 0;
}
