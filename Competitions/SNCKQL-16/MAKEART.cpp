#include<iostream>

using namespace std;

int main()
{
  int T,N,temp,i,count = 1;
  string waste;
  int check = 0;
  cin>>T;
  while(T--)
  {
    cin>>N;
    for(i=0; i<N; i++)
    {
      cin>>temp;
      if(temp == check)
        count ++;
      else
      {
        check = temp;
        count = 1;
      }
      if(count == 3)
        break;
    }
    if( i == N)
      cout<<"No"<<endl;
    else
    {
      cin.ignore(N*2);
      cout<<"Yes"<<endl;
    }
  }
}
