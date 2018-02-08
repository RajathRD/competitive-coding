#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

struct node
{
  int visited[200000];
  int prev;
  int weight;
	vector<int> trail;
};

void bfs(int *a,int N,int start,int end)
{
  node temp;
  int min = INT_MAX;
  queue<node> q;
  for(int i=0; i<N; i++)
    temp.visited[i] = 0;
  temp.prev = start;
  temp.weight = 0;
	temp.trail.push_back(start);
  q.push(temp);
  while( !q.empty() )
  {
    node front = q.front();
    // cout<<"Vertex: "<<front.prev<<endl;
    // for(int i=0; i<N; i++)
    //   cout<<front.visited[i]<<" ";
    // cout<<endl;
    // cout<<"W: "<<front.weight<<endl;
    int check = (front.prev-1 < 0)?N-1:front.prev-1;
    if(  front.visited[check] < 2 )
    {
      front.visited[check] ++;
      front.prev = ( front.prev - 1 < 0)?N-1:front.prev-1;
      front.weight += a[check];
			front.trail.push_back(check);
      q.push(front);
			front.trail.pop_back();
      front.visited[check] --;
      front.prev = ( front.prev + 1 == N)?0:front.prev+1;
      front.weight -= a[check];
    }

    check = (front.prev);
    if(  front.visited[check] < 2 )
    {
      front.visited[check] ++;
      front.weight += a[front.prev];
      front.prev = ( front.prev + 1 == N)?0:front.prev+1;
			front.trail.push_back(check);
      q.push(front);
			front.trail.pop_back();
      front.visited[check] --;
      front.prev = ( front.prev - 1 < 0)?N-1:front.prev-1;
      front.weight -= a[front.prev];
    }

    if( front.prev == end )
    {
      if( front.weight < min )
      {
				for(int i=0; i<front.trail.size(); i++)
					cout<<front.trail[i]<<" ";
				cout<<" W:"<<front.weight<<endl;

			  min = front.weight;
			}
    }
    q.pop();
  }
  cout<<min<<endl;
}

int main()
{

	int a[200001];
  int T,N,start,end;
  cin>>T;
  while(T--)
  {
    cin>>N;
    for(int i=0; i<N; i++)
    {
      cin>>a[i];
    }

    cin>>start>>end;
    bfs(a,N,start-1,end-1);
  }
}
