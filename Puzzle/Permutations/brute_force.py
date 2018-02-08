from itertools import permutations

# alpha = str(raw_input())
alpha = 'abcde'
result = [0]*len(alpha)

perms = [perm for perm in permutations(alpha)]
# print perms
for i in xrange(len(perms)-1):
	substrings_i = [perms[i][x:y+1] for x in xrange(len(perms[i])) for y in xrange(x, len(perms[i]))]*(len(perms)-i-1)
	substrings_j = [perms[j][x:y+1] for j in xrange(i+1, len(perms)) for x in xrange(len(perms[j])) for y in xrange(x, len(perms[j]))]
	# print substrings_i
	# print substrings_j
	for p,q in zip(substrings_i, substrings_j):
		result[len(p)-1] += p == q
	# print result
print [(i+1,j) for i,j in enumerate(result)]