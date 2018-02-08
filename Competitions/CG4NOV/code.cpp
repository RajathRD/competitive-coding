#include <iostream>
#include <string>
#include <list>

using namespace std;
int N;

int main () {
    int K;
    cin>>N>>K;
    int adj[N][N];
    for(int i = 0; i<N; i++)
        for(int j=0; j<N; j++)
            adj[i][j] = 0;
    int iter = N-1;
    while(iter--){
        int u, v;
        cin>>u>>v;
   
        adj[u-1][v-1] = 1;
        adj[v-1][u-1] = 1;
        // for(int i=0; i<N; i++)
        // {
        //     for(int j=0; j<N; j++)
        //         cout<<adj[i][j]<<" ";
        //     cout<<endl;
            
        // }
    }
    int fact = 1;
    for(int i=2; i<=K; i++)
    {
        fact = (fact*i) % 1000000007;
    }
    cout<< fact;




}
