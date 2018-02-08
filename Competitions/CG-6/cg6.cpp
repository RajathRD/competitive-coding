#include <iostream>
#include <string>
#include <math.h>
#include <list>
#include <queue>

using namespace std;
int visited[1000] = {0};
int connected[1000][1000] = {0};
void bfs(int start,int N )
{
  queue<int> q;
  visited[start] = 1;
  q.push(start);
  while( !q.empty() )
  {
    int f = q.front();
    for(int i=0; i<N; i++)
    {

      if(connected[f][i] == 1 && visited[i] == 0)
      {

        visited[i] = 1;
        q.push(i);
      }
    }
    q.pop();
  }
}

int main ()
{
    int T;
    cin >> T;
    while(T--) {
      int N,M;
      cin>>N>>M;
      int count = 0;

      for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
          connected[i][j] = 0;
      for(int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        connected[a][b] = 1;
        connected[b][a] = 1;
      }

      int capital;
      cin >> capital;

      // for(int i=0; i<N; i++)
      // {
      //     for(int j=0;j<N; j++)
      //     {
      //
      //         cout << connected[i][j] <<  ' ';
      //
      //     }
      //     cout << endl;
      // }

      for(int i = 0; i<N; i++)
        visited[i] = 0;

        count = 0;
      for(int i=0;i<N;i++)
      {
        if(visited[i] == 0)
        {
          visited[i] = 1;
          bfs(i,N);
          count ++;
        }
      }

      if(count==1)
        cout<< "Yes" <<endl;
      else {
        cout << "No" << endl << count-1 << endl;
      }

    }

    return 0;
}
