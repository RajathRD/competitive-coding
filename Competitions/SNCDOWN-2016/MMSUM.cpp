#include <cstdio>
#include<bits/stdc++.h>

using namespace std;

static struct IO {
	char tmp[1 << 10];
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

	// fast output routines

//#define putChar(c) putc_unlocked((c), stdout)
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


long long maxSubArraySum(vector<int> &num)
{
  long long max_so_far = num[0];
  long long curr_max = num[0];
  int size = num.size();
  for (int i = 1; i < size; i++)
  {

       curr_max = (num[i]>curr_max+num[i])?num[i]:curr_max+num[i];
       max_so_far = (max_so_far>curr_max)?max_so_far:curr_max;
  }
  return max_so_far;
}

int main()
{
  int T;
  int N;
  vector<int> num;
  cin>>T;
  while(T--)
  {
    num.clear();
    cin>>N;
    int neg = 1;
    for(int i=0; i<N; i++)
    {
      int temp;
      cin>>temp;
      if(temp>0)
        neg = 0;
      num.push_back(temp);
    }
    if( neg )
    {
       int max = -1000000000;
       for(int i=0; i<N; i++)
       if(num[i] > max)
          max = num[i];
       cout<<max<<endl;
    }
    // for(int i=0; i<N; i++)
    // {
    //   cout<<num[i]<<" ";
    // }
    // cout<<endl;
    else
    {
      long long sum = maxSubArraySum(num);

      for(int i=0; i<N; i++)
      {
         long long max_sum;
         if(num[i] < 0)
         {
           int temp = num[i];
           num[i] = 0;
           max_sum = maxSubArraySum(num);
           if( sum < max_sum)
              sum = max_sum;
           num[i] = temp;
         }
      }
      cout<<sum<<endl;
    }
  }
	return 0;
}
