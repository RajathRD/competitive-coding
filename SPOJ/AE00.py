n=int(input())
if(n==1):
    print(n)
else:
    count=0
    for i in range(1, (n//2)+1):
        for j in range(i, n+1):
            if(i*j<=n):
                count=count+1
            else:
                break
    print(count)
