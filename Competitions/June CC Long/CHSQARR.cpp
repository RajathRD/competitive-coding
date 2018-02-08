#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N,M;
int aux[201][201];
int preProcess(int mat[201][201])
{
cout<<" "<<N<<" "<<M;
for(int i=0; i<N; i++)
  for(int j=0;j<M; j++)
    cout<<mat[i][j];
for (int i=0; i<N; i++)
	aux[0][i] = mat[0][i];

for (int i=1; i<M; i++)
	for (int j=0; j<N; j++)
		aux[i][j] = mat[i][j] + aux[i-1][j];

for (int i=0; i<M; i++)
	for (int j=1; j<N; j++)
		aux[i][j] += aux[i][j-1];
}

int sumQuery(int tli, int tlj, int rbi,
											int rbj)
{

	int res = aux[rbi][rbj];

	// Remove elements between (0, 0) and (tli-1, rbj)
	if (tli > 0)
	 res = res - aux[tli-1][rbj];

	// Remove elements between (0, 0) and (rbi, tlj-1)
	if (tlj > 0)
  	res = res - aux[rbi][tlj-1];

  if (tli > 0 && tlj > 0)
	 res = res + aux[tli-1][tlj-1];

	return res;
}
int main()
{
  int R,C,Q,n,m,MAX,MIN;
  long long sum = 0;
  int a[201][201];
  cin>>N>>M;
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<M; j++)
    {
      scanf("%d",&a[i][j]);
    }
  }


  preProcess(a);
  cin>>Q;
  while(Q--)
  {
    cin>>n>>m;
    MIN = 1000000000;
    for(int x=0; x<N-n+1; x++)
    {
      // cout<<"X: "<<x;
      for(int y=0; y<M-m+1; y++)
      {
        // cout<<" Y:"<<y<<endl;
        // MAX = a[x][y];
        sum = sumQuery(x , y, x+n-1, x+m-1);
        // sum = MAX*n*m - sum;
        // if( MIN > sum )
        //   MIN = sum;
        cout<<MAX<<endl;
      }
    }
    // cout<<MIN<<endl;
  }
}
