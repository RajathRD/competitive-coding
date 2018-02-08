#include <bits/stdc++.h>

using namespace std;

bool possible(long long threshold,vector<long long> &v,int M )
{
  int count = 0;
  long long sum = 0;
  int size = v.size();
//  cout<<size<<endl;
  for(int i=0; i<size; i++)
  {
//    cout<<"Enter";
  //  cout<<"Considering: "<<v[i]<<endl;
    if( sum+v[i] <= threshold )
    {
      sum += v[i];
  //    cout<<"Sum: "<<sum<<endl;
    }
    else
    {
      count++;
  //    cout<<count<<" "<<endl;
      sum = v[i];
    }
  }
//  cout<<count<<" "<<M;
  return count <= M;
}

int main()
{
	int N,M;
	cin>>N>>M;
	vector<long long> t;
	long long sum = 0;

	for(int i=0; i<N; i++)
	{
    int temp;
    cin>>temp;
		t.push_back(temp);
		sum += temp;
	}
    t.push_back(100000000000000000);
	long long low = 0,mid;
	long long high = sum;
	long long min = sum;

	while( high - low > 1 )
	{
    mid = (low+high)/2;
//    cout<<low<<" "<<high<<" "<<mid<<endl;


    if( possible(mid,t,M) )
    {
        min = mid;
        high = mid;
    }

    else
    {
        low = mid;
    }

	}
  cout<<min<<endl;

  return 0;
}
