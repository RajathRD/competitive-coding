#include <bits/stdc++.h>
using namespace std;
struct node
{
	double r;
	double c;
};

bool use(node a, node b)
{
	return a.c>b.c;
}

int main()
{
    int N;
    cin>>N;
    vector<node> points;
    for(int i=0;i<N;i++)
    {
    	node temp;
    	cin>>temp.r>>temp.c;
    	points.push_back(temp);
    }

    double posr = -1000+points[0].r;
    double posl = -1000-points[0].r;
    double posrc = points[0].c ,poslc = points[0].c;
    double prevr = points[0].r;
    cout<<"-1000 0 0\n";
    for(int i=1;i<N;i++)
    {
    //	cout<<posrc<<" "<<poslc<<endl;
    	if( posrc > poslc )
    	{
    		posr += points[i].r;
    		cout<<posr<<" 0 0"<<endl;
   			posr += points[i].r;
   			posrc = points[i].c;
    	}
    	else
    	{
    		posl -= points[i].r;
    		cout<<posl<<" 0 0"<<endl;
    		posl -= points[i].r;
    		poslc = points[i].c;
    	}
    }
    return 0;
}
