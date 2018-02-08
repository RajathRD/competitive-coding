#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool checkE(vector< pair<int,int> >& tanks, vector< pair<int,int> >& objects,int i)
{
  for(int j=0; j<objects.size(); j++)
  {
    if(objects[j].second == tanks[i].second )
    {
      if( objects[j].first > tanks[i].first)
        return false;
    }
  }
  return true;
}

bool checkN(vector< pair<int,int> >& tanks, vector< pair<int,int> >& objects,int i)
{
  for(int j=0; j<objects.size(); j++)
  {
    if(objects[j].first == tanks[i].first )
    {
      if( objects[j].second > tanks[i].second)
        return false;
    }
  }
  return true;
}

bool checkS(vector< pair<int,int> >& tanks, vector< pair<int,int> >& objects,int i)
{
  for(int j=0; j<objects.size(); j++)
  {
    if(objects[j].first == tanks[i].first )
    {
      if( objects[j].second < tanks[i].second)
        return false;
    }
  }
  return true;
}

bool checkW(vector< pair<int,int> >& tanks, vector< pair<int,int> >& objects,int i)
{
  for(int j=0; j<objects.size(); j++)
  {
    if(objects[j].second == tanks[i].second )
    {
      if( objects[j].first < tanks[i].first)
        return false;
    }
  }
  return true;
}

int main()
{
  int N,M;
  vector< pair<int,int> > tank,object;
  cin>>N>>M;
  int tanks,objects;
  cin>>tanks;
  char results[tanks];
  for(int i=0; i<tanks; i++)
  {
    int t1,t2;
    cin>>t1>>t2;
    tank.push_back( make_pair(t1,t2) );
  }
  cin>>objects;
  for(int i=0; i<objects; i++)
  {
    int t1,t2;
    cin>>t1>>t2;
    object.push_back( make_pair(t1,t2) );
  }

  for(int i=0; i<tank.size(); i++)
  {
    // cout<<tank[i].first<<" "<<tank[i].second<<endl;
    if(checkE(tank,object,i))
    {
      results[i] = 'E';
      continue;
    }
    // cout<<"Not East"<<endl;
    if(checkN(tank,object,i))
    {
      results[i] = 'N';
      continue;
    }
    // cout<<"Not North"<<endl;
    if(checkS(tank,object,i))
    {
      results[i] = 'S';
      continue;
    }
    // cout<<"Not south"<<endl;
    if(checkW(tank,object,i))
    {
      results[i] = 'W';
      continue;
    }
    results[i] = '0';
    // cout<<"Not West"<<endl;

  }
  for(int i=0; i<tanks; i++)
  {
    cout<<results[i]<<endl;
  }
  return 0;
}
