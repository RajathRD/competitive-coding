#include<bits/stdc++.h>

using namespace std;
int a[4][4] = {0};

struct node
{
  int sum;
  int place;
  int count;
  int vis[4];
};

long long bfs()
{
  long long minimum = 10000000000000000;
  node start;
  start.place = 0;
  start.sum = 0;
  start.count = 0;
  start.vis[0] = 1;
  start.vis[1] = start.vis[2] = start.vis[3] = 0;
  queue<node> q;
  q.push(start);
  while(!q.empty())
  {
    node d = q.front();

    cout<<"Considering: "<<d.place<<" "<<d.sum<<" "<<d.count<<endl;
    if(d.count == 2)
    {
      int check;
      for(int i=0; i<4; i++)
      {
          cout<<d.vis[i]<<" ";
          if(d.vis[i] == 0)
          {
             check = i;
             break;
          }

      }
      cout<<endl;
      cout<<"Check: "<<check<<endl;
      if( minimum > min(d.sum + a[d.place][0], min(d.sum*2 , d.sum+a[d.place][check]+a[check][0])) )
        minimum = min(d.sum + a[d.place][0], min(d.sum*2 , d.sum+a[d.place][check]+a[check][0]) );
    }
    else
    {
      for(int i=1; i<4; i++)
      {

        if(a[d.place][i] != 0)
        {
           node X;
           X.sum = d.sum + a[d.place][i];
           X.count = d.count + 1;
           X.vis[0] = d.vis[0];
           X.vis[1] = d.vis[1];
           X.vis[2] = d.vis[2];
           X.vis[3] = d.vis[3];
           X.vis[i] = 1;
           X.place = i;
           q.push(X);
           cout<<"Push: "<<X.place<<" "<<X.sum<<" "<<X.count<<" : ";
           for(int i=0; i<4; i++)
            cout<<X.vis[i]<<" ";
           cout<<endl;
        }
      }
    }
    q.pop();
  }
  return minimum;
}

int main()
{

  long long ha,hb,hc,ab,ac,bc;
  cin>>ha>>hb>>hc>>ac>>ab>>bc;
  a[0][1]=a[1][0]=ha;
  a[0][2]=a[2][0]=hb;
  a[0][3]=a[3][0]=hc;
  a[1][2]=a[2][1]=ab;
  a[1][3]=a[3][1]=ac;
  a[2][3]=a[3][2]=bc;

  // for(int i=0; i<4; i++)
  // {
  //   for(int j=0; j<4; j++)
  //   {
  //     cout<<a[i][j]<<" ";
  //
  //   }
  //   cout<<endl;
  // }
  cout<<bfs();
  return 0;
}
