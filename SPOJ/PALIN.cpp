#include <iostream>
#include <vector>
#include <cstdio>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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


int num[1000000];

void nextPalindromenot9(int n)
{
	int mid = n/2;
	bool ls = false;

	int i = mid-1;

	int j = (n % 2)?mid+1:mid;

	while (i>=0 && num[i]==num[j])
		i--,j++;

	if (i<0 || num[i]<num[j])
		ls = true;
	while (i >= 0)
	{
		num[j] = num[i];
		j++;
		i--;
	}
	if (ls == true)
	{
		int toChange = 1;
		i = mid - 1;

		if (n%2 == 1)
		{
			num[mid] += toChange;
			toChange = num[mid]/10;
			num[mid] = num[mid]%10;
			j = mid + 1;
		}
		else
			j = mid;
		while (i >= 0)
		{
			num[i] +=toChange;
			toChange = num[i]/10;
			num[i] %= 10;
			num[j++] = num[i--];
		}
	}
}

void generate(int n)
{
	int flag=1;

	for(int i=0; i<n; ++i)
		if(num[i] != 9)
			flag=0;
	if(flag)
	{
		cout<<1;
		for(int i=1; i<n; i++)
			cout<<0;
		cout<<1<<"\n";
	}

	else
	{
		nextPalindromenot9 (n);
		for(int i=0;i<n;i++)
			cout<<num[i];
		cout<<"\n";
	}
}

int main()
{
	long long T;
	string s;
	cin>>T;
	while(T--)
	{
			s.clear();
			cin>>s;
			for(int i=0;i<s.length();i++)
				num[i]=s[i] - '0';
		  generate(s.length());
	}
	return 0;
}
