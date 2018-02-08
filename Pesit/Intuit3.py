 # Problem- given that chocolates are manufactured with their sweetness increasing every second.
 # the sweetness is, k =c* i * sqrt(i) * log(i)[to base 2, not 10] , for i seconds passed.
 # Given a maximum sweetness level that is accepted(namely S), and value of constant c 
 # find the max number of seconds for which manufacturing can occur.

import math
n = int(raw_input())

for i in range(n):
	c = int(raw_input())
	S =  int(raw_input())
	k =0
	i = 1
	while k<S:
		k = 1.0 * c * i * math.sqrt(i) * math.log(i) / (1.0 * math.log(2))
		i+=1
	print i-2