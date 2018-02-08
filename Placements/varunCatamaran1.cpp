#include<bits/stdc++.h>
using namespace std;

template <typename T>
string NumberToString ( T Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}

struct Node
{
  double d;
  string s;
};

bool compare(Node a, Node b)
{
  return a.d<b.d;
}
int main()
{
  vector<Node> v;
  set<double> check;
  set<double>::iterator iter;
  int N;
  cin>>N;
  Node first;
  first.s="0/1";
  first.d=0.00;
  v.push_back(first);
  for(int i=1; i<=N; i++)
  {
    for(int j=1; j<i; j++)
    {
      string s=NumberToString(j)+"/"+NumberToString(i);
      double d = (double)j/i;
      // cout<<d<<endl;
      if( check.count(d)==0 )
      {
        check.insert(d);
        Node N;
        N.d = d;
        N.s = s;
        v.push_back(N);
      }
      //  cout<<s<<endl;
    }
  }
  sort(v.begin(),v.end(),compare);
  cout<<v[0].s;
  for(int i=1; i<v.size(); i++)
  {
    cout<<" + "<<v[i].s;
  }
  cout<<endl;
  return 0;
}
