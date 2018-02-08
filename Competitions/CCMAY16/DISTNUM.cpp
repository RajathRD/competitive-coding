#include <bits/stdc++.h>

#define SWAP(a,b) { a^=b; b^=a; a^=b; }

using namespace std;
int ans[100000] = {0};

int partition(int arr[], int l, int r);

int kthSmallest(vector<int> &arr, int l, int r, int k)
{

    if (k > 0 && k <= r - l + 1)
    {
        int x = arr[r], i = l;
        for (int j = l; j <= r - 1; j++)
        {
            if (arr[j] <= x)
            {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[r]);
        int pos = i;

        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return kthSmallest(arr, l, pos-1, k);

        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }

    return INT_MAX;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int left(int a, int b, int N, int i )
{
  return (a * max( ans[i-1], 0) + b) % N + 1;
}

int right(int c, int d, int N, int i )
{
  return (c * max( ans[i-1], 0)  + d) % N + 1;
}

int main()
{

  int N,Q,temp;
  unordered_map <int,bool> isPresent;
  int a,b,c,d,k,l,r,j;
  vector <int> A,unique;
  cin>>N>>Q;
  int count[N];
  count[0] = 0;
  for(int i=1; i<=N; i++)
  {
    cin>>temp;
    A.push_back(temp);
    if(isPresent.count(temp) == 0)
    {
      isPresent.insert(temp);
      count[i] = count[i-1];
    }
    else{
      count[i] = count[i-1]+1;
    }
  }

  ans[0] = 0;

  for(int i=1; i<=Q; i++)
  {

    unique.clear();
    cin>>a>>b>>c>>d>>k;
    l = left ( a,b,N,i);
    r = left ( c,d,N,i);
    if( l>r )
      SWAP(l,r);
  //   cout<<"L:"<<l<<" R:"<<r<<endl;
      for(int j = l-1; j <= r-1; j++)
      {
          unique.push_back(A[j]);
      }
    // cout<<endl;
      if( k > count[] )
        ans[i] = -1;
      else
      {
        ans[i] = kthSmallest(unique, 0, unique.size()-1, k);
      }
      cout<< ans[i] <<endl;
      }
  return 0;
}
