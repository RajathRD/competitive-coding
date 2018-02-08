#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

struct node
{
  int x,y;
  int visited[20][20];
};
char matrix[20][20];
double P,Q;
double dfs(int visited[20][20],int Rs,int Cs,int R,int C,int S, int steps,double cost)
{
  double p1=0.0,p2=0.0,p3=0.0,p4=0.0;
  // cout<<"RS:"<<Rs<<" CS:"<<Cs<<" S:"<<S<<" Cost:"<<cost<<endl;
  // for(int i=0; i<R; i++)
  // {
  //   for(int j=0; j<C; j++)
  //     cout<<visited[i][j]<<" ";
  //   cout<<endl;
  // }
  // cout<<endl;
  if( steps == S )
    return cost;
  if(steps == 0)
  {
    if( Rs + 1 < R)
      p1 = dfs(visited,Rs+1,Cs,R,C,S,steps+1,cost);
    if( Cs + 1 < C )
      p2 = dfs(visited,Rs,Cs+1,R,C,S,steps+1,cost);
    if( Rs - 1 >= 0 )
      p3 = dfs(visited,Rs-1,Cs,R,C,S,steps+1,cost);
    if( Cs - 1 >= 0 )
      p4 = dfs(visited,Rs,Cs-1,R,C,S,steps+1,cost);
  }
  else
  {
    if( Rs + 1 < R )
    {

      if(matrix[Rs][Cs] == 'A')
        cost += pow(1.0-P,visited[Rs][Cs])*P;
      else
        cost += pow(1.0-Q,visited[Rs][Cs])*Q;
      visited[Rs][Cs]++;
      p1 = dfs(visited,Rs+1,Cs,R,C,S,steps+1,cost);
      visited[Rs][Cs]--;
      if(matrix[Rs][Cs] == 'A')
        cost -= pow(1.0-P,visited[Rs][Cs])*P;
      else
        cost -= pow(1.0-Q,visited[Rs][Cs])*Q;
    }
    if( Cs + 1 < C )
    {

      if(matrix[Rs][Cs] == 'A')
        cost += pow(1.0-P,visited[Rs][Cs])*P;
      else
        cost += pow(1.0-Q,visited[Rs][Cs])*Q;
      visited[Rs][Cs]++;
      p2 = dfs(visited,Rs,Cs+1,R,C,S,steps+1,cost);
      visited[Rs][Cs]--;
      if(matrix[Rs][Cs] == 'A')
        cost -= pow(1.0-P,visited[Rs][Cs])*P;
      else
        cost -= pow(1.0-Q,visited[Rs][Cs])*Q;
    }
    if( Rs - 1 >= 0 )
    {

      if(matrix[Rs][Cs] == 'A')
        cost += pow(1.0-P,visited[Rs][Cs])*P;
      else
        cost += pow(1.0-Q,visited[Rs][Cs])*Q;
      visited[Rs][Cs]++;
      p3 = dfs(visited,Rs-1,Cs,R,C,S,steps+1,cost);
      visited[Rs][Cs]--;
      if(matrix[Rs][Cs] == 'A')
        cost -= pow(1.0-P,visited[Rs][Cs])*P;
      else
        cost -= pow(1.0-Q,visited[Rs][Cs])*Q;
    }
    if( Cs - 1 >= 0 )
    {

      if(matrix[Rs][Cs] == 'A')
        cost += pow(1.0-P,visited[Rs][Cs])*P;
      else
        cost += pow(1.0-Q,visited[Rs][Cs])*Q;
      visited[Rs][Cs]++;
      p4 = dfs(visited,Rs,Cs-1,R,C,S,steps+1,cost);
      visited[Rs][Cs]--;
      if(matrix[Rs][Cs] == 'A')
        cost -= pow(1.0-P,visited[Rs][Cs])*P;
      else
        cost -= pow(1.0-Q,visited[Rs][Cs])*Q;
    }
  }
  return max( max(p1,p2), max(p3,p4) );
}

int main()
{
  int T;
  cin>>T;
  for(int t=1; t<=T; t++)
  {
    int R,C,Rs,Cs,S;

    int visited[20][20];
    cin>>R>>C>>Rs>>Cs>>S;
    cin>>P>>Q;


    for(int i=0; i<R; i++)
    {
      for(int j=0; j<C; j++)
      {
        cin>>matrix[i][j];
        visited[i][j] = 0;
      }
    }
    double diff = ( matrix[Rs][Cs] == 'A' )?P:Q;
    cout<<fixed;
    cout<<setprecision(6);
    cout<<"Case #"<<t<<": "<< dfs(visited,Rs,Cs,R,C,S+1,0,0) <<endl;
  }
}
