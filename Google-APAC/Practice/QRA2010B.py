T = int(input())
for i in range(T):
    words = input().split()
    print("\nCase #"+str(i+1)+":",end = ' ')
    for j in reversed(words):
        print(j,end=' ')
