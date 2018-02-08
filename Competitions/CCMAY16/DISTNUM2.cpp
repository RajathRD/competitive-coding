#include <bits/stdc++.h>

#define SWAP(a,b) { a^=b; b^=a; a^=b; }

using namespace std;
int ans[100000] = {0};

#include <math.h>
#include <limits.h>

// A utility function to get minimum of two numbers
int minVal(int x, int y) { return (x < y)? x: y; }

// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }

/*  A recursive function to get the minimum value in a given range
     of array indexes. The following are parameters for this function.

    st    --> Pointer to segment tree
    index --> Index of current node in the segment tree. Initially
              0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented
                  by current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part of given range, then return
    //  the min of the segment
    if (qs <= ss && qe >= se)
        return st[index];

    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return INT_MAX;

    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}

// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
int RMQ(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return RMQUtil(st, 0, n-1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    int mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}

/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
int *constructST(int arr[], int n)
{
    // Allocate memory for segment tree

    //Height of segment tree
    int x = (int)(ceil(log2(n)));

    // Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1;

    int *st = new int[max_size];

    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);

    // Return the constructed segment tree
    return st;
}

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
  vector <int> unique;


  cin>>N>>Q;
  int A[N];
  for(int i=0; i<N; i++)
  {
    cin>>A[i];
  }
  int *st = constructST(A, N);
  ans[0] = 0;

  for(int i=1; i<=Q; i++)
  {
    isPresent.clear();
    unique.clear();
    cin>>a>>b>>c>>d>>k;
    l = left ( a,b,N,i);
    r = left ( c,d,N,i);
    if( l>r )
      SWAP(l,r);
    if( k != 1)
    {
    //  cout<<"L:"<<l<<" R:"<<r<<endl;
      for(int j = l-1; j <= r-1; j++)
      {
        if(isPresent[A[j]] != true)
        {
        //  cout<<A[j]<<" ";
          unique.push_back(A[j]);
          isPresent[A[j]] = true;
        }
      }
    //  cout<<endl;
      if( k > unique.size())
        ans[i] = -1;
      else
      {
        ans[i] = kthSmallest(unique, 0, unique.size()-1, k);
      }

    }

    else
    {
      ans[i] = RMQ(st,N,l-1,r-1);
    }
    cout<< ans[i] <<endl;
  }
  return 0;
}
