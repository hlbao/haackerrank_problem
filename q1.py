import sys

lines = sys.stdin.readlines()

k = int(lines[0])
requests = []
for l in lines[1:]:
    requests.append([])
    vals = l.split()
    n,r = int(vals[0]),int(vals[1])
    requests[-1].append(n)

    for i in range(r):
        r1 = int(vals[i*2 + 2])
        r2 = int(vals[i*2 + 3])
        req = (r1,r2)
        requests[-1].append(req)

def check_valid(r,A):
    #to_remove = []
    for i,req in enumerate(r):
        r1,r2 = req
        #if r1 or r2 in A: to_remove.append(i)
        if -1 * r1 in A and -1 * r2 in A: return False

    return True

def get_next(r,A):
    for i,req in enumerate(r):
        r1,r2 = req

        if r1 in A or r2 in A: return i
        if -1 * r1 in A or -1 * r2 in A: return i

    return 0

#TAKES 3 SETS
#r - set of requests
#A - set of requests satisfied
def foo(r,A):

    if len(r) == 0: return True

    idx = get_next(r,A)
    req = r.pop(idx)
    r1,r2 = req
    if r1 in A or r2 in A: return foo(r,A)
    elif -1 * r1 in A and -1 * r2 in A: return False
    elif not check_valid(r,A): return False
    elif -1 * r1 in A: A.add(r2); return foo(r,A)
    elif -1 * r2 in A: A.add(r1); return foo(r,A)
    else:
        A.add(r1)
        good1 = foo(r.copy(),A.copy())
        if good1: return True
        A.remove(r1)

        A.add(r2)
        good2 = foo(r,A)
        return good1 or good2

for i,r in enumerate(requests):
    n = r[0]
    req = r[1:]
    A = set()
    if (foo(req,A)): print(1)
    else: print(0)

