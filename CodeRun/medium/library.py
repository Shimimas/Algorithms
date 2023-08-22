import random

def ON(k, m, d):
    need_to_read = 1
    result = 0
    while True:
        if d != 6 and d != 7:
            m += k
        d += 1
        if d == 8:
            d = 1
        m -= need_to_read
        need_to_read += 1
        if m < 0:
            break
        result += 1
    return result

def check_fun(mid, k, m, d):
    summ = ((1 + mid) / 2) * mid
    col = m + (mid // 7) * (k * 5)
    days = mid % 7
    for i in range(days):
        if d != 6 and d != 7:
            col += k
        d += 1
        if d == 8:
            d = 1
    if col >= summ:
        return True
    else:
        return False


def binsearch(k, m, d):
    if d == 6 and m == 0:
        return 0
    elif d == 6 and m == 1:
        return 1
    elif d == 6 and m == 2:
        return 1
    elif d == 7 and m == 0:
        return 0
    l = 0
    r = 2000000000
    while l < r:
        mid = (l + r + 1) // 2
        if check_fun(mid, k, m, d):
            l = mid
        else:
            r = mid - 1
    return l


k, m, d = map(int, input().split())
print(binsearch(k, m, d))
while True:
    k = random.randint(1, 1000)
    m = random.randint(0, 1000)
    d = random.randint(1, 7)
    f = ON(k, m, d)
    s = binsearch(k, m, d)
    if f != s:
        print(k, m, d)
        print(f)
        print(s)
        

    
    