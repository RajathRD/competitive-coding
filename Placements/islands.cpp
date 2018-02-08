#include<bits/stdc++.h>
#define MAX 100
using namespace std;

struct node
{
  int i,j;
};
int visited[MAX][MAX];

void bfs(int a[MAX][MAX],int N,int starti,int startj)
{
  node q[MAX*MAX];
  int head = 0;
  int tail = 1;
  q[0].i=starti;
  q[0].j=startj;

  while(head != tail)
  {
    int i = q[head].i;
    int j = q[head++].j;
    // cout<<i<<" "<<j<<endl;
    if( i+1 < N && a[i+1][j] == 1 && visited[i+1][j] == 0)
    {
       q[tail].i = i+1;
       q[tail++].j = j;
       visited[i+1][j] = 1;
      //  cout<<"Set I:"<<i+1<<" J:"<<j<<endl;
    }
    if( j+1 < N && a[i][j+1] == 1 && visited[i][j+1] == 0)
    {
      q[tail].i = i;
      q[tail++].j = j+1;
      visited[i][j+1] = 1;
      // cout<<"Set I:"<<i<<" J:"<<j+1<<endl;
    }
    if( i-1 > -1 && a[i-1][j] == 1 && visited[i-1][j] == 0)
    {
      q[tail].i = i-1;
      q[tail++].j = j;
      visited[i-1][j] = 1;
      // cout<<"Set I:"<<i<<" J:"<<j+1<<endl;
    }
    if( j-1 > -1 && a[i][j-1] == 1 && visited[i][j-1] == 0)
    {
      q[tail].i = i;
      q[tail++].j = j-1;
      visited[i][j-1] = 1;
      // cout<<"Set I:"<<i<<" J:"<<j+1<<endl;
    }

  }
  // cout<<tail<<endl;
}
int main()
{
  int a[MAX][MAX];
  int N;
  cin>>N;
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      cin>>a[i][j];
    }
  }
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      visited[i][j] = 0;
  int count = 0;
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      if(visited[i][j] == 0 && a[i][j] == 1)
      {
        // cout<<i<<j<<visited[i][j]<<endl;
        count++;
        bfs(a,N,i,j);
      }
    }
  }
  cout<<count<<endl;
  return 0;
}
