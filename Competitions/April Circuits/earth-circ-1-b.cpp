#include <iostream>
#include <vector>
#include <cstdio>
#include <stdlib.h>
#include <math.h>

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

#define SWAP(a,b) { a=a+b; b=a-b; a=a-b; }


class obj
{
public:
	long val;
	int pos;
	int rank;
};

long long position(const vector<obj> &v,long long toFind)
{
  for(unsigned long long i=0;i<v.size();i++)
    if( v[i].pos == toFind )
    {
  //     cout<<"FOUND AT "<<i<<endl;
       return i;
    }
  return 0;
}

int main()
{
  long long it;
  long long N,Q;
  obj part;
	int change;
	long long sum = 0;
  vector <obj> v;
  cin>>N>>Q;
  vector<bool> isPresent(N+1,false);
  v.reserve(N+1);
	int apos[N+1];
  while(Q--)
  {

    long long a,b;
    cin>>a>>b;
    if(isPresent[a])
    {
      v[apos[a]].val +=b;
			it = apos[a];
			change = 0;
			sum+= b*v[apos[a]].rank;
			if(v[apos[a]].val == v[apos[a]-1].val)
				change = 1;
    }
    else
    {
      part.pos = a;
			part.val = b;
      v.push_back(part);
			apos[a] = v.size() - 1;
		  it = v.size() - 1;
		  isPresent[a]=true;
			change = 1;
    }

	if(it != 0)
		while( v[it].val > v[it-1].val && it>0)
		{
			SWAP(v[it].val,v[it-1].val);
			SWAP(apos[v[it].pos],apos[v[it-1].pos]);
			SWAP(v[it].pos,v[it-1].pos);
			it--;
			change = 1;
		}
		if(change==1)
		{
			sum=0;
      long long rank = 1;
      v[0].rank = 1;
			sum += v[0].rank * v[0].val;
			int SIZE = v.size();
      for(unsigned long long i=1;i<SIZE;i++)
      {
        if(v[i].val == v[i-1].val )
        {
          v[i].rank = rank;
					sum += v[i].rank * v[i].val;
        }
        else{
          v[i].rank = i+1;
					sum += v[i].rank * v[i].val;
          rank = i+1;
        }
      }
		}
			// for(int i=0;i<v.size();i++)
			// {
			// 	cout<<"I: "<<i<<" RANK:"<<v[i].rank<<" VAL:"<<v[i].val<<" POS:"<<v[i].pos<<" APOS:"<<apos[v[i].pos]<<endl;
			// }

      cout<<sum<<"\n";

  }
  return 0;
}
