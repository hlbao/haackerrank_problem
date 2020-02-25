# INFO
#
# initialize a queue with path index 0, 1, 02
# test path length with new vertex 3 on path 0 and path 1
# check which is bigger and add it to the possible paths (i.e 03 or 13)
# remove path at beginning of queue (i.e 0)
# update biggest path if new path is bigger than current biggest


import sys

lines = sys.stdin.readlines()
k = int(lines[0])
hives = lines[1].split()

i = 3
paths = [[tuple(['0']), int(hives[0])], [tuple(['1']), int(hives[1])],[tuple(['02']),int(hives[0]) + int(hives[2])]]
if int(hives[0]) > int(hives[1]): best = ('0', int(hives[0]))
else: best = ('1',int(hives[1]))
    
while i < k:
    val1 = paths[0][1] + int(hives[i])
    val2 = paths[1][1] + int(hives[i])
    if val1 >= val2:
        bestpath = paths[0][0] + tuple([str(i)])
        val = val1
    else:
        bestpath = paths[1][0] + tuple([str(i)])
        val = val2
    paths.pop(0)
    paths.append((bestpath,val))
    
    if best[1] < val:
        best = ((bestpath,val))
    
    i += 1
    
print(best[1])
