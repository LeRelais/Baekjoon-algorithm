from collections import deque

dicts = {'A':3, 'B':2, 'C':1, 'D':2, 'E':3, 'F':3, 'G':3, 'H':3, 'I':1, 'J':1, 'K':3, 'L':1, 'M':3, 'N':3, 'O':1, 'P':2, 'Q':2, 'R':2, 'S':1, 'T':2, 'U':1, 'V':1, 'W':2, 'X':2, 'Y':2, 'Z':1}

s = input()

n = len(s)

q = deque()

for i in range(n):
    q.append(dicts[s[i]])

while True:
    if int(len(q)) <= 3:
        break
    
    a1 = q.popleft()
    b1 = q.popleft()
    
    a2 = q.popleft()
    b2 = q.popleft()
    
    
    q.appendleft((a2 + b2) % 10)
    q.appendleft((a1 + b1) % 10)

if len(q) >= 2:
    res = (q.popleft() + q.popleft()) % 10
else:
    res = q.popleft()

if q:
    res = (res + q.popleft()) % 10

if res % 2 == 1:
    print("I'm a winner!")
else:
    print("You're the winner?")
    