#include <iostream>
#include <stack>

using namespace std;

void insert(stack<int> &st, int a)
{
  if(st.empty())
    st.push(a);
  else
  {
    int temp = st.top();
    st.pop();
    insert(st,a);
    st.push(temp);
  }
}

int main()
{
  stack<int> st;
  int N;
  cout<<"Queue Implementation using stacks"<<endl;
  cout<<"Enter N:";
  cin>>N;
  for(int i=0; i<N; i++)
  {
    int temp;
    cin>>temp;
    insert(st,temp);
  }
  while(!st.empty())
  {
    int temp = st.top();
    cout<<temp<<" ";
    st.pop();
  }
  cout<<endl;
}
