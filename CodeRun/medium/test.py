import random

def check_f(x, y, z, b):
    if x**2 + y**2 + z**2 <= b:
        return True
    return False


def binsearch(n, i, a, b, c):
    l = 1
    r = n
    while l < r:
        m = (l + r) // 2
        if check_f(i, m, a - (i + m), b):
            r = m
        else:
            l = m + 1
    if i**3 + l**3 + (a - i - l)**3 == c and i**2 + l**2 + (a - i - l)**2 == b:
        return l
    return -1


while True:
    n = random.randint(3, 15)
    f = random.randint(1, n)
    s_4 = random.randint(1, n)
    while s_4 == f:
        s_4 = random.randint(1, n)
    t = random.randint(1, n)
    while t == f or t == s_4:
        t = random.randint(1, n)
    a = 0
    b = 0
    c = 0
    for i in range(1, n + 1):
        if i != f and i != s_4 and i != t:
            a += i
            b += i**2
            c += i**3
    a_tmp = a
    b_tmp = b
    c_tmp = c
    s = (n * (n + 1)) // 2
    s_2 = (n * (n + 1) * (2 * n + 1)) // 6
    s_3 = (n**2 * (n + 1)**2) // 4
    a = s - a
    b = s_2 - b
    c = s_3 - c
    for i in range(1, n + 1):
        ans = binsearch(n, i, a, b, c)
        if ans != -1:
            break
    else:
        print("Error")
        print(n)
        print(a_tmp, b_tmp, c_tmp)
        print(f, s_4, t)
        input()
    

