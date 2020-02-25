import sys

lines = sys.stdin.readlines()

n,m,k = [int(i) for i in lines[0].split()]

x = n
y = (n * (n - 1) / 2) - m
z = n - k

data = [] * n
for i in range(n):
    data.append([1] * n)

for l in lines[1:]:
    a,b = [int(i) for i in l.split()]
    data[a][b] = 0

print('%i %i %i' % (x,y,z))
for i in range(n):
    for j in range(i+1,n):
        if data[i][j] == 1: print(i,j)
