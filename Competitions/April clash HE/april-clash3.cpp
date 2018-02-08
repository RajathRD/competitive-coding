#include <iostream>
#include <cstdio>


using namespace std;

static struct IO {
	char tmp[1 << 10];

	// fast input routines
	char cur;
	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }

	inline operator bool() { return peekChar(); }
	inline static bool isBlank(char c) { return (c < '-' && c); }
	inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }

	inline IO& operator >> (char & c) { c = nextChar(); return *this; }

	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0; } return *this; }

	inline IO& operator >> (string & s) {
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }

	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}

#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}

defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)

	inline void putChar(char c) { putc_unlocked(c, stdout); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }

	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }

	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }


#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }

defineOutFor(int)
defineOutFor(long long)

#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;


int main()
{
  int T,n,q,maxn,count;
  int type,L,R,x;
  cin>>T;

  long long a[250000],front[250000],back[250000];
  while(T--)
  {
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    count = 1;
    maxn = -1;
    for(int i=0;i<n-1;i++)
    {
      // cout<<"Comparing:"<<maxn<<" "<<a[i]<<endl;
      if(a[i]>=maxn)
      {
        maxn=a[i];
        front[i]=count;
        count++;
      }
      else
        front[i]=front[i-1];
    }
    // cout<<"Comparing:"<<maxn<<" "<<a[n-1]<<endl;
    if(a[n-1]>=maxn)
      {
        front[n-1]=count;
      }
    else
      {
        front[n-1]=front[n-2];
      }
    // for(int i=0;i<n;i++)
    //   cout<<front[i]<<" ";
    // cout<<endl;

    // cout<<endl<<"BACK"<<endl;

    count = 1;
    maxn = -1;
    for(int i=n-1;i>0;i--)
    {
      // cout<<"Comparing:"<<maxn<<" "<<a[i]<<endl;
      if(a[i]>=maxn)
      {
        maxn=a[i];
        back[i]=count;
        count++;
      }
      else
        back[i]=back[i+1];
    }
    // cout<<"Comparing:"<<maxn<<" "<<a[n-1]<<endl;
    if(a[0]>=maxn)
      {
        back[0]=count;
      }
    else
      {
        back[0]=back[1];
      }
    // for(int i=0;i<n;i++)
    //   cout<<back[i]<<" ";
    // cout<<endl;
    while(q--)
    {
      cin>>type>>L>>R;

      if(type == 1)
      {
          if(L>R)
          {
            if(L==n || back[L-1]!=back[L] || back[R-1]-back[L-1]==0 )
              cout<<back[R-1]-back[L-1]+1<<"\n";
            else
              cout<<back[R-1]-back[L-1]<<"\n";
          }
          else if(L<R)
          {
            if(L==1 || front[L-1]!=front[L-2] || front[R-1]-front[L-1]==0 )
              cout<<front[R-1]-front[L-1]+1<<"\n";
            else
              cout<<front[R-1]-front[L-1]<<"\n";

          }
          else
            cout<<1<<"\n";
     }
     else if(type == 2)
     {
          cin>>x;
          for(int i=L-1;i<=R-1;i++)
            a[i]=a[i]+x;
          count = 1;
          maxn = -1;
          for(int i=0;i<n-1;i++)
          {
            // cout<<"Comparing:"<<maxn<<" "<<a[i]<<endl;
            if(a[i]>=maxn)
            {
              maxn=a[i];
              front[i]=count;
              count++;
            }
            else
              front[i]=front[i-1];
          }
          //  cout<<"Comparing:"<<maxn<<" "<<a[n-1]<<endl;
          if(a[n-1]>=maxn)
            {
              front[n-1]=count;
            }
          else
            {
              front[n-1]=front[n-2];
            }
          //  for(int i=0;i<n;i++)
          //    cout<<front[i]<<" ";
          //  cout<<endl;

          //  cout<<endl<<"BACK"<<endl;

          count = 1;
          maxn = -1;
          for(int i=n-1;i>0;i--)
          {
            // cout<<"Comparing:"<<maxn<<" "<<a[i]<<endl;
            if(a[i]>=maxn)
            {
              maxn=a[i];
              back[i]=count;
              count++;
            }
            else
              back[i]=back[i+1];
          }
          // cout<<"Comparing:"<<maxn<<" "<<a[n-1]<<endl;
          if(a[0]>=maxn)
            {
              back[0]=count;
            }
          else
            {
              back[0]=back[1];
            }
        //  for(int i=0;i<n;i++)
        //    cout<<back[i]<<" ";
        //  cout<<endl;
     }
   }
  }
  return 0;
}
