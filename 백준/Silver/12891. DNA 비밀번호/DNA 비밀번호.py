import sys
from collections import Counter 

s, p = input().strip().split(' ')
s = int(s)
p = int(p)
s1 = input().strip()

a, c, g, t = input().split(' ')
rules = {'A': int(a), 'C': int(c), 'G': int(g), 'T': int(t)}

res = 0
current_count = {'A': 0, 'C': 0, 'G': 0, 'T': 0}
for i in range(p):
    current_count[s1[i]] += 1

def is_valid(curr, req):
    for char in 'ACGT':
        if curr[char] < req[char]:
            return False
    return True

if is_valid(current_count, rules):
        res += 1

for i in range(p, s):
    new_char = s1[i]
    current_count[new_char] += 1
    
    out_char = s1[i-p]
    current_count[out_char] -= 1
    
    if is_valid(current_count, rules):
        res += 1

print(res)