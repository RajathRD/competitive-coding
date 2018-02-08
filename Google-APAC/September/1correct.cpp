#include <bits/stdc++.h>

#define DG(x) cerr << #x << " is " << x << endl

#define F first
#define S second
#define pb push_back

typedef long long L;

using namespace std;

const int N = 22;
char a[N][N];
int r, c, s;
double p, q;

struct Solution {
  double dfs(int x, int y, map <pair<int,int>, int> pos) {
    double res = 0;

    int sz = 0;
    for (auto pp : pos) {
      sz += pp.second;
    }

    if (sz < s) {
      for (int dx = -1; dx < 2; ++dx) {
        for (int dy = -1; dy < 2; ++dy) {
          if ((dx == 0 || dy == 0) && (dx != 0 || dy != 0)) {
            if (x + dx < 0 || x + dx >= r) continue;
            if (y + dy < 0 || y + dy >= c) continue;

            double pr = 0, now = 0;
            pr = a[x + dx][y + dy] == '.' ? q : p;
            now = pow(1.0 - pr, pos[{x + dx, y + dy}]) * pr;

            pos[{x + dx, y + dy}]++;
            res = max(res, now + dfs(x + dx, y + dy, pos));
            pos[{x + dx, y + dy}]--;
            if (pos[{x + dx, y + dy}] == 0) {
              pos.erase({x + dx, y + dy});
            }
          }
        }
      }
    }

    return res;
  }

  void solve() {
    int t;
    scanf("%d", &t);

    for (int tt = 1; tt <= t; ++tt) {
      printf("Case #%d: ", tt);
      int rx, cx;
      scanf("%d %d %d %d %d", &r, &c, &rx, &cx, &s);
      scanf("%lf %lf", &p, &q);

      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          char pp[2];
          scanf("%s", pp);
          a[i][j] = pp[0];
        }
      }

      printf("%.17f\n", dfs(rx, cx, {}));
    }
  }

  struct Debug {
    L random(L l, L r) {
      return l + (rand() * 1./RAND_MAX) * (r - l);
    }

    L pn(L lo, L hi, bool rnd = 0) {
      if (rnd) {
        L nn = random(lo, hi);
        printf("%lld\n", nn);
        return nn;
      } else {
        printf("%lld\n", hi);
        return hi;
      }
    }

    void par(L lo, L hi, L cnt = 1, bool rnd = 0) {
      for (int i = 0; i < cnt; ++i) {
        printf("%lld%c", rnd ? random(lo, hi) : hi, (i == cnt - 1) ? '\n': ' ');
      }
    }

    void gen() {
      freopen("IN.txt", "w", stdout);
      // input format
    }
  };

  void run() {
    // runs
   // Debug db;
   // db.gen();
    freopen("IN.txt", "r", stdin);
    freopen("OUT.txt", "w", stdout);

    clock_t b = clock();
    solve();
    clock_t e = clock();

    cerr << "Time Taken for random case : " << (e - 1.0 * b) / CLOCKS_PER_SEC << endl;
  }

};

int main()
{
  Solution solution;
  solution.solve();
  return(0);
}
