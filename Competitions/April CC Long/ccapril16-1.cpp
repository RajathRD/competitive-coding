//mistake dint declare max as int so it thought max was the function and freaked out

#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
  int T,N,highest;
  char color;
  map<char,int> count;
  map<char,int>::iterator iter;
  cin>>T;
  while(T--)
  {
    count['R']=0;
    count['G']=0;
    count['B']=0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
      cin>>color;
      count[color]++;
    }
    highest = -1;
    for(iter=count.begin();iter!=count.end();iter++)
    {
      if(highest<iter->second)
        highest=iter->second;
    }
    cout<< N - highest <<endl;

  }

  return 0;
}
