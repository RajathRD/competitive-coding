#include <bits/stdc++.h>
#define M 1000000007
using namespace std;

vector <long long> amaze(1000000001,0);
int amazingness(vector <short> &a)
{
  vector <bool> S(20,false);

  set <short>::iterator iter;
  int ans = 0;
  // for(int i = a.size() - 1; i>=0; i--)
  //   cout<<a[i]<<" ";
  // cout<<endl;
  for(int i = a.size() - 1; i>=0; i--)
  {

      int val = 0;
      for(int j = i;j >=0 ; j--)
      {
        val ^=a[j];
      //  cout<<val<<endl;

        if(S[val] == false)
        {
          ans += val;
          ans %= M;
          S[val] = true;
        }
      }

  }
  return ans;
}

int main()
{
  int T;
  long long sum = 0;
  int l,r,num,temp;
  long long val;
  vector <short> a;
  l = 1,r=1000000;
  for(int i=l; i<=r; i++)
  {
    a.clear();
    num = i;
      while( num > 0)
      {
        int temp = num%10;
      //  cout<<"Temp:"<<temp<<endl;
        a.push_back(temp);
        num/=10;
      }
    //  cout<<i<<":"<<endl;

    long long val = amazingness(a);
  //  cout<<"Val:"<<val<<endl;
    amaze[i] = val;
    sum += val;
    sum %= M;

  }
  //cout<<"Enter:";
 cin>>T;

  // T = 1;
  while(T--)
  {
    cin>>l>>r;
    // l = 1,r=100000;
    sum = 0;
    for(int i=l; i<=r; i++)
    {
      a.clear();
      if(amaze[i] != 0)
        val = amaze[i];
      else{
      num = i;
      while( num > 0)
      {
        int temp = num%10;
      //  cout<<"Temp:"<<temp<<endl;
        a.push_back(temp);
        num/=10;
      }
    //  cout<<i<<":"<<endl;
      val = amazingness(a);
      amaze[i] = val;
    //  cout<<"Val:"<<val<<endl;
      }
      sum += val;
      sum %= M;

    }
    cout<<sum<<endl;
  }
  return 0;
}
