#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {

    long long int N,M,result;
    int T;
    cin>>T;

    while(T--)
    {
      cin>>N;
      cin>>M;

      if((N==1 && M==2) || (N==2 && M==1))
          cout<<"Yes"<<endl;

      else if(N==1 || M==1)
          cout<<"No"<<endl;

      else if(N%2==0 || M%2==0)
          cout<<"Yes"<<endl;

      else
          cout<<"No"<<endl;
    }
return 0;
}
