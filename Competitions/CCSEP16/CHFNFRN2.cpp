#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1000][1000];
int N;

struct node
{
  int i;
  int count;
};
bool operator < (node &a, node&b)
{
  return a.count < b.count;
}
vector <node> people;

bool recur( vector<int> table1, vector<int> table2, int val)
{
  if(val == N)
  {
    return true;
  }
  bool flag1=false,flag2=false,change1=true,change2=true;
  for(int j=0; j<table1.size(); j++)
    {
    if ( a[ people[val].i ][ table1[j] ] == 0 )
    {
      change1 = false;
      break;
    }
  }
  if(change1)
  {
    table1.push_back(people[val].i);
    flag1 = recur(table1,table2,val+1);
    table1.pop_back();
  }

  for(int j=0; j<table2.size(); j++)
  {
    if ( a[ people[val].i] [ table2[j] ] == 0 )
    {
      change2 = false;
      break;
    }
  }
  if(change2)
  {
    table2.push_back(people[val].i);
    flag2 = flag1 || recur(table1,table2,val+1);
    table2.pop_back();
  }

  if( !(change1 || change2) )
  {
    return false;
  }

  return flag1 || flag2 ;
}

int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    vector<int> table1;
    vector<int> table2;
    vector<int> new_entry;
    table1.clear();
    table2.clear();
    people.clear();

    int M;
    cin>>N>>M;
    if( N < 500 )
    {
      for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
          a[i][j] = 0;

      for( int i = 0; i < M; i++ )
      {
        int temp1,temp2;
        cin>>temp1>>temp2;
        a[temp1-1][temp2-1] = 1;
        a[temp2-1][temp1-1] = 1;
      }

      for( int i =0; i<N; i++)
      {
        node temp;
        temp.i = i;
        temp.count = 0;
        for(int j=0; j<N; j++)
        {
          if( a[i][j] == 1 )
          {
            temp.count++;
          }
        }
        people.push_back(temp);
      }

      sort( people.begin(), people.end() );

      table1.push_back(people[0].i);
      if( recur (table1,table2,1) )
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
    }
    else
    {
      vector<vector<int> > components;
      vector<int> new_component;
      components.clear();
      for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
          a[i][j] = 0;
          if( i==j)
            a[i][j] = 1;
        }

      for( int i = 0; i < M; i++ )
      {
        int temp1,temp2;
        cin>>temp1>>temp2;
        a[temp1-1][temp2-1] = 1;
        a[temp2-1][temp1-1] = 1;
      }

      for(int i=0; i<N; i++)
      {
        int change = 0;
        for(int j=0; j<components.size(); j++)
        {
          int inserted = 1;
          for(int k=0; k<components[j].size(); k++)
          {
            if ( a[ i ][ components[j][k] ] == 0 )
            {
              inserted = 0;
              break;
            }
          }
          if(inserted == 1 )
          {
            change ++;
            components[j].push_back(i);
          }
        }
        if( change > 1 )
        {
          components[0].pop_back();
          components[1].pop_back();
        }
        if( change == 0 )
        {
          new_component.push_back(i);
          components.push_back(new_component);
          if(components.size() == 3)
          {
            cout<<"NO"<<endl;
            break;
          }
          new_component.clear();
        }
      }
      if( components.size() <= 2 )
        cout<<"YES"<<endl;
    }
  }
}
