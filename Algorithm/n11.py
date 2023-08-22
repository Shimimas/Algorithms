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

n = int(input())
print((Fib((n + 2) % 60) - 1) % 10)