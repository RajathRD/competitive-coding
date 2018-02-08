#include <bits/stdc++.h>

using namespace std;

struct point
{
	double x,y;
};

int main()
{
		std::clock_t start;
		double duration;

    vector <point > points;
    vector <point> row;
    int N;
    int count = 0;
    point p;
    vector < vector<point> > kplusj;
		cin>>N;
    if(N<1000)
    {
			start = std::clock();
    	for( int i=0; i<N; i++)
		{
    	cin>>p.x>>p.y;
    	points.push_back(p);
    	}

    for(int i=0 ; i<points.size() ; i++)
    {
    	row.clear();
    	cout<<i+1<<endl;
    	for(int j=i; j<points.size(); j++)
    	{
    		p.x = points[i].x + points[j].x;
    		p.y = points[i].y + points[j].y;
    		row.push_back(p);
   			cout<<p.x<<","<<p.y<<" ";
    	}
    	kplusj.push_back(row);
    	cout<<endl;
    }

    for(int k=0; k<points.size(); k++)
    {
			cout<<k+1<<endl;
     	for(int i=0;i<kplusj.size();i++)
    	{
    		if(i!=k)
	    		for(int j=1;j<kplusj[i].size();j++)
	    		{
					if(!(kplusj[i][j].x == 0 && kplusj[i][j].y == 0) && j+i!=k)
					{
	    				long double sum = points[k].x * kplusj[i][j].x + points[k].y * kplusj[i][j].y;
	    				if(sum == 0)
	    				{
	    					cout<<k+1<<","<<i+1<<","<<j+1<<endl;
	    					count++;
	    				}
					}
	    		}
    	}
			cout<<"Count:"<<count*2<<endl;
			duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    }
			cout<<count*2<<endl;
			cout<<duration<<endl;
    }
    return 0;
}
