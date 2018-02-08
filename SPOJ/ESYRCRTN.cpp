#include<iostream>

using namespace std;

int main()
{
  int a[] = {1,4,6,5,2,0};
  int T;
  long long N;
  cin>>T;
  while(T--)
  {
    cin>>N;
    cout<<a[(N-1)%6]<<endl;
  }
  return 0;
}
