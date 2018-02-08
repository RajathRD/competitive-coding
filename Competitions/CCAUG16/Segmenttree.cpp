#include <iostream>

using namespace std;

int a[100000];

int F(int i, int j)
{
	return ( (a[i]&a[j]) == a[i] || (a[i]&a[j]) == a[j])?true:false;
}

int RMQ(int *st, int low, int high, int qleft, int qright, int index)
{

	if (qleft <= low && qright >= high)
		return st[index];
	if (high < qleft || low > qright)
		return 0;
	int mid = low + (high-low)/2;
	return max((RMQ(st, low, mid, qleft, qright, 2*index+1)),
				(RMQ(st, mid+1, high, qleft, qright, 2*index+2)));
}

int constructSTUtil(int arr[], int low, int high, int *st, int si)
{
	if (low == high)
	{
		st[si] = arr[low];
		return arr[low];
	}
	int mid = low + (high-low)/2;
	st[si] = max(constructSTUtil(arr, low, mid, st, si*2+1),
					constructSTUtil(arr, mid+1, high, st, si*2+2));
	return st[si];
}

int *constructST(int arr[], int n)
{
	int *st = new int[1000000];
	constructSTUtil(arr, 0, n-1, st, 0);
	return st;
}

int main()
{
	int N;
	cin>>N;

	for(int i=0; i<N; i++)
	{
		cin>>a[i];
	}

	int *st = constructST(a, N);

	long long sum = 0;

	for(int i=0; i<N; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			if(F(i,j) )
				sum += RMQ(st,0,N-1,i,j,0);
    		}
  	}

	cout<<sum<<endl;

	return 0;
}
