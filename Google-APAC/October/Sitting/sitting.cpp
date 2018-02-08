#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  for(int t=1; t<=T; t++) {
    int R,C;
    cin >> R >> C;
    int count = 0;
    bool filled[R][C];

    for(int r=0; r<R; r++)
      for(int c=0; c<C; c++)
        filled[r][c] = false;

    for(int r=0; r<C; r++) {
      for(int c=0; c<R; c++)
      {
        bool flag = true;
        if( r - 2 > -1 && r - 1 > -1 )
        {
          if( filled[r-2][c] && filled[r-1][c] )
            flag = false;
        }
        if( c-2 > -1 && c - 1 > -1)
        {
          if( filled[r][c-2] && filled[r][c-1] )
            flag = false;
        }

        filled[r][c] = flag;
        count += (int)flag;
      }
    }
    for(int r=0; r<C; r++)
    {
      for(int c=0; c<R; c++)
        cout<<filled[r][c]<<" ";
      cout<<endl;
    }
    cout<<"Case #"<<t<<": "<<count<<endl;
  }
  return 0;
}
