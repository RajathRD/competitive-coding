T = int(input())
for i in range(T):
    C = int(input())
    N = int(input())
    items = [int(x) for x in input().split()]
    dic = {}
    for x in range(len(items)):
        if items[x] in dic:
            print("Case #"+str(i+1)+":",dic[items[x]],x+1)
            break
        else:
            dic[C-items[x]] = x+1
