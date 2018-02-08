"""
	Take a set of characters and find the sets permutations. Compare the permutations with the first set of character. 
	and print the number of pairs which have 1, 2, 3 or .... n consecutive one-to-one character matching with each other
	
	Consider set of characters ABCD.
	Permutations:
	ABCD, ACDB, DBCA
	Now compare each permutation with ABCD
	in ABCD, ACDB we notice A in both occuring at same position, so they are 1 character 1-to-1 matched.
	in DBCA, ABCD we notice the substring BC having a 1-to-1 matching, so they are 2 consecutive characters matching.
"""
from itertools import permutations
alpha = 'abc'
result = [0]*len(alpha)

perms = [''.join(p) for p in permutations(alpha)]
print perms
substrings = [(alpha[i:j+1], i, j+1) for i in xrange(len(alpha)) for j in xrange(i, len(alpha))]
print substrings
count = [(len(sub[0]), perm, perm[sub[1]:sub[2]] == sub[0]) for sub in substrings for perm in perms]
print count
count = [max(x+[0]) for x in [[c[0] for c in count if c[1] == perm and c[2]] for perm in perms]] 
print count
result = [sum([1 for i in xrange(len(count)) if count[i] == x]) for x in xrange(1, len(alpha)+1)]
print result

print [(i+1,j) for i,j in enumerate(result)]


#------------


# for sub in substrings:
# 	total = 0
# 	for perm in perms:
# 		total += perm[sub[1]:sub[2]] == sub[0]
			
# 		# print sub, total
# 	count.append(total)
# print count
# for i in xrange(len(substrings)):
# 	result[len(substrings[i][0])-1] += count[i]
# for perm in perms:
# 	length = len(perm)
# 	substings.append([perm[i:j+1], i, j+1] for perm in perms for i xrange(len(perms)) for j in xrange(i, len(perms)))
# print perms
# print substrings
# print s
# print total
# print len(substrings)

# result = [sum([count[i][1] for i in xrange(len(count)) if len(count[i][0]) == x]) for x in xrange(1, len(alpha)+1)]
# for i in xrange(len(result)-1, 0, -1):
# 	diff = [0]*len(result)
# 	for j in xrange(i-1, -1, -1):
# 		diff[j] = (i-j+1)*result[i]	
# 	result = [i-j for i,j in zip(result, diff)]