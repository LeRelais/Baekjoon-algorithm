dicts = [0] * 53

n = int(input())

nums = [int(x) for x in input().split(' ')]

for i in range(len(nums)):
    dicts[nums[i]] += 1

s = input()

for i in range(len(s)):
    if s[i] == ' ':
        dicts[0] -= 1
    elif 'a' <= s[i] <= 'z':
        dicts[ord(s[i]) - ord('a') + 27] -= 1
    elif 'A' <= s[i] <= 'Z':
        dicts[ord(s[i]) - ord('A') + 1] -= 1

flag = 1

for i in range(53):
    if dicts[i] != 0:
        flag = 0
        break

if flag == 0:
    print('n')
else:
    print('y')