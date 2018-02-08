import sys
sys.stdout.softspace=False
def check():
    for i in count:
        if i < 1:
            return True
    return False

def numbers(N):
    while N > 0:
        num = N%10
        count[num]+=1
        N = N/10
count = [0,0,0,0,0,0,0,0,0,0]

T = int(raw_input())
for _ in xrange(0,T):
    N = int(raw_input())
    if N == 0:
        print "Case #"+str(_+1)+":","INSOMNIA"
        continue
    i = 1
    while check():
        numbers(N*i)
    #    print count
        i += 1
    print "Case #"+str(_+1)+":",(i-1)*N
    count = [0,0,0,0,0,0,0,0,0,0]
