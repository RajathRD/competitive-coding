#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> boys;
    int count1 = 0,count2 = 0,i,j,count;
    int T,N;
    cin>>T;

    string line;

    while(T--)
    {
      cin>>N;
    	line.clear();
    	cin>>line;
	    for(i=0;i<line.length();i++)
	    {
	   		if(i%2 == 0)
	   		{
	   			if( line[i] != 'B')
	   				count1++;
	   		}
	   		else
	   		{
	   			if( line[i] != 'G')
	   				count1++;
	   		}

	   	}
	    for(i=0;i<line.length();i++)
	    {
	   		if(i%2 == 0)
	   		{
	   			if( line[i] != 'G')
	   				count2++;
	   		}
	   		else
	   		{
	   			if( line[i] != 'B')
	   				count2++;
	   		}
	    }
	   	count = (count1>=count2)?count2/2:count1/2;
	   //	cout<<count1<<" "<<count2<<endl;
	    cout<<count<<endl;
    }

    return 0;
}
