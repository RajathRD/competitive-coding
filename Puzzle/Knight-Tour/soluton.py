
def move_path(x, y, mx, my, table):
	if x+mx < 0 or y+my < 0 or x+mx > 7 or y+my > 7:
		return False, x, y, table
	
	to_x = x+mx
	print x, to_x
	for i in xrange(min(to_x,x),max(to_x,x)):
		print i,
		if i != x:
			if table == True:
				return False, x, y, table
			table[i][y] = True
		
	x = to_x
	for i in table:
		print i
	to_y = y+my
	print y, to_y
	for i in xrange(min(to_y,y), max(to_y,y)):
		print i
		if i != y:
			if table == True:
				return False, x, y, table

			table[x][i] = True
	y = to_y
	for i in table:
		print i

	return True, x, y, table
table = [[0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0, 0, 0]]

table[8][0] = 1
for line in table:
	print line
