n = int(input())
if n == 0:
    print(0)
elif n == 1:
    print(1)
else:
    previous_1 = 1
    previous_2 = 1
    res = 1
    for i in range(3, n + 1):
        res = previous_1 + previous_2
        previous_1 = previous_2
        previous_2 = res
    print(res)