#include <iostream>
#include <map>
#include <string.h>
#include <vector>
using namespace std;

int num_of_diff_cookies(int *a)
{
  int count = 0;
  for(int i=0; i<6; i++)
  {
    if( a[i] > 0 )
      count++;
  }
  return count;
}

int getMin(int *a)
{
  int min = 999999;
  for(int i=0; i<6; i++)
    if( min > a[i] && a[i] > 0)
      min = a[i];
  return min;
}

int main()
{
  int T,N, num,countbag[6];
  cin>>T;
  map<int,vector<int>,greater<int> > points;
  while(T--)
  {

    points.clear();
    cin >> N;
    int tie = 0;
    for( int player = 1; player <= N; player ++)
    {
      int score = 0;
      cin >> num;
      memset(countbag,0,sizeof(countbag));

      for( int i = 0; i < num; i++ )
      {
        int temp;
        cin >> temp;
        countbag[temp-1]++;
      }
      // 
      // for(int i=0; i<6; i++)
      //   cout<<countbag[i]<<" ";
      // cout<<endl;
      int diff = num_of_diff_cookies(countbag);
      while( diff > 0 )
      {
        int min = getMin(countbag);

        for(int i=0; i<6; i++)
        {
          countbag[i] -= min;
        }
        score += min * diff;
        if( diff == 4 )
          score += min;
        else if ( diff == 5 )
          score += min*2;
        else if( diff == 6 )
          score += min*4;

        diff = num_of_diff_cookies(countbag);
      }
      // cout << score << endl;
      points[score].push_back(player);

    }
    map< int, vector< int > >::iterator iter;
    iter = points.begin();
    if(iter->second.size() == 1 )
    {
      if(iter->second[0] == 1)
        cout<<"chef"<<endl;
      else
        cout<<iter->second[0]<<endl;
    }
    else
      cout << "tie" << endl;
  }
  return 0;
}
