#include <iostream>

using namespace std;

int main()
{
  long long product = 1;
  for(int i=1; i<=100; i++)
  {
    product = product * i;
    cout<<i<<" "<<product<<endl;
  }
}
