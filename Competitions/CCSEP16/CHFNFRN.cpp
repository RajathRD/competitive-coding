#include <iostream>
#include <vector>
using namespace std;

int a[1000][1000];

bool recur( vector< vector<int> > tables, vector<int> &redo)
{
  for(int i=redo.size()-1; i>-1; i--)
  {
    int val = redo[i];
    redo.pop_back();
    int change1 = 1,change2 = 1;
    for(int j=0; j<tables[0].size(); j++)
    {
      if ( a[ val ][ tables[0][j] ] == 0 )
      {
        change1 = 0;
        break;
      }
    }
    if(change1 == 1)
      tables[0].push_back(val);

    for(int j=0; j<tables[1].size(); j++)
    {
      if ( a[ val ][ tables[1][j] ] == 0 )
      {
        change2 = 0;
        break;
      }
    }
    if(change2 == 1)
      tables[1].push_back(val);
    if( !(change1 || change2) )
      return false;
    if( change1 && change2 )
    {
      tables[0].pop_back();
      bool flag1 = recur(tables,redo);
      tables[1].pop_back();
      tables[0].push_back(val);
      return flag1 || recur(tables,redo);
    }
  }
  return true;
}

int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    vector<vector<int> > tables;
    vector<int> new_entry,redo;
    tables.clear();

    int N,M,flag = 0;
    cin>>N>>M;

    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
      {
        a[i][j] = 0;
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
      for(int j=0; j<tables.size(); j++)
      {
        int inserted = 1;
        for(int k=0; k<tables[j].size(); k++)
        {
          if ( a[ i ][ tables[j][k] ] == 0 )
          {
            inserted = 0;
            break;
          }
        }
        if(inserted == 1 )
        {
          change ++;
          tables[j].push_back(i);
        }
      }
      if( change > 1 )
      {
        tables[0].pop_back();
        tables[1].pop_back();
        redo.push_back(i);
      }
      else if( change == 0 )
      {
        new_entry.push_back(i);
        tables.push_back(new_entry);
        if(tables.size() == 3)
        {
          break;
        }
        new_entry.clear();
      }
    }

    if( tables.size() <= 2 )
    {
      if( recur(tables,redo) )
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;

    }
    else
      cout<<"NO"<<endl;
    for(int i=0; i<tables.size(); i++)
    {
      for(int j=0; j<tables[i].size(); j++)
      {
        cout<<tables[i][j]+1<<" ";
      }
      cout<<endl;
    }
  }

  return 0;
}
