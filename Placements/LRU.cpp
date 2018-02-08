#include<iostream>
#define MAX 100
using namespace std;

int isPresent(int a[MAX],int N,int key)
{
  int i=0;
  for(i=0; i<N; i++)
    if( a[i] == key )
      break;
  return i;
}

int check(int a[MAX],int N, int num)
{
  int i;
  for(i=0; i<N; i++)
    if(a[i] == num)
      break;
  return i;
}

int main()
{
  int N,size;
  cin>>size;
  int LRU[size];
  int priority[size];
  cin>>N;
  int a[N];
  for(int i=0; i<N; i++)
    cin>>a[i];

  int i = 0;
  int j = 0;
  while( i <= min(N,size) && j < N)
  {
    int pos = isPresent( LRU, i, a[j] );
    cout<<i<<endl;
    if( pos == i )
    {
      LRU[i] = a[j];
      i += 1;
    }
    else
      cout<<"HIT"<<endl;
    // for(j=0; j<size; j++)
    //   cout<<LRU[j]<<" ";
    // cout<<endl;
    j+=1;
  }
  for(i=0 ; i<size; i++)
    priority[size-1-i] = i+1;
  for(j=0; j<size; j++)
    cout<<LRU[j]<<" ";
  cout<<endl;
  for(j=0; j<size; j++)
    cout<<priority[j]<<" ";
  cout<<endl;
  for(i=min(size,N) ; i<N; i++)
  {
    int pos = isPresent( LRU, size, a[i] );
    if( pos == size )
    {
      int change = check(priority,size,size);
      for(j=0 ; j<size; j++)
        priority[j]+=1;
      priority[change] = 1;
      LRU[change] = a[i];
      cout<<"FAULT"<<endl;
    }
    else
    {
      for(j=0; j<size; j++)
        priority[j]+=1;
      priority[pos] = 1;
      cout<<"HIT"<<endl;
    }
    for(j=0; j<size; j++)
      cout<<LRU[j]<<" ";
    cout<<endl;
  }

  return 0;
}
