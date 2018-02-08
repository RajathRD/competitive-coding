#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int a[100000];
  for(int i=0;i<n;i++)
   cin>>a[i];
  sort(a,a+n);
  int low = 0,high = n-1;
  while(low<=high)
  {
    int mid = (low + high)/2;
    if(a[mid] > a[mid+1])
     high = mid - 1;
    else if(a[mid] < a[mid+1])
     low = mid +1;
    if((a[mid] > a[mid-1])&&(a[mid]>a[mid+1]))
    {
     cout << a[mid]<<endl;
     break;
    }
  }
  return 0;
}
