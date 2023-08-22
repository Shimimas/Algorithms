def PisanoPeriod(m):
    current = 0
    next = 1
    period = 0
    while True:
        oldNext = next
        next = (current + next) % m
        current = oldNext
        period = period + 1
        if current == 0 and next == 1:
            return period

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

n, m = tuple(map(int, input().split()))
pis = PisanoPeriod(m)
print(Fib(n % pis) % m)