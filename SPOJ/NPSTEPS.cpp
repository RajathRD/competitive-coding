#include<iostream>

using namespace std;

int main()
{
  int T;
  int x,y;
  cin>>T;
  while(T--)
  {
    cin>>x>>y;
    if(x==y || y==x-2)
    {
        if(x%2==0)
          cout<<x+y<<endl;
        else
          cout<<x+y-1<<endl;

    }
    else
    {
      cout<<"No Number"<<endl;
    }
  }
  return 0;
}
