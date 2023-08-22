a, b, c, d = tuple(map(int, input().split()))
l = -10000
r = 10000
while l + 0.000001 < r:
    m = (r + l) / 2
    if a * m**3 + b * m**2 + c * m + d > 0:
        if a > 0:
            r = m
        else:
            l = m
    else:
        if a > 0:
            l = m
        else:
            r = m
print(l)