memo = {}
def F(n, x=True, k = 4):
    memo.clear()
    if n == 0: return 1
    if k == 0: return 0
    if (n, x) in memo: return memo[n,x]
    i = 1
    a, b = 1, 1
    while b + a <= n:
        a, b = b, a + b
    memo[n,x] = (F(n - b, True, k - 1) if x else 0) + F(n - a, n - a < a, k-1)
    return memo[n,x]


for _ in xrange(0,435897) :
	i = 1
