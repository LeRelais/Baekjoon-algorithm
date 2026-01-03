s = input()

# 1. "XXXX"를 "AAAA"로 먼저 바꾼다.
s = s.replace("XXXX", "AAAA")
# 2. 남은 "XX"를 "BB"로 바꾼다.
s = s.replace("XX", "BB")

# 3. 만약 여전히 'X'가 남아있다면 채우지 못한 것이므로 -1
if 'X' in s:
    print("-1")
else:
    print(s)