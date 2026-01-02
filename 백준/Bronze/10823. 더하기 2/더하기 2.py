res = ""

while True:
    try:
        A = input()
        res += A
    except:
        break

values = [int(x) for x in res.split(',')]
print(sum(values))