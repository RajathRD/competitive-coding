#include <iostream>
#include <map>
#include <vector>
#include <math.h>

using namespace std;

int squaresum(int x)
{
	int temp,sum;

	while(x>0)
	{
		temp=x%10;
		sum+=(temp*temp);
		x=x/10;
	}
	return sum;
}
int main()
{
	int N,temp;
	long long int result;
	map<int, int> count;
	map<int,int>::iterator iter;


	N=10;
	for(long int i=0;i<=pow(10,N);i++)
	{
		temp=squaresum(i);
		iter=count.find(temp);
		if(iter!=count.end())
			count[temp]++;
		else
			count[temp]=1;
	}
	result=0;
	for(iter=count.begin();iter!=count.end();iter++)
	{
		temp=0;
//		cout<<iter->first<<" "<<iter->second<<endl;
		for(int i=0;i<=iter->second-1;i++)
		{
			temp+=i;
		}
		result+=iter->second+(temp*2);
	}
	result=result%1000000007;
	cout<<result<<endl;
	return 0;
}
