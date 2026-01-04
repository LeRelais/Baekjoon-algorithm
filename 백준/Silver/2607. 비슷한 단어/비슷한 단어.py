from collections import Counter

n = int(input())
res = 0

target = input().strip()
target_len = len(target)
f_cnt = Counter(target)

for i in range(1, n):
    s = input().strip()
    s_len = len(s)
    
    if abs(target_len - s_len) > 1:
        continue
    
    s_cnt = Counter(s)
    
    common_cnt = sum((f_cnt & s_cnt).values())
    
    if target_len - common_cnt <= 1 and s_len - common_cnt <= 1:
        res += 1        

print(res)
    