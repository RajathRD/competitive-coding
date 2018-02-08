// invert a matrix by 90 degrees
/*
1 2 3  7 4 1
4 5 6  8 5 2
7 8 9  9 6 3
*/
#include <iostream>

using namespace std;

int main()
{
  //cout<<"Enter size of square matrix: ";
  int N;
  cin>>N;
  int a[100][100];
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      cin>>a[i][j];
    }
  }
  cout<<"--------Input---------"<<endl;
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"-----Transpose----"<<endl;
  for(int i=0; i<N; i++)
  {
    for(int j=i; j<N; j++)
    {
      // cout<<a[i][j]<<" "<<a[j][i]<<endl;
      int temp = a[i][j];
      a[i][j] = a[j][i];
      a[j][i] = temp;

    }
  }
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  for(int i=0; i<N; i++)
  {
    int left=0,right=N-1;
    while(left < right)
    {
      int temp = a[i][left];
      a[i][left] = a[i][right];
      a[i][right] = temp;
      left++;
      right--;
    }
  }
  cout<<"------Mirror------ [ finally 90 degrees flip right ]------"<<endl;
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
}
