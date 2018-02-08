N, W, L = [int(x) for x in input().split()]

trees = []

def enough_trees(months):
    global trees, N, W, L

    wood = 0
    for h,r in trees:
        if (h+r*months)>=L:
            wood += h + r*months
    if wood>W:
        return 1
    if wood<W:
        return -1
    return 0

max_h = max_r = -1
for i in range(N):
    h,r = [int(x) for x in input().split()]
    trees.append((h,r))

    if h > max_h:
        max_r = r
        max_h = h

ub_months = (W-max_h)//max_r + 1
lb_months = 0

best_months = None
while lb_months<=ub_months:
    months = (ub_months+lb_months)//2
    res = enough_trees(months)

    if res==0:
        best_months = months
        break
    elif res==1:
        best_months = months
        ub_months = months-1
    elif res==-1:
        lb_months = months+1

print(best_months)
