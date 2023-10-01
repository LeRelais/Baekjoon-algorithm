inputs = list(map(int, input().split()))

if not 12 <= inputs[0] <= 16 or inputs[1] == 1:
    print(280)
elif 12 <= inputs[0] <= 16 and not inputs[1] == 1:
    print(320)