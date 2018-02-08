fact=[1,1]
M = 1000000007

def power(a):
    b = M - 2
    x = 1
    y = a
    while b > 0:
        if b%2 == 1:
            x = x*y
            if x > M:
                x %= M
        y = y*y
        if y>M:
            y %= M
        b /= 2
    return x

def Euler(N):
    return power(N)

def factorial():
        for i in xrange(2,100001):
                fact.append((fact[i-1]*i)%M)

def nck(n,k):
        return fact[N] * ( Euler(fact[k]) * Euler(fact[n-k]) )

factorial()

T = int( raw_input() )
while T:
    num0 = 0
    total = 0
    N,K = [int(x) for x in raw_input().split()]
    T -= 1
    num = [int(x) for x in raw_input().split()]
    for i in num:
            if i == 0:
                    num0 += 1
    K = min(N,K)
    if K % 2 == 0:
        X = 0
    else:
        X = 1
    if num0 == 0:
        if N == K:
            total = pow(2,N-1)
        else:
            if N-K >= K:
                for i in xrange ( X,K+1,2 ):
                    total += nck(N,i)
                #print i, nck(N,i)
            else:
                for i in xrange ( K+2,N+1,2 ):
                    total += nck(N,i)
                total = pow(2,N-1) - total
    else:
        total = pow(2,N-num0)
            #print N-num0,i,nck(N-num0,i)

    print total%M
