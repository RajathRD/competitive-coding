#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
		int i,j;
};
int mat[51][51];
bool visited[51][51];
vector<node> addTrail(int mi, int mj,int N,int M)
{
	vector<node> trail;
	bool flag = false;
	node temp;
	temp.i = mi;
	temp.j = mj;
	visited[mi][mj] = true;
	trail.push_back(temp);

	for(int i=0; i<trail.size(); i++)
	{
		int mi = trail[i].i;
		int mj = trail[i].j;
		if ( mat[mi+1][mj] < mat[mi][mj] || mat[mi][mj-1] < mat[mi][mj] || mat[mi][mj+1] < mat[mi][mj] ||  mat[mi-1][mj] < mat[mi][mj] )
		{
			flag = true;
		}
			// cout<<"Added1";

		// cout<<mat[trail[i].i][trail[i].j]<<endl;
		if( mat[trail[i].i+1][trail[i].j] == mat[mi][mj] && visited[trail[i].i+1][trail[i].j] == false )
		{
			// cout<<"Added1";
			// cout<<"Added1";
			// cout<<"Added1";
  			visited[trail[i].i+1][trail[i].j] = true;
			temp.i = trail[i].i+1;
			temp.j = trail[i].j;
			trail.push_back(temp);
			if( trail[i].i+1==0 || trail[i].j==0 || trail[i].j==M-1 || trail[i].i+1 == N-1 )
				flag = true;
		}
		if( mat[trail[i].i-1][trail[i].j] == mat[mi][mj] && visited[trail[i].i-1][trail[i].j] == false)
		{
			// cout<<"Added2";
			visited[trail[i].i-1][trail[i].j] = true;
			temp.i = trail[i].i-1;
			temp.j = trail[i].j;
			trail.push_back(temp);
			if( trail[i].i-1==0 || trail[i].j==0 || trail[i].j==M-1 || trail[i].i-1 == N-1 )
				flag = true;
		}
		if( mat[trail[i].i][trail[i].j+1] == mat[mi][mj] && visited[trail[i].i][trail[i].j+1] == false)
		{
			// cout<<"Added3";
			visited[trail[i].i][trail[i].j+1] = true;
			temp.i = trail[i].i;
			temp.j = trail[i].j+1;
			trail.push_back(temp);
			if( trail[i].i==0 || trail[i].j+1==0 || trail[i].j+1==M-1 || trail[i].i == N-1 )
				flag = true;
		}
		if( mat[trail[i].i][trail[i].j-1] == mat[mi][mj] && visited[trail[i].i][trail[i].j-1] == false)
		{
			// cout<<"Added4";
			visited[trail[i].i][trail[i].j-1] = true;
			temp.i = trail[i].i;
			temp.j = trail[i].j-1;
			trail.push_back(temp);
			if( trail[i].i == 0 || trail[i].j-1==0 || trail[i].j-1==M-1 || trail[i].i == N-1 )
					flag = true;

		}
	}
	if( flag )
	{
		vector<node> ret;
		return ret;
	}
	return trail;

}

int main()
{
	int original[51][51];
	vector< vector<node> > trails;
	int T,N,M;
	cin>>T;
	for(int t=0; t<T; t++)
	{
		cin>>N>>M;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				cin>>mat[i][j];
				original[i][j] = mat[i][j];
			}
		}
		int times = 1000;
		while(times--)
		{
			trails.clear();
			for(int i=0; i<N;i++)
				for(int j=0; j<M; j++)
					visited[i][j] = 0;
			for(int i=1; i<N-1; i++)
			{
				for(int j=1; j<M-1; j++)
				{
					if( visited[i][j] == 0 )
					{
						trails.push_back(addTrail(i,j,N,M));
					}
				}
			}

			for(int i=0; i<trails.size(); i++)
			{
				int min;
				if( trails[i].size() != 0)
					 min = mat[trails[i][0].i][trails[i][0].j];
				for(int j=0; j<trails[i].size(); j++)
				{
					int mi = trails[i][j].i;
					int mj = trails[i][j].j;
					if( mat[mi+1][mj] != mat[mi][mj] && mat[mi+1][mj] > min )
						min = mat[mi+1][mj];
					if( mat[mi-1][mj] != mat[mi][mj] && mat[mi-1][mj] > min )
						min = mat[mi-1][mj];
					if( mat[mi][mj+1] != mat[mi][mj] && mat[mi][mj+1] > min )
						min = mat[mi][mj+1];
					if( mat[mi][mj-1] != mat[mi][mj] && mat[mi][mj-1] > min )
						min = mat[mi][mj-1];
				}
				int change = 1;
				for(int j=0; j<trails[i].size(); j++)
				{

					int mi = trails[i][j].i;
					int mj = trails[i][j].j;
					if( mi+1 == N-1 || mi-1 == 0 || mj+1 == M-1 || mj-1 == 0)
					{
						if( mat[mi+1][mj] <= mat[mi][mj] )
							change = 0;
						else if( mat[mi+1][mj] < min )
							min = mat[mi+1][mj];
						if(  mat[mi-1][mj] <= mat[mi][mj] )
							change = 0;
						else if( mat[mi-1][mj] < min )
							min = mat[mi-1][mj];
						if( mat[mi][mj+1] <= mat[mi][mj] )
							change = 0;
						else if( mat[mi][mj+1] < min )
							min = mat[mi][mj+1];
						if( mat[mi][mj-1] <= mat[mi][mj] )
							change = 0;
						else if( mat[mi][mj-1] < min )
							min = mat[mi][mj-1];
					}
				}
				if(change)
					for(int j=0; j<trails[i].size(); j++)
					{

						int mi = trails[i][j].i;
						int mj = trails[i][j].j;
						mat[mi][mj] = min;
					}
			}

		}
		long long int sum = 0;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				sum += (mat[i][j] - original[i][j]);
			}
		}
		cout<<"Case #"<<t+1<<": "<<sum<<endl;
	}

	return 0;
}
