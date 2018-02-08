#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<math.h>
#include<map>
#include<algorithm>
#include<queue>
#include<string>
#include<climits>
#include<bitset>
#include<set>
#include<functional>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

#ifdef _WIN32
    #define gx getchar
    #define px putchar
    #define ps putchar(' ')
    #define pn putchar('\n')
    #define DEBUG 1
#else
    #define gx getchar_unlocked
    #define px putchar_unlocked
    #define ps putchar_unlocked(' ')
    #define pn putchar_unlocked('\n')
    #define DEBUG 0
#endif

//input
void scan(int &n)
{
    int sign = 1;
    n = 0;
    char c = gx();
    while( c < '0' || c > '9' )
    {
        if( c == '-' ) sign = -1;
        c = gx();
    }
    while( c >= '0' && c <= '9' ) n = (n<<3) + (n<<1) + c - '0', c = gx();  n = n * sign;
}
void lscan(ll &n)
{
    int sign = 1;
    n = 0;
    char c = gx();
    while( c < '0' || c > '9' )
    {
        if( c == '-' )
        sign = -1;
        c = gx();
    }
    while( c >= '0' && c <= '9' ) n = (n<<3) + (n<<1) + c - '0', c = gx();  n = n * (ll)(sign);
}
int sscan(char a[])
{
    char c = gx();
    while(c==' ' || c=='\n') c=gx();
    int i=0;
    while(c!='\n')a[i++] = c,c=gx();
    a[i]=0;
    return i;
}
int wscan(char a[])
{
    char c = gx();
    while(c==' ' || c=='\n') c=gx();
    int i=0;
    while(c!='\n' && c!=' ')a[i++] = c,c=gx();
    a[i]=0;
    return i;
}

//output
void print(int n)
{
    if(n<0)
    {
        n=-n;
        px('-');
    }
    int i=10;
    char o[10];
    do{o[--i] = (n%10) + '0'; n/=10;}while(n);
    do{px(o[i]);}while(++i<10);
}
void lprint(ll n)
{
    if(n<0LL)
    {
        n=-n;
        px('-');
    }
    int i=21;
    char o[21];
    do{o[--i] = (n%10LL) + '0'; n/=10LL;}while(n);
    do{px(o[i]);}while(++i<21);
}
void sprint(const char a[])
{
    const char *p=a;
    while(*p)px(*p++);
}


ll po(ll a, ll b, ll m)
{
	ll x=1,y=a;
	while(b > 0)
	{
		if(b%2 == 1)
		{
			x=(x*y);
			if(x>m) x%=m;
		}
		y = (y*y);
		if(y>m) y%=m;
		b /= 2;
	}
	return x;
}

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1000000007LL;
const int siz = 1000005;

string input;
int n,k,a;
int ans;
vector<string> v[30];

int check(string s, int n)
{
    int i,x,y,j;
    for(j=1;;j++)
    {
        x = n-j;
        y = x-j;
        if(y < 0) break;
        if( (s[n]==s[x]) && (s[n]==s[y]) ) return 0;
    }
    return 1;
}

void rec(string s, int done, int len)
{
    //if(done > k) return;
    if(len==n)
    {
        ++ans;
        return;
    }
    string temp;
    for(int i=0;i<a;i++)
    {
        temp = s;
        temp += i+'a';
        if(!check(temp,len)) continue;
        v[len+1].push_back(temp);
        //if(temp[len] == input[len]) rec(temp,done,len+1);
        //else rec(temp,done+1,len+1);
        rec(temp,done,len+1);
    }
}

int main()
{
    int t,i,j,k,temp;
    n = 26;
    a = 3;
    ans = 0;
    rec("",0,0);
    for(i=1;i<10;i++) for( j=0;j<v[i].size();j++) cout << i << " " << v[i][j] << endl;
    scan(t);
    // while(t--)
    // {
    //     cin >> a >> k >> input;
    //     n = input.size();
    //     if( (n>3) && (a==1) )
    //     {
    //         print(0);
    //         pn;
    //         continue;
    //     }
    //     ans = 0;
    //     rec("",0,0);
    //     print(ans);
    //     pn;
    // }
    while(t--)
    {
        cin >> a >> ::k >> input;
        n = input.size();
        k = v[n].size();
        ans = 0;
        for(i=0;i<k;i++)
        {
            temp = 0;
            for(j=0;j<n;j++)
            {
                if(input[j] != v[n][i][j]) ++temp;
            }
            if(temp <= ::k) ++ans;
        }
        print(ans);
        pn;
    }
    return 0;
}
