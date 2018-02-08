/*Find Maximum sum in an array such that no 2 elements are adjacent.
 In this, 1 more condition was also there that first and last elements should also not be taken together.
*/
#include<iostream>

using namespace std;

int main()
{
  int N;
  cin>>N;
  int a[N];
  int b[N];
  for(int i=0; i<N; i++)
  {
    cin>>a[i];
    b[i]=a[i];
  }
  for(int i=3; i<N; i++)
  {
    a[i] = max(a[i-1],a[i]+a[i-2]);
  }
  for(int i=2; i<N-1; i++)
  {
    b[i] = max(b[i-1],b[i]+b[i-2]);
  }
  cout<<max(a[N-1],b[N-1])<<endl;
  return 0;
}
