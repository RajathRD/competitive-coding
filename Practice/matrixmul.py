a = [[1,1,1],[1,1,1]]
b = [[1],[1],[1]]
c = []
l = []

for i in range(2):
  l.clear()
  for j in range(1):
    temp = 0
    for k in range(3):
      temp = temp + a[i][k] * b[k][j]
    l.append(temp)
  c.append(l)
print(c)
