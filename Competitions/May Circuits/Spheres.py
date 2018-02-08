N = int(raw_input())

rc = []

for _ in xrange(0,N):
    r,c = [int(x) for x in raw_input().split()]
    rc.append((r,c))

pos = 0
prevr = 0

for i in rc:
    pos += i[0] + prevr
    print pos,0,0
    prevr = i[0]
