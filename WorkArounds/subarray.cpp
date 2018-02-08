#include<iostream>
#include<vector>

using namespace std;

int main()
{
  int arr[]= {2,2,3};
  int temp;
  vector<int> subsum;
  for(int i=2;i>=0;i--)
  {
    temp=subsum.size();
    for(int j=0;j<temp;j++)
    {
    //  cout<<arr[i]+subsum[j]<<" ";
      subsum.push_back(arr[i]+subsum[j]);
    }
//    cout<<arr[i]<<endl;
    subsum.push_back(arr[i]);
  }
  for(int j=0;j<subsum.size();j++)
  {
    cout<<subsum[j]<<" ";
  }
  return 0;
}
