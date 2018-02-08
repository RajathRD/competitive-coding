
from math import gcd

T = int(input())
for _ in range(T):
    A,B,C,D = [int(x) for x in input().split()]
    if C==D:
        d = abs(A-B)
        ans=min(d%C, abs(min(A,B)+C*(d//C)+C))
        print(min(d, d%C))
    elif gcd(C,D)==1:
        print(0)
    else:
        print(min(abs(A-B),gcd(C,D)))
