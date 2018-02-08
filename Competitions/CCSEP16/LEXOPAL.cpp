#include <iostream>

using namespace std;

int main()
{
  int T;
  cin>>T;
  while(T--)
  {
      string S;
      cin>>S;
      int flag = 1;
      int N = S.length();
      int i = N/2;
      int j = i;
      if( N % 2 == 0 )
        i--;
      while( i > -1 && j < N )
      {
        // cout<<i<<" "<<j<<endl;
        if( i == j && S[i] == '.' )
          S[i] = 'a';
        else if ( S[i] == '.' || S[j] == '.')
        {
          if( !(S[j] == '.') )
            S[i] = S[j];
          else if ( !(S[i] == '.') )
            S[j] = S[i];
          else
            S[i] = S[j] = 'a';
        }
        else if ( S[i] != S[j] )
          flag = 0;
        i--;
        j++;
      }
      if( flag )
        cout << S << endl;
      else
        cout << -1 << endl;

  }
  return 0;
}
