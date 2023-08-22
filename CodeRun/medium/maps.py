def check_f(x, y, z, b):
    if x**2 + y**2 + z**2 >= b:
        return True
    return False


def binsearch(i, a, b, c):
    r = a - i - 1
    l = r // 2 + 1
    while l < r:
        m = (l + r) // 2
        if check_f(i, m, a - (i + m), b):
            r = m
        else:
            l = m + 1
    if i**3 + l**3 + (a - i - l)**3 == c and i**2 + l**2 + (a - i - l)**2 == b:
        return l
    return -1


n = int(input())
a, b, c = tuple(map(int, input().split()))
s = (n * (n + 1)) // 2
s_2 = (n * (n + 1) * (2 * n + 1)) // 6
s_3 = (n**2 * (n + 1)**2) // 4
a = s - a
b = s_2 - b
c = s_3 - c
for i in range(1, n + 1):
    ans = binsearch(i, a, b, c)
    if ans != -1:
        print(i, ans, a - ans - i)
        break