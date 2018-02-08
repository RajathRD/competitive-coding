#include <bits/stdc++.h>

using namespace std;

struct node
{
  int curr;
  int M;
};

void bfs(int s, int M,int N, const vector<int> &a)
{
  vector <int> ways(N,0);
  queue <node> path;
  node X;
  X.curr = s;
  X.M = 0;
  path.push(X);
  //cout<<X.curr<<" Pushed M:"<<X.M<<endl;

  while(!path.empty())
  {
    node check;

    check = path.front();
  //  cout<<"Checking Curr:"<<check.curr<<" M:"<<check.M<<endl;
    if(check.M == M)
    {
      ways[check.curr-1]++;
      path.pop();
    //  cout<<"M reached "<<"Curr: "<<check.curr<<" M:"<<check.M<<endl;
    }
    else
    {

      int currPM = check.curr + a[check.M];
      int currMM = check.curr - a[check.M];
      if( !( currPM > N ) )
      {
        X.curr = currPM;
        X.M = check.M + 1;
        path.push(X);
  //      cout<<X.curr<<" Pushed CurrPM:"<<X.M<<endl;

      }
      if( !( currMM < 1 ) )
      {
        X.curr = currMM;
        X.M = check.M + 1;
        path.push(X);
      //  cout<<X.curr<<" Pushed CurrMM:"<<X.M<<endl;

      }
      if(!path.empty())
      {
        path.pop();
      //  cout<<check.curr<<" Popped "<<endl;
      }
    }
  }
  for(int i=0;i<N;i++)
    cout<<ways[i]<<" ";
  cout<<endl;
}

int main()
{
  int T,N,M,s;
  cin>>T;
  vector <int> a;
  while(T--)
  {
      a.clear();
      cin>>N>>M>>s;
      for(int i=0;i<M;i++)
      {
        int temp;
        cin>>temp;
        a.push_back(temp);
      }
      bfs(s,M,N,a);
  }
}
