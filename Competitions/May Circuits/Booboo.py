def possible(threshold,v,M):
    count = 0
    sum = 0
    for ele in v:
        if ele > threshold:
            return False
        if sum+ele <= threshold:
            sum += ele
        else:
            count = count + 1
            sum = ele
    count = count + 1
    return count <= M

N,M = [ int(_) for _ in raw_input().split() ]
t = [ int(_) for _ in raw_input().split() ]
total = sum(t)

minimum = None

while minimum is None:
    low = 0
    high = total
    while low <= high:
        mid = ( low + high )/2

        if possible(mid,t,M):
            minimum = mid
            high = mid - 1
        else:
            low = mid + 1
    M = M - 1

print minimum
