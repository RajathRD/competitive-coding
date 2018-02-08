#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct node
{
  int i;
  int k;
};

void bfs(vector< vector<int> > &adj,int start, int k)
{
  set<int> ans;
  queue<node> q;
  node temp;
  temp.i = start-1;
  temp.k = 0;
  q.push(temp);
  while( !q.empty() )
  {
    node front = q.front();
    //cout<<front.i<<endl;
    if( front.k == k )
    {
      ans.insert(front.i);
    }
    else if( front.k < k )
    {
      for(int i=0; i<adj[front.i].size(); i++)
      {
        temp.i = adj[front.i][i];
        temp.k = front.k + 1;
        q.push(temp);
      }
    }
    q.pop();
  }
  cout<<ans.size()<<endl;
  if(ans.size() == 0)
    cout<<-1;
  else
  {
    set<int>::iterator iter;
    for(iter = ans.begin(); iter != ans.end(); iter++)
      cout<<*iter+1<<" ";
  }
  cout<<endl;
}

int main()
{
  int N,M;
  cin>>N;
  vector< vector<int> > adj;
  vector< int > row;
  for(int i=0; i<N; i++)
  {
    row.clear();
    for(int j=0; j<N; j++)
    {
      int temp;
      cin>>temp;
      if( temp == 1 )
        row.push_back(j);
    }
    adj.push_back(row);
  }
  cin>>M;
  while(M--)
  {
    int K,X;
    cin>>K>>X;
    bfs(adj,X,K);
  }

  return 0;
}
