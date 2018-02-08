M = 1000000007
v = []
prods = []
def query2( R ):
    product = 1;
    for i in xrange(0,len(v),R):
        product = product * v[i]
    return product

def qO1(R):
    return prods[R-1]

def query1(P, F):
    v[P-1] = F
    gen( N )

def gen( size ):
    for i in xrange(1,size+1):
        prods.append( query2(i) )


def dignprint(N):
    i = 0
    temp = N
    while temp >= 10:
        temp = temp//10
    print temp,N%M

N = int(raw_input())
v = [ int(x) for x in raw_input().split() ]
Q = int(raw_input())
gen(N)
print prods
while Q:
    q = [int(x) for x in raw_input().split() ]
    if q[0] == 1:
        prods = []
        query1(q[1],q[2])
        print prods
    else:
        dignprint(qO1(q[1]))
    Q -= 1
