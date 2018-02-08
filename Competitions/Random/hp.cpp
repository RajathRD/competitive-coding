#include <iostream>
#include <map>
#include<vector>
using namespace std;

int main()
{
	int N,Q,count;
	long long int temp,a,b,c,i,j;
	map<long long int, vector<long int> > pos;
	vector<int> x;
	map<long long int, vector<long int> >::iterator iter;
	cin>>N;
	cin>>Q;


	while(Q--)
	{
		count=0;
		cin>>a>>b>>c;

		for(i=a-1,j=b-1;i<=((a+b)/2)-1,j>=((a+b)/2);i++,j--)
		{

			if(S[i]<=c)
				count++;
			if(S[j]<=c)
				count++;
		}

		if(j==(a+b)/2)
			{
			if(S[j]<=c)
				count++;
			}
		if(i==((a+b)/2)-1)
			{
				if(S[i]<=c)
					count++;

			}
		cout<<count<<endl;
	}
}
