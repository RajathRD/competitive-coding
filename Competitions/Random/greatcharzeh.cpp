#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n,m,pos;
    cin>>n>>m;
    int a[n],maxn;
    int f[m+n-1];
    int max[n][2];

    for(int i=0;i<n;i++)
    	cin>>a[i];
    for(int i=0;i<n+m-1;i++)
    	cin>>f[i];
    vector< vector<int> > diff;
    vector< int > eachdiff;
    for(int i=0;i<n;i++)
    {
    	eachdiff.clear();
    	for(int j=0;j<n;j++)
    			eachdiff.push_back(f[a[i]+j]);
    	diff.push_back(eachdiff);
    }

     //for(int i=0;i<n;i++)
     //{
     //	for(int j=0;j<n;j++)
     //			cout<<diff[i][j]<<" ";
     //	cout<<endl;
     //}
    vector< vector<int> > sorted;
    sorted=diff;
    vector< vector<int> >::iterator iter1;
    vector<int>::iterator iter2;
    //cout<<"Iterator"<<endl;
    for(iter1=sorted.begin();iter1!=sorted.end();iter1++)
    {
    	sort((*iter1).begin(),(*iter1).end());
    	 //for(iter2=(*iter1).begin();iter2!=(*iter1).end();iter2++)
    	 //{

    	 //	cout<<*iter2<<" ";
    	 //}
    	 //cout<<endl;
    }
    int visited[n];
    std::fill_n(visited, n, 0);

 //   cout<<endl;
    int dist=0;
    map<int,int> set;
    map<int,int>::iterator iter3;
    for(int i=0;i<n;i++)
    {
      if(visited[i]==0)
      {
//        cout<<"Dist="<<dist<<endl;
	       max[i][0]=sorted[i][dist];
//	    cout<<i<<"'s "<<max[i][0]<<endl;
	       for(int j=0;j<n;j++)
			   {
				   if(diff[i][j]==max[i][0])
					 {
						pos=j;
				   }
		     }
	//	cout<<"Pos="<<pos<<endl;
    	iter3=set.find(pos);
        if(iter3==set.end())
        	{
        		set[pos]=i;
       // 		cout<<pos<<" set---------------------"<<endl;
        		max[i][1]=pos;
        		dist=0;
            visited[i]=1;
        	}
        else
        {
		//		cout<<"Collision with "<<pos<<endl;
		//		cout<<f[a[i]+pos]<<"<>"<<f[a[iter3->second]+pos]<<endl;
        if(max[i][0]<max[iter3->second][0] || sorted[i][dist]<sorted[iter3->second][dist])
        	 // 	if(f[a[i]+pos]<f[a[iter3->second]+pos])
        		{
        		//		cout<<max[i][0]<<" "<<max[iter3->second][0]<<endl;
        			    	max[i][1]=pos;
        		//		cout<<pos<<" set"<<endl;
            		    visited[i]=1;
        			    	i=iter3->second-1;
            	//		cout<<"Loop to "<<i<<endl;
                		visited[iter3->second]=0;
                		dist=0;
        			}
        		else
        		{
        			dist++;
        			--i;
        		}
      	}
    }
    }
    // for(int i=0;i<n;i++)
    // {
    // 	cout<<i<<" ";
    // 	for(int j=0;j<2;j++)
    // 			cout<<max[i][j]<<" ";
    // 	cout<<endl;
    // }
    maxn=0;
    for(int i=0;i<n;i++)
    {
    //	cout<<f[a[i]+max[i][1]]<<" ";
    	if(maxn<f[a[i]+max[i][1]])
    		maxn=f[a[i]+max[i][1]];

    }
    cout<<maxn<<endl;
    return 0;
}
Language: C++
