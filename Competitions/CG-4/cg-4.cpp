#include <iostream>
#include <string>
#include <queue>
using namespace std;
int connected[100][100];
bool cycle(int boy, int N)
{
  int visited[100];
  queue<int> q;
  for(int i=0 ;i < N; i++)
    visited[i] = 0;
  q.push(boy);
  visited[boy] = 1;
  while(!q.empty())
  {
    int d = q.front();
    for(int i=0; i<N; i++)
    {
      if(connected[d][i] != 0 && visited[i] == 0)
      {
         q.push(i);
         visited[i] = 1;
      }
      if( connected[d][i] != 0 && visited[i] == 1 && i == boy)
        return false;
    }
    q.pop();
  }
  return true;
}


int main ()
{
    int N,M;
    cin>>N;
    cin>>M;
    int x[M],y[M],m[M];
    for(int i=0; i<M; i++)
    {
        cin>>x[i]>>y[i]>>m[i];
    }



    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
           connected[i][j] = 0;

    int chocolate[N];
    for(int i=0 ;i <N; i++)
      chocolate[i] = -1;

    for(int i=0; i<M;i++)
    {
        connected[x[i]-1][y[i]-1] = m[i];
    }

    // for(int i=0; i<N;i++)
    // {
    //     for(int j=0; j<N; j++)
    //     {
    //         cout<<connected[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0; i<N; i++)
    {
      if( !cycle(i,N) )
        chocolate[i] = 0;
      // cout<<"First";
    }

    for(int i=0; i<N; i++)
    {
      int flag = 1;
      if(chocolate[i] == -1)
      {
        for(int j=0; j<N; j++)
        {
          if( connected[i][j] > 0 )
          {
            flag = 0;
            break;
          }

        }
        if(flag)
        {
          chocolate[i] = 1;
        }
     }
    //  cout<<"Second";
    }
    int flag = 1;
    while( flag )
    {
      flag = 0;
      for(int i=0; i<N; i++)
      {
        if(chocolate[i] == -1)
         flag = 1;
      }
      if( flag == 0)
        break;

      for(int i=0; i<N; i++)
      {
        if(chocolate[i] == -1)
        {
          for(int j=0; j<N; j++)
          {
            if(connected[i][j] >= 0)
            {
              if(chocolate[j] >= 0)
              {
                if(chocolate[i] < chocolate[j]+connected[i][j])
                {
                  chocolate[i] = chocolate[j]+connected[i][j];
                }
              }
            }
          }
        }
      }
   }
    int sum = 0;
    for(int i=0; i<N; i++)
    {
       sum+= chocolate[i];
        // cout<<chocolate[i]<<endl;
    }
    cout<<sum;
    return 0;
}
