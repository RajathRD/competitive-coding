#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct node
{
  int v1,v2,v3;
  int product;
};

vector<int> primes;
vector<node> triplet_product;

void preprocess()
{
  int N = 600;

  for(int i=2; i<N; i++)
  {
    int flag = 1;
    for(int j=2; j<=sqrt(i); j++)
    {
      if( i%j == 0 )
        flag = 0;
    }
    if( flag )
      primes.push_back(i);
  }

  for(int i=0; i<primes.size()-2; i++)
  {
    for(int j=i+1; j<primes.size()-1; j++)
    {
        for(int k=j+1; k<primes.size(); k++)
        {
          node temp;
          temp.v1 = primes[i];
          temp.v2 = primes[j];
          temp.v3 = primes[k];
          temp.product = temp.v1 * temp.v2 * temp.v3;
          triplet_product.push_back(temp);
        }
    }
  }
  cout<<triplet_product.size()<<endl;
  sort(triplet_product.begin(), triplet_product.end());
}


bool operator < (node t1, node t2)
{
  return t1.product < t2.product;
}
int main()
{
  preprocess();
  int T;
  cin>>T;
  while(T--)
  {
    int Q;
    cin>>Q;
    cout<<triplet_product[Q-1].product<<endl;
  }
  return 0;

}
