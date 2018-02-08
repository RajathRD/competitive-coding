#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
  int T,N;
  cin>>T;
  while(T--)
  {
    int start,end,l,r;
    long long int result;
    int a[200001];
    int ul[200001];
    int ur[200001];
    int vl[200001];
    int vr[200001];
    cin>>N;
    for(int i=0; i<N; i++)
    {
      cin>>a[i];
      ur[i] = vl[i] = 0;
      ul[i] = vr[i] = 0;
    }
    cin>>start>>end;

    // Right U to V
    // cout<<1<<endl;
    l = start-1;
    r = end-1;
    while ( l < r )
    {
      l++;
      ur[l] = ur[l-1] + a[l-1];
    }


    // Left V to U
    l = start-1;
    r = end-1;
    // cout<<2<<endl;
    while ( r > l )
    {

      r--;
      vl[r] = vl[r+1] + a[r];
    }

    // left from U TO V
    l = start - 1;
    r = end - 1;
    // cout<<3<<endl;
    while ( l != r )
    {

      l--;
      if ( l < 0 )
        l += N;

      if( l+1 == N )
        ul[l] = ul[0] + a[l];
      else
        ul[l] = ul[l+1] + a[l];

    }

    // right from V to U
    l = start - 1;
    r = end - 1;
    // cout<< l << r << endl;
    while ( r != l )
    {

      r ++;
      if( r == N )
        r -= N;
      if( r-1 == -1)
        vr[r] = vr[N-1] + a[N-1];
      else
        vr[r] = vr[r] + a[r-1];
    }

    cout<<"A: ";
    for(int i=0; i<N; i++)
      cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0; i<N; i++)
      cout<<ur[i]<<" ";
    cout<<endl;
    for(int i=0; i<N; i++)
      cout<<ul[i]<<" ";
    cout<<endl;
    for(int i=0; i<N; i++)
      cout<<vl[i]<<" ";
    cout<<endl;
    for(int i=0; i<N; i++)
      cout<<vr[i]<<" ";
    cout<<endl;

    // l = start - 1;
    // r = end - 1;
    // result = min(ul[end-1],ur[end-1]);
    //
    // while( l != r)
    // {
    //   l++;
    //   if( ur[l] < 0 )
    //   {
    //     int i = l;
    //     int j = r;
    //     int min = 0;
    //     while ( j != i)
    //     {
    //       j--;
    //
    //       if(  vl[j] < 0 && vl[j] < min )
    //         min = vl[j];
    //     }
    //     // cout<<ur[l]<<" "<<min<<endl;
    //     long long check = (ur[l] + min)*2 + ul[r];
    //     if( check < result )
    //       result = check;
    //
    //
    //   }
    // }
    //
    //
    // l = start - 1;
    // r = end - 1;
    // while( l != r)
    // {
    //   l--;
    //   if( l-1 < 0)
    //     l += N;
    //   if( ul[l] < 0 )
    //   {
    //     int i = l;
    //     int j = r;
    //     int min = 0;
    //     while ( j != i)
    //     {
    //       j+=1;
    //       j%=N;
    //
    //         if( vr[j]<0 && vr[j] < min  )
    //           min = vr[j];
    //     }
    //     long long check = (ul[l] + min)*2 + ur[end-1];
    //     // cout<<ul[l]<<" "<<min<<" W:"<<ur[end-1]<<" "<<check<<endl;
    //     // cout<<check<<" "<<result<<endl;
    //     if( check < result )
    //       result = check;
    //
    //   }
    // }
    //
    // l = start - 1;
    // r = end - 1;
    // int check = ul[r];
    // int min = 0;
    // while( l != r)
    // {
    //   r--;
    //   if ( min > vl[r] )
    //     min = vl[r];
    // }
    // // cout<<check<<" "<<min<<endl;
    // if( check + (min*2) < result)
    //   result = check + (min * 2);
    //
    // l = start - 1;
    // r = end - 1;
    // check = ur[r];
    // min = 0;
    // while( l != r)
    // {
    //   r++;
    //   r%=N;
    //   if ( min > vr[r] )
    //     min = vr[r];
    // }
    // // cout<<check<<" "<<min<<endl;
    // if( check + (min*2) < result)
    //   result = check + (min * 2);
    // cout<<result<<endl;
    //

  }
  return 0;
}
