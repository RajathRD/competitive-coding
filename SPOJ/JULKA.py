for _ in range(10):
    N = int(input())
    diff = int(input())

    if N%2 == 0:
        klaudia = N//2+ (diff//2)
    else:
        klaudia = N//2+1+ (diff-1)//2
    print (klaudia)
    print (N - klaudia)
