#include <bits/stdc++.h>
using namespace std;

map<int,int> possible_sums;
long long che[50] = {0};

struct node{
  long long sum;
  int K;
  int last;
};

void chefib( int num )
{
  if( che[num - 1] == 0 )
    chefib( num - 1 );
  if( che[num - 2] == 0 )
    chefib( num - 2 );

    che[num] = che[num-1] + che[num - 2];
}

int do_magic(const vector<int> &a, int X, int K)
{
  int count = 0;
  queue <node> sum;
  node temp;
  for(int i=0; i<a.size(); i++)
  {
    temp.sum = a[i];
    temp.K = 1;
    temp.last = a[i];
    sum.push(temp);
    // cout<<temp.sum<<" Pushed K:"<<temp.K<<endl;
  }
  while(!sum.empty())
  {
    node& check = sum.front();
    int flag = 1;
    // cout<<"-----Checking Curr:"<<check.sum<<" K:"<<check.K<<endl;
    if(check.K == K)
    {
      flag = 0;
      if(possible_sums.count(check.sum))
        possible_sums[check.sum]++;
      else
        possible_sums[check.sum] = 1;
      if( check.sum == X)
      {

        count++;
        // cout<<"K reached "<<"Curr: "<<check.sum<<" K:"<<check.K<<endl;

      }
    }
    if(flag)
      for(int i = 0; i<a.size();i++)
      {
          if( check.sum + a[i] == X && check.K +1 == K && check.last <= a[i])
            count++;
          else if( check.sum + a[i] <= X && check.K + 1 <= K && check.last <=a[i])
          {
            temp.sum = check.sum + a[i];
            temp.K = check.K + 1;
            temp.last = a[i];
            sum.push(temp);
        //    cout<<"Pushed "<<temp.sum<<" K:"<<temp.K<<endl;
          }
      }
    sum.pop();
    //cout<<"----Popped: "<<check.sum<<" K:"<<check.K<<"---"<<endl;
  }
  return count;
}

int main()
{
  che[0] = 1;
  che[1] = 2;
  chefib(43);
  // for(int i = 0; i<44; i++)
  // {
  //   cout<<i<<" "<<che[i]<<endl;
  // }

  vector<int> a;
  int Q,X,K;
  cin>>Q;
  while ( Q-- )
  {
      cin>>X>>K;
      a.clear();
      int i = 0;
      while(che[i] <= X)
      {
      //  cout<<che[i]<<" < "<<X<<endl;
        a.push_back(che[i]);
        i++;
      }
      cout<<do_magic(a,X,K);<<endl;

      cout<<"For K:"<<K<<"\nNumber of possible sums:"<<possible_sums.size()<<endl;
  }


  return 0;
}
