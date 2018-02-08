#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> one,two,diff;
  int A,B,C,D,temp1,temp2,temp3,temp4;
  int T;
  cin>>T;
  while(T--)
  {
    cin>>temp1>>temp2>>temp3>>temp4;
    if(temp1 > temp2)
    {
      A = temp1;
      B = temp2;
      C = temp3;
      D = temp4;
    }
    else
    {
      B = temp1;
      A = temp2;
      D = temp3;
      C = temp4;
    }

    for(int i=0; i<30; i++)
    {
      one.push_back(A+C*i);
      two.push_back(B+D*i);
    }
    for(int i=0; i<30; i++)
    {
        cout<<one[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<30; i++)
    {
       cout<<two[i]<<" ";
    }
    cout<<endl;
    int i=0,j=0;
    while(i <= 30 && j <= 30)
    {
      if( one[i] < two[j] )
      {
        cout<<"One"<<endl;
        while( one[i+1] < two[j] && i<30 )
          i++;
        int val = min(two[j]-one[i],one[i+1]-two[j]);
        diff.push_back(val);
        cout<<one[i]<<" "<<two[j]<<" "<<min(two[j]-one[i],one[i+1]-two[j])<<endl;
        i++;
      }
      else
      {
        cout<<"Two"<<endl;
        while( one[i] > two[j+1] && j < 30)
          j++;
        int val = min(one[i]-two[j],two[j+1]-one[i]);
        diff.push_back(val);
        cout<<two[j]<<" "<<one[i]<<" "<<min(two[j]-one[i],one[i+1]-two[j])<<endl;
        j++;
      }
    }

    for(i=0; i<diff.size(); i++)
    {
      cout<<diff[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
