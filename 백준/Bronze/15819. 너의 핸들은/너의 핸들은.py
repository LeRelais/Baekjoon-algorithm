n, m = map(int, input().split(' '))

dicts = []

for i in range(n):
    s = input()
    dicts.append(s)

dicts.sort()

print(dicts[m-1])