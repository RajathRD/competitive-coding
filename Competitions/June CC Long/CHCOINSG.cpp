#include <iostream>

using namespace std;

int main()
{
string s;
int T,N;
cin>>T;
while(T--)
{
cin>>N;
s = ( N%6 == 0 )?"Misha":"Chef";
cout<<s<<endl;
}
return 0;
}
