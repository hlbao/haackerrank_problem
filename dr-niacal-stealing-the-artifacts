# INFO
#
# Sort artifacts by biggest to smallest
# assign each worker an artifact until all workers have a job. Update the amount of risk each worker faced. Repeat until no more jobs and print the total amount of risk
# across all workers


import sys

lines = sys.stdin.readlines()

#n artifacts, k workers
n,k = [int(x) for x in lines[0].split()]
risk = [int(x) for x in lines[1].split()]
risk.sort()
risk.reverse()

i = 0
iteration = 1
bags = [0] * k
while True:
    cur_task = risk[i:i+k]
    
    #zip will naturally adjust to smallest length list
    for j,data in enumerate(zip(bags,cur_task)):
        b,task = data
        bags[j] =  b + task * iteration
            
    iteration += 1
    i = i+k
    
    #ONCE WE GO THROUGH N ARTIFACTS
    if i > n: break

print(sum(bags))
