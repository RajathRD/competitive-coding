print "Printing chess board with M x N squares of size P x Q (ROW x COLUMN)"

m, n = [int(x) for x in raw_input("Enter M and N:").split()]
p, q = [int(x) for x in raw_input("Enter P and Q:").split()]

# m, n = 10, 10
# p, q = 10, 10

row_cells = p * m
column_cells = q * n

chars = ["X","-"]
for i in xrange(row_cells):
	val = i/p
	for j in xrange(column_cells):
		print chars[((j/q)+(i/p))%2],
	print 



