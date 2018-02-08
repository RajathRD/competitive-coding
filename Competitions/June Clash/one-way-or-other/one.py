T = int(input())
for t in range(T):
    n = int(input())

    # first 3
    mc, mr, mx = [int(x)%2 for x in input().split()]

    flag = True
    for _ in range(n-1):
        c,r,x = [int(x)%2 for x in input().split()]
        if x==mx:
            if not((mr==r and mc==c) or (mr!=r and mc!=c)):
                flag = False
        else:
            if not ((mr!=r and mc==c) or (mr==r and mc!=c)):
                flag = False

    if flag:
        print("Yes")
    else:
        print("No")
