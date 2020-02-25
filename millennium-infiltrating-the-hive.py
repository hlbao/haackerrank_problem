# INFO
#
# sum up the digits and then convert to octal. Repeat until there is only 1 digit.
#
#



import sys

digit_in = sys.stdin.readlines()[0].strip()

def get_octal(decimal):
    if int(decimal / 8.0) == 0:
        return str(decimal % 8)
    else:
        val = int(decimal / 8)
        div = str(decimal % 8)
        return  get_octal(val) + div

def get_bugcount(digit):
    if len(digit) == 1:
        return int(digit)
    else:
        total = sum([int(x) for x in digit])
        octal = get_octal(total)
        
        return get_bugcount(octal)
    
    
    
print(get_bugcount(digit_in))
