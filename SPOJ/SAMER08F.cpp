#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  int temp;
  while (true)
  {
    cin>>temp;
    long long sum = 0;
    if(temp == 0)
      break;
    for(int i=1;i<=temp;i++)
    {
        sum += pow(i,2);
    }
    cout<<sum<<endl;
  }
  return 0;
}
