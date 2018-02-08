#include <iostream>
#include <vector>
#include <cstdio>
#include <stdlib.h>
#include <math.h>
#include <set>

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

struct node {
    set<int> *values;
    int l;
    int r;
    node *l_node;
    node *r_node;
};

node *gen_tree(int *A, int l, int r) {
    set<int> *s = new set<int>;
    for(int i=l; i<=r; i++)
        s->insert(A[i]);

    if(l==r) {
        node *root = new node{s, l, r, nullptr, nullptr};
        return root;
    }

    int mid = (l+r)/2;

    node *l_node = gen_tree(A, l, mid);
    node *r_node = gen_tree(A, mid+1, r);
    node *root = new node{s, l, r, l_node, r_node};

    return root;
}

void collect(node *root, int l, int r, vector<node*> &out) {
    if(root->l>=l && root->r<=r) {
        out.push_back(root);
        return;
    }
    int mid = (root->l + root->r)/2;

    if(l<=mid)
        collect(root->l_node, l, r, out);
    if(l>mid || r>mid)
        collect(root->r_node, l, r, out);
}

int find(node *root, int l, int r, int k) {
    vector<node *> nodes;
    collect(root, l, r, nodes);

    set<int> uni;
    for(const auto &iter : nodes)
        for(const auto &s_iter : *(iter->values))
            uni.insert(s_iter);

    int find_index=0;
    // for(const auto &iter : uni) {
    //     if(find_index==k)
    //         return iter;
    //     find_index++;
    // }
    return -1;
}

// in-order traversal
// Prints the tree
void print_tree(node *root) {
    if(root==nullptr)
        return;
    print_tree(root->l_node);

    cout << "L: " << root->l << "    R: " << root-> r << endl;
    for(const auto &iter : *(root->values))
        cout << iter << ' ';
    cout << endl << "---" << endl;

    print_tree(root->r_node);
}

int main() {
    int N,Q;
    cin >> N >> Q;

    int *A = new int[N];
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    node *root = gen_tree(A, 0, N-1);

    int ans = 0;
    while(Q--) {
        int a,b,c,d,k;
        cin >> a >> b >> c >> d >> k;

        int l = (a*max(ans,0)+b)%N; // + 1;
        int r = (c*max(ans,0)+d)%N; // + 1;
        if(l>r) {
            int tmp = l;
            l = r;
            r = tmp;
        }
        ans = find(root, l,r,k-1);
        cout << ans << endl;
    }

    return 0;
}
