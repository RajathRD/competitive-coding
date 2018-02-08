def dfs(u, adj, visited):
    if adj.get(u)==None:
        return
    for v in adj.get(u):
        if not visited[v]:
            visited[v] = True
            dfs(v, adj, visited)

def find_comps(N, adj):
    count = 0
    visited = [False for _ in xrange(N)]
    for i in xrange(N):
        if not visited[i]:
            dfs(i, adj, visited)
            count += 1
    return count


T = int(input())
for _ in range(T):
    N,M = [int(x) for x in raw_input().split()]

    adj = {}
    for m in xrange(M):
        a,b = [int(x) for x in raw_input().split()]
        if adj.get(a)==None:
            adj[a] = [b]
        else:
            adj[a].append(b)
        if adj.get(b)==None:
            adj[b] = [a]
        else:
            adj[b].append(a)

    capital = int(raw_input()) #capital. screw it

    count = find_comps(N, adj)
    if count==1:
        print "Yes"
    else:
        print "No"
        print (count-1)
