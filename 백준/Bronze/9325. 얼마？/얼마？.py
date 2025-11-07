t = int(input())

for x in range(0, t):
    s = int(input())
    n = int(input())
    
    for i in range(0, n):
        a, b = input().split()
        s += int(a) * int(b)
    print(s)