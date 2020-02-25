#
#
#
# Count the number of combinations that sum to produce the result k, order matters
# 
# 1. construct data to k+1 elements with data[0] = 1
# 2. go through each element in data and add each pass phrase
# 3. set data[i + passphrase] += data[i]
# 
# since data[0] = 1 this will count all ways to get to k. Make sure to take mode 1000000009 as the answer
#




import sys
lines = sys.stdin.readlines()

passphrase_count = int(lines[0])
for c in range(passphrase_count):
    #w is the word count, k is the passphrase length
    w,k = lines[2*c+1].split()
    w = int(w); k = int(k)
    phrases = [int(x) for x in lines[2*c+2].split()]
    phrases.sort()
    
    data = [0] * (k + 1)
    data[0] = 1
    
    for i in range(len(data)):
        for p in phrases:
            if i + p < len(data):
                data[i + p] += data[i]
            else:
                break
                
    print(data[-1] % 1000000009)
    
