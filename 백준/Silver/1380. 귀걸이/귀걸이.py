res = []
while True:
    n = int(input())
    
    if n == 0:
        break
    
    arr = [0] * n
    names = []
    
    for i in range(n):
        name = input()
        names.append(name)
    
    for i in range(2*n - 1):
        a, b = input().split()
        arr[int(a)-1] += 1
    
    for i in range(n):
        if arr[i] != 2:
            res.append(names[i])
            break

for i in range(len(res)):
    print(i+1, end= " ")
    print(res[i])
    
    