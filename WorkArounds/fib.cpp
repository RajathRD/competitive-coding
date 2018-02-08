#include <iostream>
#include <math.h>

using namespace std;
#define M 1000000007

int fast_pow(double base, long long n)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2);
    if(n%2==0)
    {
        long long int res=halfn*halfn;
        return res % M;
    }
    else
    {
        long long int res=( halfn * halfn );
        res=res%M;
        res=(long long int)res*base;
        return res % M;
    }
}

int main()

{

    double gr = (1 + sqrt(5))/2;
    double diff = 1/sqrt(5);
    long long int fib;
    long long int f1,f2;
    int n;
    cout<<pow(2,10)<<endl;
    cout << "Enter number: ";
    cin >> n;
    for(int i=0;i<n;i++)
    {

        cout << ((pow(gr, i) - pow(1 - gr, i))*(1/sqrt(5))) << ":  " << i << "th Fibonnaci number."<<endl;
    }
    return 0;

}
