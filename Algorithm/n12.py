def Fib(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        previous_1 = 1
        previous_2 = 1
        res = 1
        for i in range(3, n + 1):
            res = previous_1 + previous_2
            previous_1 = previous_2
            previous_2 = res
        return res

n1, n2 = tuple(map(int, input().split()))
f = (Fib((n2 + 2) % 60) - 1) % 10
s = (Fib((n1 + 1) % 60) - 1) % 10
if f > s:
    print(f - s)
elif f == s:
    print(0)
else:
    print((f + 10) - s)