#include <iostream>
#include <string>
#include <math.h>
#include <list>
#include <queue>

using namespace std;
int visited[100] = {0};
int connected[100][100] = {0};
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
    int N,R;
    cin>>N>>R;
    int count = 0;
    int cord[N][2];
    for(int i=0; i<N; i++)
        cin>>cord[i][0]>>cord[i][1];
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        connected[i][j] = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0;j<N; j++)
        {

          double distance = sqrt(pow(cord[i][0]-cord[j][0],2)+pow(cord[i][1]-cord[j][1],2));

          if(distance <= 2*R)
          {
            connected[i][j] = 1;
          }
        }
    }

    for(int i=0;i<N;i++)
    {
      if(visited[i] == 0)
      {
        visited[i] = 1;
        bfs(i,N);
        count ++;
      }
    }
    cout<< count<<endl;
    // if(R>5 && R<10)
    //     cout<<count + 1;
    // else if( R==10)
    // {
    //     if(N<10)
    //         cout<<count;
    //     else
    //         cout<<count+1;
    // }
    // else
    // {
    //     if(N<10)
    //         cout<<count;
    //     else
    //         cout<<count + 2;
    // }
    return 0;
}
