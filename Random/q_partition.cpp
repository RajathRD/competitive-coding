#include <iostream>
#define swap(a,b) {int t=a;a=b;b=t}
using namespace std;
int a[1000];
int quicksort(int start, int end, int K)
{
  while( i < j)
  {
    while( a[i] > pivot )
      i++;
    while( a[j] < pivot )
      j--;
    if( i < j )
      swap(a[i],a[j]);
  }
  swap(a[j],pivot);
  if( j > K )
    quicksort(start,pivot,K);
  else if ( j < K)
    quicksort(pivot+1,end,K);
  else
    return a[j];
}
int main()
{

  return 0;
}
